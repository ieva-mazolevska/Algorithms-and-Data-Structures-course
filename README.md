# Algorithms-and-Data-Structures-course
Practical homework assignments and tests for Algorithms and Data Structures course

# TreeDequeQueueManager – Binary Tree Processing with Deque and Queue Integration

## Description

This program implements a **binary search tree (BST)** for integer values and supports key operations such as **insertion**, **search**, **deletion**, and **in-order traversal**. Additionally, it processes values from the tree based on given numerical intervals, moving them to a **deque** or a **queue**, both implemented as linked lists.

### Core Functionalities

- Build and manage a binary search tree (BST)
- Insert, search, delete, and print BST elements
- Implement a deque (double-ended queue) using a linked list
- Implement a queue using a linked list

### Additional Interval-Based Actions

1. **Insert into the front of the deque** all values in the interval `[a; b]` from the BST  
2. **Insert into the back of the deque** all values in the interval `[0; a]` from the BST  
3. **Remove from the BST** all values in the interval `[b; c]`, and add them to the **queue**  
4. Print the contents of the **deque** and **queue**
