# Round Robin Process Scheduler (C++)

This project implements a Round Robin CPU scheduling algorithm in C++, using a circular linked list to simulate time-sliced process execution. It reads execution times from a file, performs scheduling, and reports turnaround times per process and their average.

## Files

- `RoundRobinProcessScheduling.h` – Core scheduling class with time slicing, execution tracking, and turnaround time computation.
- `CircularLinkedList.h` – Circular linked list implementation used to model cyclic process queues.
- `Tester.cpp` – Program entry point; loads data, runs scheduler, displays results.
- `process.txt` – Input file containing:
  - Line 1: Time slice (int)
  - Line 2: Comma-separated process execution times

## Features

- Time-sliced execution simulation using a circular linked list
- Dynamic turnaround time tracking per process
- Average turnaround time calculation
- Modular structure for testing and reuse

## Example

`process.txt`:
