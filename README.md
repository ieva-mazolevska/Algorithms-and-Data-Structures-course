# Algorithms-and-Data-Structures-course
Practical homework assignments and tests for Algorithms and Data Structures course

# CycleToDequeConverter – From Doubly Cyclic List to Singly Deque

## Description

This program implements two key data structures and transfers data between them:

1. A **dynamic doubly cyclic linked list** with:
   - Insertion
   - Deletion
   - Search
   - Printing

2. A **singly linked deque (double-ended queue)** with:
   - Insertion at the **front** or **back**
   - Deletion from the **front** or **back**

### Purpose

The program allows users to input and manage elements in a cyclic doubly linked list and then **transfer all of its elements** into a **custom singly linked deque**, maintaining full deque functionality.

---

## Functionality

### Doubly Cyclic List

- Circular navigation (head connects to tail and vice versa)
- Dynamic memory management
- Operations:
  - `insert(value)`
  - `remove(value)`
  - `print()`
  - `search(value)`

### Singly Linked Deque

- Implemented as a **singly linked list**
- Head and tail pointers
- Operations:
  - `push_front(value)`
  - `push_back(value)`
  - `pop_front()`
  - `pop_back()`
  - `print()`
