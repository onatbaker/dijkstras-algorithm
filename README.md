A **shortest path algorithm** built around a graph traversal technique inspired by Dijkstra's Algorithm. The graph is efficiently represented using `unordered_map` in C++, where each edge comes with a weight (cost), and the algorithm works its magic to find the optimal path through the network of nodes.

## Features

- **Shortest Path Calculation**: Implements a basic algorithm to find the shortest path in a weighted graph.
- **Efficient Graph Representation**: Utilizes `unordered_map` for quick access and efficient graph traversal.
- **Greedy Algorithm**: Uses a greedy approach to iteratively find the node with the lowest cost.

## How the Algorithm Works

The algorithm follows a simple **greedy approach** to find the shortest path from the starting node to all other nodes in the graph:

1. **Initialization**: 
   - Set the cost of the starting node to 0, and the cost of all other nodes to infinity (`inf`).
   - Set the parent of the starting node to `null` (or empty), and initialize the parent for all other nodes.
   
2. **Greedy Selection**:
   - At each step, the algorithm selects the node with the **lowest cost** that has not been processed yet.
   
3. **Cost Update**:
   - For each **neighboring node** of the selected node, the algorithm checks if a cheaper path can be found.
   - If a cheaper path is found, the cost is updated, and the parent of the neighbor is set to the current node.
   
4. **Repeat**:
   - This process repeats until all nodes are processed, and the shortest paths from the starting node are finalized.

This approach ensures that each node is processed in the order of its proximity to the start, with the shortest path being selected at each step.

## Note

- If you are using **C++17 or later**, you can improve the code readability and reduce boilerplate by using **structured bindings**. This code was written in **C++14**, so **no** structure bindings


