# Skip List & Circular Linked List Implementation (C++)

This project demonstrates two advanced data structures implemented in C++: a **Skip List** for efficient ordered data operations and a **Circular Linked List** for constant-time rotation and cyclic traversal. Both are built using custom node classes and dynamic memory.

## Files

- `SkipList.h` – Core skip list logic with randomized multi-level node structure.
- `Node.h` – Shared node definition used by the skip list (multi-pointer per level).
- `CircularLinkedList.h` – Singly circular linked list with insert, delete, search, update, and traversal.
- `testSkip.cpp` – Demonstrates skip list usage.


## Skip List Features

- Probabilistic height-based node structure
- Fast search and insertion (O(log n) on average)
- Dynamic level assignment per node (coin-flip model)
- Customizable max level index

## Circular Linked List Features

- Insert, delete, and update operations
- Efficient wraparound traversal
- Size tracking and indexed access
- Destructor handles full memory cleanup

## How to Run

```bash
g++ testSkip.cpp -o skiplist
./skiplist
