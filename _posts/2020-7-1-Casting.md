---
layout: post
title: All about Casting
excerpt_separator: <!--more-->
tags: C++ Casting
---

<!--more-->

### Static Cast

Static cast is used to convert from one type to another, primarily a pointer from a base class to a derived class and from a derived class to a base class. This cast is done at compile time, meaning there is no run time check done to ensure the cast results in a full type of the target type so the user has to ensure the type cast is safe.

Consider using it when:
- Trying to implicitly convert between two different types. In the below example the latter can improve finding the conversion.
For example:

``` cpp
float f = 7.7; int a;

a = f; // avoid this
a = static_cast<int>(f); // use this.
```

- When using conversion ctor or conversion operator.
``` cpp
class Type {
    int x;
public:
    Type (int i): x{i} {}
    operator string() {
        return to_string(x);
    }
};

...
Type t1(5);

string str = t1;   // avoid this, use (i)
obj = 7;           // avoid this, use (ii)

string str = static_cast<string>(t1); // (i)
t1 = static_cast<Type>(7);            // (ii) 
```

- Casting the types where pointers are involved. In the example below, the casting is done at compile time and this avoids unrelated pointer conversion.

``` cpp
char s = 'r';
int * s_ptr = (int*)&s; // avoid this
int * s_ptr = static_cast<int*>(&s); // use this
```

- When casting from derived class to base class. But do not use for converting from base class to derived because there is no compile time checking done.

``` cpp
class Base {};
class Derived1: public Base {};
class Derived2: public Base {};
...
Base * bd1 = static_cast<Base*>(new Derived); // this is correct
Derived * d1 = static_cast<Base*>(bd1); // this is wrong
```

- Type casting to or from void pointer `void*`.

``` cpp
int p1 = 59;
void * p1_ptr = static_int<void*>(&p1);
int * n_ptr = static_int<int*>(p1_ptr);
```

### Const Cast

Const Cast is used to add or remove the const modifier to a variable allowing the developer to make a non-modifiable variable modifiable or vice versa. It can also be used to add the volatile modifier.

Use it for achieving the following:

- Getting non-const pointer for a const pointer, where the object being pointed is a non-const.

``` cpp
int p1 = 59;
const int * p1_ptr = &p1;
int * p2_ptr = const_cast<int*>(p1_ptr);
```

Use this type of cast with caution. Removing the const-ness of a pointer will cause undefine behaviour. This may be required for passing to a 3rd-party library (but doing this is a poor-design by the library).
 
<!-- https://www.geeksforgeeks.org/const_cast-in-c-type-casting-operators/ -->

### Dynamic Cast

Dynamic cast does a run time type check when performing the cast unlike the const cast. This means it is safer to use when it is less known about the types involved.

# Reinterpret cast

Reinterpret cast will convert pointers between types and integers. Since reinterpret cast doens't check the pointer type or the type pointed to it is possible to cast between unrelated and incompatible types and thus any derefernce of the cast is likely to fail, thus reinterpret cast is not safe.


<!-- https://www.geeksforgeeks.org/static_cast-in-c-type-casting-operators/ -->