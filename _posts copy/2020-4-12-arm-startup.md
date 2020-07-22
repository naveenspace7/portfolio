---
layout: post
title: ARM Cortex-M Startup
excerpt_separator: <!--more-->
tags: C ARM microcontroller
---

<!--more-->

### ARM Cortex-M4 startup script

The startup code is divided into the following sections:

#### Declaration of stack area
`Stack_Size EQU 0x00000400`

The "EQU" is same as "#define" preprocessor directive in C.


There is separate region created with a name using the following command:

`AREA STACK, NOINIT, READWRITE, ALIGN=3`

This directive denotes a separate section in the memory. In this case, "STACK" is just the name of the section. Following the name are the following attributes:

* "NOINIT": indicates that the data in this section is initialized to zero.
* "READWRITE": allows this section to be both read and write.
* "ALIGN=3": makes the start of the section on an 8-byte boundary (2^3 = 8)

`Stack_Mem SPACE Stack_Size`

The above line allocates space of 0x400 bytes in the stack area (SPACE is used to reserve a space for a specified number bytes).


#### Vector Table

`AREA RESET, DATA, READONLY`

Here we create another section and call it "RESET", which contains only "DATA", and not instructions. Vector tables contains only the addresses of handlers and initial stack pointer value.

"READONLY" indicates that the area is only accessable for reading.