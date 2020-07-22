---
layout: post
title: Data Structures in C++
excerpt_separator: <!--more-->
tags: C++ Datastructures
---

C++ offers a wide range of data structures. From a performance perspective, the right data structure has to be chosen. This post briefly outline the main feature of every data structure available in C++.

<!--more-->

[1. vector](#vector)

[2. set](#set)

[3. multiset](#multiset)

[4. unordered_set](#unorderedset)

[5. unordered_multiset](#unorderedmultiset)

[6. map](#map)

[7. multimap](#multimap)

[8. unordered_map](#unorderedmap)

[9. unordered_multimap](#unorderedmultimap)

[priority_queue](#priorityqueue)


<!-- ### Types of initialization <a name="initializations"></a> -->
___

### 1. std::vector <a name="vector"></a>

___

### 2. std::set <a name="set"></a>

<!-- Header file -->
Present in header file `set`.

<!-- General purpose and properties -->
Set container stores **unique elements** whose values once entered **cannot be modified later**, they can only be inserted and removed. The elements in a set are accessed by their **key instead of position**. The elements are sorted according to a particular order as they are inserted.

<!-- Implementation -->
Set is most commonly implemented as a **binary search tree** (red-black trees). Therefore, it also has the provision to make use of a custom comparison function as a template parameter (requiring signature `bool comp(T lhs, T rhs)`). It can also take an allocator object when default memory allocation needs to be modified.

<!-- Figure of binary search tree -->
![Binary Search Tree]({{site.url}}/assets/images/binary-tree.png)

<!-- Access times -->
Since they are implemented in a binary search trees, the time to **insert, erase and find** an element is `O(log n)` (the size of the tree). It is worth mentioning that set can make use of hints to decrease the operation times.

<!-- Operations possible -->
Set allows the following operations:
* Iterators: begin, end, rbegin, rend, cbegin, cend, crbegin, crend
* Capacity: empty, size
* Modification: insert, erase, clear, emplace, emplace_hint
* Operations: find, lower_bound, upper_bound

___

### 3. std::multiset <a name="multiset"></a>

<!-- Header file -->
Present in header file `set`.

<!-- General purpose and properties -->
Multiset container stores **multiple equal elements** whose values once entered **cannot be modified later**, they can only be inserted and removed. The elements in a set are accessed by their **key instead of position**. The elements are sorted according to a particular order as they are inserted.

<!-- Implementation -->
Set is most commonly implemented as a **binary search tree** (red-black trees). Therefore, it also has the provision to make use of a custom comparison function as a template parameter (requiring signature `bool comp(T lhs, T rhs)`). It can also take an allocator object when default memory allocation needs to be modified.

<!-- Figure of binary search tree -->

<!-- Access times -->
Since they are implemented in a binary search trees, the time to **insert, erase and find** an element is `O(log n)` (the size of the tree). It is worth mentioning that set can make use of hints to decrease the operation times. Count takes `O(log n)` to find the matching element and linear time to count the number of elements.

<!-- Operations possible -->
Set allows the following operations:
* Iterators: begin, end, rbegin, rend, cbegin, cend, crbegin, crend
* Capacity: empty, size
* Modification: insert, erase, clear, emplace, emplace_hint
* Operations: find, count, lower_bound, upper_bound

___

### 4. std::unordered_set <a name="unorderedset"></a>

Present in the header file `unordered_set`.

<!-- General purpose and properties -->
Unordered set container stores **unique elements** whose values once entered **cannot be modified later** (immutable), they can only be inserted and removed. The elements in a set are accessed by their **key instead of position**. The elements are placed in no particular order, which makes it easier for faster retrieval.

<!-- Implementation -->
Unordered set is implemented as a **chained hash table**, which arranges the elements into buckets based on the hash of the element. Therefore, it also has the provision to make use of a custom hash function as a template parameter. It can also take an allocator object when default memory allocation needs to be modified.

<!-- Figure of binary search tree -->

<!-- Access times -->
Since they are implemented as a chained hash table, the time to **insert, erase and find** an element is `O(1)`. It is worth mentioning that set can make use of hints to decrease the operation times.

<!-- How to use it -->

<!-- Operations possible -->
Set allows the following operations:
* Iterators: begin, end, cbegin, cend
* Capacity: empty, size
* Modification: insert, erase, clear, emplace, emplace_hint
* Operations: find, count, equal_range
* Observers: hash_function, key_eq, get_allocator
* Hash Policy: load_factor, max_load_factor, rehash, reserve
* Buckets: bucket_count, max_bucket_count, bucket_size, bucket

A small demo program to show how to implement an unordered_set for custom classes is shown <a href="https://gist.github.com/naveenspace7/d44e137e788b6fc7a686125091b4ff9a">here</a>

___


### 5. std::unordered_multiset <a name="unorderedmultiset"></a>

Present in the header file `unordered_set`.

The only difference between this container and unorder set is that this container can hold multiple keys.

<!-- General purpose and properties -->
Unordered set container stores **multiple equal elements** whose values once entered **cannot be modified later** (immutable), they can only be inserted and removed. The elements in a set are accessed by their **key instead of position**. The elements are placed in no particular order, which makes it easier for faster retrieval.

<!-- Implementation -->
Unordered multiset is also implemented as a **chained hash table**, which arranges the elements into buckets based on the hash of the element. Therefore, it also has the provision to make use of a custom hash function as a template parameter. It can also take an allocator object when default memory allocation needs to be modified.

<!-- Figure of binary search tree -->

<!-- Access times -->
Since they are implemented as a chained hash table, the time to **insert, erase and find** an element is `O(1)`. It is worth mentioning that set can make use of hints to decrease the operation times.

<!-- How to use it -->

<!-- Operations possible -->
Set allows the following operations:
* Iterators: begin, end, cbegin, cend
* Capacity: empty, size
* Modification: insert, erase, clear, emplace, emplace_hint
* Operations: find, count, equal_range
* Observers: hash_function, key_eq, get_allocator
* Hash Policy: load_factor, max_load_factor, rehash, reserve
* Buckets: bucket_count, max_bucket_count, bucket_size, bucket

___

### 6. std::map <a name="map"></a>

<!-- Header file -->
Present in header file `map`.

<!-- General purpose and properties -->
Map container stores **unique key elements**. The elements in a set are accessed by their **key instead of position** and the value held by the key can be extracted (keys and mapped to values). The elements are sorted according to a particular order as they are inserted.

<!-- Implementation -->
Maps is most commonly implemented as a **binary search tree** (red-black trees). Therefore, it also has the provision to make use of a custom comparison function as a template parameter (requiring signature `bool comp(T lhs, T rhs)`). It can also take an allocator object when default memory allocation needs to be modified. An entry in the map can be accessed with `pair<const T1 K, T2 V> entry`.

<!-- Figure of binary search tree -->

<!-- Access times -->
Since they are implemented in a binary search trees, the time to **insert, erase and find** an element is `O(log n)` (the size of the tree). It is worth mentioning that set can make use of hints to decrease the operation times.

<!-- Operations possible -->
Set allows the following operations:
* Iterators: begin, end, rbegin, rend, cbegin, cend, crbegin, crend
* Capacity: empty, size, max_size
* Element Access: operator[], at
* Modification: insert, erase, clear, emplace, emplace_hint
* Observers: key_comp, value_comp
* Operations: find, lower_bound, upper_bound, equal_range
* Allocator: get_allocator

___

### 7. std::multimap <a name="multimap"></a>

<!-- Header file -->
Present in header file `map`.

<!-- General purpose and properties -->
Multi map container stores **multiple equal elements**. The elements in a multi map are accessed by their **key instead of position**. The elements are sorted according to a particular order as they are inserted.

<!-- Implementation -->
Set is most commonly implemented as a **binary search tree** (red-black trees). Therefore, it also has the provision to make use of a custom comparison function as a template parameter (requiring signature `bool comp(T lhs, T rhs)`). It can also take an allocator object when default memory allocation needs to be modified. An entry in the map can be accessed with `pair<const T1 K, T2 V> entry`.

<!-- Figure of binary search tree -->

<!-- Access times -->
Since they are implemented in a binary search trees, the time to **insert, erase and find** an element is `O(log n)` (the size of the tree). It is worth mentioning that set can make use of hints to decrease the operation times. Count takes `O(log n)` to find the matching element and linear time to count the number of elements.

<!-- Operations possible -->
Set allows the following operations:
Set allows the following operations:
* Iterators: begin, end, rbegin, rend, cbegin, cend, crbegin, crend
* Capacity: empty, size, max_size
* Modification: insert, erase, clear, emplace, emplace_hint
* Observers: key_comp, value_comp
* Operations: find, count, lower_bound, upper_bound, equal_range
* Allocator: get_allocator

___

### 8. std::unordered_map <a name="unorderedmap"></a>

___

### 9. std::unordered_multimap <a name="unorderedmultimap"></a>

___

### 10. std::deque  <a name="deque"></a>

<!-- Header file -->
Present in header file `deque`.

<!-- General purpose and properties -->
Deque expands to double ended queue. This container should be preferred when elements are inserted or removed from either the front or back of the container frequently, while also allowing random access to the elements (by index).

<!-- Implementation -->
Deque is commonly implemented as dynamic arrays in which multiple arrays are attached with linked with each other. Generally these multiple arrays are managed from a lookup table. The working of this data structure is shown in the image below.It should be noted that the size of the chucks should be constant throughout an instance.

<!-- Figure of binary search tree -->
![Double Ended Queue Implementation as shown by Konrad Rudolph]({{site.url}}/assets/images/deque.png)

<!-- https://stackoverflow.com/questions/6292332/what-really-is-a-deque-in-stl -->

<!-- Access times -->
The internal implementation around maps make it constant time access `O(1)` by making use of the house-keeping data in the lookup table. Pushing and poping an element from the front and back are both constant time access `O(1)`. However, insert is a linear time operation, since it has to move all elements by one position.

<!-- Operations possible -->
Set allows the following operations:
* Iterators: begin, end, rbegin, rend, cbegin, cend, crbegin, crend
* Capacity: empty, size, resize, shrink_to_fit
* Element Access: operator[], at, front, back
* Modification: assign, push_back, push_front, pop_back, pop_front, insert, erase, clear, emplace, emplace_back, emplace_front

Some detailed analysis of the operations on deque are found [here](https://www.codeproject.com/Articles/5425/An-In-Depth-Study-of-the-STL-Deque-Container) and [here](http://cpp-tip-of-the-day.blogspot.com/2013/11/how-is-stddeque-implemented.html).

Reference found [here](http://www.cplusplus.com/reference/deque/deque/).

___


### 11. std::forward_list  <a name="forwardlist"></a>

<!-- Header file -->
Present in header file `forward_list`.

<!-- General purpose and properties -->
Deque expands to double ended queue. This container should be preferred when elements are inserted or removed from either the front or back of the container frequently, while also allowing random access to the elements (by index).

<!-- Implementation -->
Forward lists are implemention of singly-linked lists. In which every element along with it's data also hold the pointer to the next element.

<!-- Deque is commonly implemented as dynamic arrays in which multiple arrays are attached with linked with each other. Generally these multiple arrays are managed from a lookup table. The working of this data structure is shown in the image below.It should be noted that the size of the chucks should be constant throughout an instance. -->


<!-- Figure of binary search tree -->
![Singly-Linked List]({{site.url}}/assets/images/forward-list.png)

<!-- Access times -->
<!-- The internal implementation around maps make it constant time access `O(1)` by making use of the house-keeping data in the lookup table. Pushing and poping an element from the front and back are both constant time access `O(1)`. However, insert is a linear time operation, since it has to move all elements by one position. -->

<!-- Operations possible -->
<!-- Set allows the following operations:
* Iterators: begin, end, rbegin, rend, cbegin, cend, crbegin, crend
* Capacity: empty, size, resize, shrink_to_fit
* Element Access: operator[], at, front, back
* Modification: assign, push_back, push_front, pop_back, pop_front, insert, erase, clear, emplace, emplace_back, emplace_front -->

<!-- Some detailed analysis of the operations on deque are found [here](https://www.codeproject.com/Articles/5425/An-In-Depth-Study-of-the-STL-Deque-Container). -->

<!-- Reference found [here](http://www.cplusplus.com/reference/deque/deque/). -->


___

### std::list

### std::queue

### std::stack

### std::array

### std::priority_queue <a name="priorityqueue"></a>

<!-- Header file -->
Present in header file `queue`.

<!-- General purpose and properties -->
Although they are not containers, the are container adaptors which can take form of a `vector` (default) or `deque`.
Priority queues are container that store elements with some interesting property (either min or max value) at the top of the tree, decreasing the access time. It allows only to retrieve the max (for max-heap) and min (for min-heap).

<!-- Implementation -->
They are implementation of binary heaps. In which a node has a value greater than equal to the children (for a max heap). Heaps are linear data structures, in which relation between children and parent can be obtain with the following equations:

`parent(n) = (n-1)/2`

`left-child(n) = (n+1)*2 - 1 = 2n + 1`
`right-child(n) = (n+1)*2 = 2n + 2`


 Therefore, it also has the provision to make use of a custom comparison function as a template parameter (requiring signature `bool comp(T lhs, T rhs)`). It can also take an allocator object when default memory allocation needs to be modified.

![Heap Representation of an array]({{site.url}}/assets/images/heap.png)

<!-- Access times -->
Since they are implemented as heaps, the time to access the value of interest (max - for max heap and min - for min heap) is `O(1)`. However, inserting an element into the heap takes `O(log n)` time. Since, insertions initially happen at the end of the array and keep climbing until they reach the desired position. (inserting an element actually calls the function `push_heap` on the underlying container). Pop operations also have a similar runtime.

<!-- Operations possible -->
Set allows the following operations:
* Iterators: **None**
* Capacity: empty, size
* Modification: push, emplace, pop
* Operations: top

Heap operations are also possible on standalone vector and deque with heap functions. These function are available in header `algorithm`.

A small demo program to show how to use a priority queue and standalone heap <a href="https://gist.github.com/naveenspace7/f3395243e7b720720e01dd90dca16e03">here</a>

<!-- http://www.cplusplus.com/reference/queue/priority_queue/ -->

<!-- https://www.cs.usfca.edu/~galles/visualization/Heap.html -->

___

## Summary

<!-- Final verdict -->

Q. Why to choose set against unordered_set when there is very little benefit gained by using the former? 

If you need to iterator through the container or need the elements to be sorted and using a small container with 100 elements, choose set.
For smaller sets prefer the usage of set, otherwise use an unordered_set. However, always benchmark when counting for performance.

Reference: 
<!-- https://stackoverflow.com/questions/1349734/why-would-anyone-use-set-instead-of-unordered-set -->
