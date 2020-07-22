---
layout: post
title: One use case of double pointers
excerpt_separator: <!--more-->
tags: C C++ pointers
---

The whole concept of pass-by-value in C seemed so simple in the beginning and could also be one of the reason why many beginners might take it for granted and I was one of them when I got started with the language four years ago. I am writing this post after spending hours debugging some code that I wrote for one of my assignment, without realizing that I was making a fundamental mistake.

 <!--more-->

My mistake in brief, I tried to pass a null_ptr to a function, which was supposed to make and image on the heap and modify the pointer which was null_ptr previously. After hours of debugging, I realized the mistake I made. This post will try to brief this out. After searching on the internet, I found this has been a misconception among beginners.

It should be first made clear of what kind of way are present for passing arguments to functions.

* **Pass-by-value**: the value of the variable at the callee is copied to the caller arguments. When any change are made in the function scope, they don't reflect outside the function scope. The illustration can be seen in the image.

![Pass-by-value]({{ site.baseurl }}/images/double_ptr_prog.png "Working of pass-by-value")

* **Pass-by-address**: as an argument to the caller function, the address of the variable is passed, unlike previous case. When the address is deferenced and any changes are made to the variable, they reflect outside the function scope.

Double-pointers came to the rescue to provide the functionality what I desired. The code with double-pointer is shown below (taken from [Answer by Asha on SO](https://stackoverflow.com/questions/5580761/why-use-double-indirection-or-why-use-pointers-to-pointers)):

```c
void modify(int ** n) {
    *n = malloc(sizeof(int)); // *n points to an address in heap
    **n = 5;
}

int main() {
    int * n = NULL; // n is NULL.
    modify(&n);
    // *n is 5 now
}
```
