# Algorithms-and-Data-Structures-course
Practical homework assignments and tests for Algorithms and Data Structures course

# AdvancedListManipulator – Dual List Processing with STL

## Description

This program manages a general-purpose list using STL (e.g., `std::list`, `std::forward_list`) and implements a variety of operations on both a **doubly linked list** and a **singly circular list**.

### Supported Operations:

- Insert elements at the end of the list
- Insert **before** and **after** a specified element
- Remove a **specific element**
- Find the **maximum value**
- Build a **singly circular list** from all elements **after the last `0`**
- Calculate how many elements in the circular list are **greater than the average** of all elements in the **doubly linked list**
- Remove all elements **between the third and the second-to-last** in the circular list and **print them**

---

## Features

### Doubly Linked List (with STL):

- Built using `std::list<int>`
- Input and edit operations: insert, remove, max search

### Singly Circular List:

- Constructed using a custom implementation or `std::forward_list` with tail-loop pointer
- Populated with all elements **after the last 0** from the original list

### Analysis:

- Calculate **average** of all elements in the doubly list
- Count elements in the **circular list** that are greater than this average
- Delete and print all elements **between the 3rd and second-to-last node** in the circular list
