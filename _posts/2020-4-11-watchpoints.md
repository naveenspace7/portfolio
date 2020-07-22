---
layout: post
title: Watchpoints in GDB
excerpt_separator: <!--more-->
tags: gdb C++ C linux
---

Used to stop execution whenever the value of an expression changes, without having to predict a particular place where this might happen. The expression may be as simple as the value of a single variable or complex as a combination.

<!--more-->

* A reference to the value of a single variable.
* An address which is typecasted into a type *(int*)0x123456.
* A complex expression, like `a+b*5`.

Watchpoint works by watching the expression every time an instruction is stepped through, which is called as a software watchpoint. This can be a lot slower. However, some x86 and PPC support hardware watchpoints, which do not slow down the machine.

`watch expr [thread thread-id]`
* `> watch var`, watch a single exp. (var) for change in it's value, when detected, it breaks there.

* `> rwatch var`, watch a single exp. (var) for being read from "var", when detected, it breaks there.

* `> awatch var` is a combination for both read and write.

* thread thread-id can be mentioned when it should be stopped only in that particular thread. This only works on a hardware breakpoint.

* `> watch *(type*)0x1234`, the above formats apply for the content at the address.

* `> info watchpoints` prints all the watchpoints set.

GDB always prefers to use hardware watchpoints before falling back to software watchpoints. It can be however forced to use software breakpoints using `set can-use-hw-watchpoints 0`. The vice-versa can also done with the command by replacing 0 with 1. To see the status of the watchpoint, use `show can-use-hw-watchpoints`.

GDB Breakpoints:


GDB Commands:

* `> info program`: displays information about the status of your program whether it is running or not and why it is stopped.

