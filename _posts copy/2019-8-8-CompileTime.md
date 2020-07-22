---
layout: post
title: Compile time checking in C
excerpt_separator: <!--more-->
tags: C
---

There might be place where there has to be a check that has to be done at the compile time. In C, one can use `_Static_assert(<bool-expr>, <str-literal>)`. When the `bool-expr` is `0`, it throws a compile time error with the message specified in `str-literal`.

<!--more-->

One use case which comes to my mind is to check during compile time if a macro has been defined.
```c
#define HEAD 0

#ifndef HEAD
_Static_assert(0, "Head not defined");
#endif
```

### Reference
https://stackoverflow.com/questions/3385515/static-assert-in-c