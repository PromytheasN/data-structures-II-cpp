# AVL Tree Implementation (C++)

A self-balancing AVL Tree implementation with full support for insertion, deletion, searching, and various traversal and analysis functions. Includes a test driver (`TesterTemp.cpp`) to demonstrate usage and output.

## Files

- `AVLTree.h` – AVL Tree class with balancing, traversal, and utility methods.
- `TesterTemp.cpp` – Driver program to test tree operations and display results.

## Features

- AVL balancing (LL, LR, RR, RL rotations)
- Element search (recursive)
- Tree visualizations: level-order and horizontal
- Count nodes in range and at levels
- Tree diameter calculation (longest path)

## Sample Usage

```bash
g++ TesterTemp.cpp -o avl
./avl
