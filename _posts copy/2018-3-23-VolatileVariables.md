---
layout: post
title: Volatile Variables
excerpt_separator: <!--more-->
tags: C C++ volatile microcontroller
---

This short article describes how volatile variable can benefit the development on both desktop and embedded applications.

<!--more-->

## Why am I writing this article?
I started doing some microcontroller programming on ARM Cortex-M4. I started to dig into the code given in the libraries and I was really surprised how often volatile variables were used. Later, reading some articles on the Internet, I understood how much I have underestimated this whole concept. I decided to accumulate the information found on the Internet and stuff it into one article.

## What is the use of volatile variables?
_volatile_ is a qualifier that is applied to a variable when it is declared. It tells the compiler that the value of the variable may change at any time-without any action being taken by the code the compiler finds nearby. The implications of this are quite serious. However, before we examine them, let's take a look at the syntax.

_volatile_ in C actually came into existence for the purpose of not caching the values of the variable automatically. It will tell the machine not to cache the value of this variable. So it will take the value of the given volatile variable from the main memory every time it encounters it. This mechanism is used because at any time the value can be modified by the OS or any interrupt. So using volatile will help us accessing the value afresh every time.

## When use volatile variables?
Have you experienced any of the following in your C/C++ embedded code?

* Code that works fine-until you turn optimization on.
* Code that works fine-as long as interrupts are disabled.
* Flaky hardware drivers.
* Tasks that work fine in isolation-yet crash when another task is enabled.

A variable should be declared volatile whenever its value could change unexpectedly. In practice, only three types of variables could change:

* Memory-mapped peripheral registers.
* Global variables modified by an interrupt service routine.
* Global variables within a multi-threaded application.

### Peripheral Registers:

Embedded systems contain real hardware, usually with sophisticated peripherals. These peripherals contain registers whose values may change asynchronously to the program flow. 

To demonstrate this use case, consider an 8-bit status register at address 0x1234. It is required that you poll the status register until it becomes non-zero. The naive and incorrect implementation is as follows:

```c
UINT16 * ptr = (UINT16 *) 0x1234;

// Wait for register to become non-zero.
while (*ptr == 0);
// Do something else for later action.
```

This will almost certainly fail as soon as you turn the optimizer on, since the compiler will generate assembly language that looks something like this:
```c
mov    ptr, #0x1234
mov    a, @ptr 
loop   bz    loop
```

The rationale of the optimizer is quite simple: having already read the variable's value into the accumulator (on the second line), there is no need to reread it, since the value will always be the same. Thus, in the third line, we end up with an infinite loop. 

To force the compiler to do what we want, we modify the declaration to:
```c
UINT16 volatile * ptr = (UINT16 volatile *) 0x1234;
```

The assembly language now looks like this:

```c
mov     ptr, #0x1234
loop    mov    a, @ptr        
bz    loop
```

Hence, the desired behavior is achieved.

Subtler problems tend to arise with registers that have special properties. For instance, a lot of peripherals contain registers that are cleared simply by reading them. Extra (or fewer) reads than you are intending can cause quite unexpected results in these cases.


### ISR

Interrupt service routines often set variables that are tested in main line code. For example, a serial port interrupt may test each received character to see if it is an ETX character (presumably signifying the end of a message). If the character is an ETX, the ISR might set a global flag. An incorrect implementation of this might be:

```c
int etx_rcvd = FALSE;

void main() {
    ...
    while (!ext_rcvd) {
        // Wait
    }
    ...
}

interrupt void rx_isr(void) {
    ...
    if (ETX == rx_char)
        etx_rcvd = TRUE;
    ...
}
```

With optimization *turned off*, this code might work. However, any half decent optimizer will "break" the code. The problem is that the compiler has no idea that etx_rcvd can be changed within an ISR. As far as the compiler is concerned, the expression !ext_rcvd is always true, and, therefore, you can never exit the while loop. Consequently, all the code after the while loop may simply be removed by the optimizer.

The solution is to __declare the variable etx_rcvd to be volatile__.


### Multi-threaded applications

Despite the presence of queues, pipes, and other scheduler-aware communications mechanisms in real-time operating systems, it is still fairly common for two tasks to exchange information via a shared memory location (that is, a global). When you add a pre-emptive scheduler to your code, your compiler still has no idea what a context switch is or when one might occur. Thus, another task modifying a shared global is conceptually identical to the problem of interrupt service routines discussed previously. So all shared global variables should be declared volatile. For example:

```c
int cntr;

void task1(void)
{
    cntr = 0;
    while (cntr == 0)
    {
        sleep(1);
    }
    ...
}

void task2(void)
{
    ...
    cntr++;
    sleep(10);
    ...
}
```

This code will likely fail once the compiler's optimizer is enabled. Declaring cntr to be volatile is the proper way to solve the problem.


## A word on GCC Optimizer:
To be done.

## Conclusion

Some compilers allow you to implicitly declare all variables as volatile. Resist this temptation, since it is essentially a substitute for thought. It also leads to potentially less efficient code.

Source: 
[www.embedded.com](https://www.embedded.com/electronics-blogs/beginner-s-corner/4023801/Introduction-to-the-Volatile-Keyword)

[www.stackoverflow.com](https://stackoverflow.com/questions/246127/why-is-volatile-needed-in-c)
