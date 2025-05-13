# Algorithms-and-Data-Structures-course
Practical homework assignments and tests for Algorithms and Data Structures course

# Custom Singly and Doubly Cyclic Linked List Operations

## Description

This program implements a **custom cyclic singly linked list** (without STL) and performs various operations such as insertion, deletion, and data manipulation. It also uses a **cyclic doubly linked list** to process selected elements.

### Core Features:

- Create and populate a **cyclic singly linked list**
- Insert a new element **before or after** a specified value
- Remove a **specified element**
- Find the **maximum element**
- Transfer the **first 6 negative values** to a **cyclic doubly linked list**
- Compare sums between:
  - **Even elements (by absolute value)** in the **doubly cyclic list**
  - **Odd elements** in the **singly cyclic list**
- Remove and print the **first**, **middle**, and **last** elements of the singly cyclic list

### ❗ STL is not used in this implementation, as per assignment requirements.

---

## Functionality

### Singly Cyclic List:

- `Insert(value)`: Insert a new element at the end
- `InsertBefore(target, value)`: Insert before specified value
- `InsertAfter(target, value)`: Insert after specified value
- `Delete(value)`: Remove the element with specified value
- `FindMax()`: Find and return the node with the highest value
- `RemoveFirstMiddleLast()`: Remove and display first, middle, and last elements

### Doubly Cyclic List:

- `Add(value)`: Add new element at the end
- `CountEvenSumGreaterThanOddSum()`: Compare absolute even sum (doubly list) vs odd sum (singly list)
