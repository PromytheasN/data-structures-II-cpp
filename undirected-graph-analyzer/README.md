# Undirected Graph Analyzer (C++)

This project implements a class-based undirected graph system in C++, with support for vertex and edge tracking, degree analysis, pathfinding, cycle detection, and multiple display formats. It includes a randomized adjacency matrix generator for demo purposes.

## Files

- `Graph.h` – Graph class with adjacency list, edge list, and all core algorithms.
- `testGraph.cpp` – Driver to test all graph features on a randomly generated matrix.

## 🔧 Features

- 🔹 Graph creation from adjacency matrix  
- 🔹 Adjacency list and edge list construction  
- 🔹 Vertex and edge count functions  
- 🔹 Neighbor and degree analysis (with sorted output)  
- 🔹 Pathfinding via DFS  
- 🔹 Cycle detection using DFS traversal  
- 🔹 Clean console output for all operations  

## 🧪 Example Usage

```bash
g++ testGraph.cpp -o graph
./graph
