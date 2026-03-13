# Binary Tree Algorithms in C

This repository contains several binary tree and binary search tree algorithms implemented in C.  
The goal of this project is to demonstrate understanding of fundamental **data structures**, **recursion**, and **tree traversal techniques**.

The implementations include multiple algorithms for analyzing and traversing binary trees as well as common operations on binary search trees.

---

# Implemented Algorithms

## Algorithm Set 1 — Binary Tree Analysis

This module implements algorithms that analyze properties of a binary tree.

Implemented algorithms:

- **Maximum Key in a Binary Tree**  
  Finds the largest value stored in the tree by recursively exploring all nodes.

- **Additional Tree Traversal Logic**  
  Uses recursive traversal to visit nodes and evaluate their values.

Concepts used:

- recursion
- tree traversal
- divide and conquer

---

## Algorithm Set 2 — Counting Even Numbers in a Binary Tree

This module counts how many nodes in a binary tree contain **even values**.

Algorithm description:

The tree is recursively traversed and each node is evaluated.  
If a node contains an even value, the counter is incremented.

Concepts used:

- recursion
- conditional evaluation
- full tree traversal

---

## Algorithm Set 3 — Binary Tree Depth

This module calculates the **maximum depth (height)** of a binary tree.

The depth of a tree is defined as: depth = 1 + max(depth(left subtree), depth(right subtree))

Concepts used:

- recursion
- divide and conquer
- tree height computation

---

## Algorithm Set 4 — Binary Search Tree Operations

This module implements a **Binary Search Tree (BST)** with a menu-driven interface.

Implemented operations:

### Insert
Adds a new element to the BST while maintaining the BST property.

### Find k-th Smallest Element (`findMin_K`)
Uses **in-order traversal** to find the k-th smallest element.

Since in-order traversal of a BST returns elements in sorted order, the algorithm counts nodes until the k-th value is reached.

### Count Leaf Nodes (`numLeafNodes`)
Counts nodes that have **no children**.

### Level Order Traversal (`LevelOrder`)
Traverses the tree **level by level** using a queue (Breadth-First Search).

Example:

    10
   /  \
  5    15
 / \
3   7

Level Order Traversal:
10 5 15 3 7


Concepts used:

- Binary Search Trees
- In-order traversal
- Breadth-first traversal (BFS)
- Dynamic memory management

---

# Project Structure
binary-tree-algorithms

tree_analysis.c
tree_metrics.c
tree_comparison.c

bst.c
bst.h
test_bst.c

binary_tree_from_list.c

---

File description:

| File | Description |
|-----|-------------|
| tree_analysis.c | Binary tree analysis algorithms |
| tree_metrics.c | Counting even numbers in a binary tree |
| tree_comparison.c | Binary tree depth calculation |
| bst.c | Binary Search Tree implementation |
| bst.h | BST function declarations |
| test_bst.c | Menu-driven BST program |
| binary_tree_from_list.c | Tree construction helper functions |

---



# Concepts Demonstrated

This repository demonstrates understanding of:

- Binary Trees
- Binary Search Trees
- Recursion
- Tree Traversal Algorithms
- Breadth-First Search (BFS)
- Depth-First Search (DFS)
- Dynamic Memory Management in C
- Modular C Programming (.c / .h separation)

---

# Author

Carlos Torres González  
GitHub: https://github.com/CtglzzML

