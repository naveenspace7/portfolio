---
layout: post
title: Allocators
excerpt_separator: <!--more-->
tags: C++ Allocators
---

Allocators provides a handle to override the memory management done by the operating systems. In this blog, I will incrementally write about the details of allocators.

<!--more-->

## Allocators

In one of the talk at CppCon, a speaker mentioned allocators are a handle to heap.

Most of the STL containers store their data on the heap instead of the stack. As an example, I will explain how vector works superficially, only highlighting the aspects needed for talking about the allocators. From what is shown in the below figure, it can be seen that the data a vector represents is stored in the heap section of the program memory.


![Working of vector]({{site.url}}/assets/images/vector-working.png)


This can be achieved by the simple default usage, as described below. This calls in for a dynamic (heap) allocation by calling the new/malloc function.

``` cpp
vector<int> v (50, 0);
```
However, STL containers also give an option for creating the allocation in the memory that the client wants to allocate in. If this path is taken, the responsibility of managing the memory is on the client. A small sample program to demonstrate how this is done is shown [here](https://gist.github.com/naveenspace7/8030d88916e278972672c4723713935c).






<!-- How does malloc work?

Malloc is a glibc function which does all the memory handling. When there is heap memory allocated in the physical memory, the library calls a sbrk system call which in return fetch the requested amount of memory for the heap allocation by creating a mapping entry in the virtual memory. -->


<!-- To know why allocators are important, we need to understand how dynamic memory allocation works. -->

### Creating Shared Memory Interface

The concept of allocators is a powerful tool that helps precisely controlling the memory management. This section explains one use-case of custom allocators in which multiple processes share the same memory to store their containers' data. This can reduce the overhead involved transferring the data between multiple consumers and producers.

``` cpp
#include <sys/ipc.h>
#include <sys/shm.h>

void * setup_shm()
{
    int shmid = shmget(777, 100, 0644 | IPC_CREAT); // request 100 bytes

    void * shared_mem = shmat(shmid, (void*)(0), 0);

    if (shared_mem == (char *) (-1)) perror("error creating shared mem\n");

    return shared_mem;
}
```

### Allocators to shared memory

To use the shared memory for multiple containers (vectors), present in multiple containers, the allocator needs to passed with the shared memory address obtained in the previous sections.

![Allocators to shared memory]({{site.url}}/assets/images/shared_allocator.png)

A simple working code for using shared memory as a custom allocator with a vector is given [here](https://gist.github.com/naveenspace7/ffed1c3ea33690b686699add198b9ba5).

Now with the sharing in place, there needs to be additional care taken for synchronization of the data shared by multiple processes.