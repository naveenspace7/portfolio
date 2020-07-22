---
layout: post
title: Shared Libraries in Linux
excerpt_separator: <!--more-->
tags: libraries C++ C linux
---

In this short post, I briefly describe how to create and use static and dynamic shared libraries. It should be noted that this post is created purely for my quick reference. The original references would be cited.

<!--more-->

### Sample Reference Code

To deliver the actual knowledge, these simple examples are used.

```cpp
//add.cpp
int add(int x, int y)
{
    return x + y;
}
```

```cpp
//sub.cpp
int sub(int x, int y)
{
    return x - y;
}
```

```cpp
//mul.c
int mul(int x, int y)
{
    return x - y;
}
```

```cpp
//main.cpp
/* function prototypes (forward declarations)
   adding these in a header file is a better practice */
int add(int, int);
int sub(int, int);

// since mul is compile with C compiler
extern "C" {
    int mul(int,int); // or include the header file here
}

int main()
{
    int a = 5, b = 3;
    cout << add(a,b) << " " << sub(a,b) << endl;
    return 0;
}
```

### Why use libraries?

Libraries allow multiple translational units (TU) to be bundled into a single pack. Generally, without using libraries, one can compile each of the TU and compile with the main program. But this would need referencing all the individual object files explicitly.

There are two kinds of shared libraries.

* Static Library
* Dynamic Library

#### Static Library

In static libraries, the binary content of the object files contained in the static library is copied over to the final executable at the linking stage.

The process and commands for creating the shared static libraries are detailed.

##### Compile TUs

Firstly, compile the individual TUs to obtain the object files.
~~~
$ g++ -c add.cpp -o add.o
$ g++ -c sub.cpp -o sub.o
$ gcc -c mul.cpp -o mul.o
~~~

##### Creating Static Library

The below command takes all the required object files generated and packs them into an archive.
~~~
$ ar -cvq liboperations.a *.o
~~~

##### Using Static Library

The created static library can be used with the following command:

~~~
$ g++ main.cpp -L. -loperations -o out
~~~

**Note**: `-L` indicates the path where the shared lib can be found and it cannot be avoided.

#### Dynamic Library

In dynamic libraries, the binary content of the object files are copied into the memory during runtime of the executable.

##### Compile TUs

Firstly, compile the individual TUs to obtain the object files.
~~~
$ g++ -fPIC -c add.cpp -o add.o
$ g++ -fPIC -c sub.cpp -o sub.o
$ gcc -fPIC -c mul.cpp -o mul.o
~~~

##### Creating Dynamic Library

The below command creates the shared dynamic library.
~~~
$ g++ -shared -o liboperations.s *.o
~~~

##### Using Dynamic Library

Although the dynamic library has been created, it has to be put in a separate path to enable successful linking.

~~~
$ LD_LIBRARY_PATH=$LD_LIBRARY_PATH:<new_path>
$ export LD_LIBRARY_PATH
$ g++ main.cpp -L
~~~

**Alternatively**, the generated shared object file can be copied to `/usr/local/lib/<your_path/.`. Once they are copied, it should be add to the path by adding/modifying the file at `/etc/ld.so.conf.d/`.

Once they are added, the loader paths can be updated with the following command:
~~~
$ ldconfig -p | grep <lib-name> # to verify if the library is updated

$ ldconfig # updates the config
~~~

To check the dependencies of the final executable, the following command needs to be used:

~~~
$ ldd ./exec
~~~

The latter method doesn't need the specification of the library path (`-L`) in the command. Moreover, it doesn't even need the inclusion of header files or forward declaration of the functions/classes used.
