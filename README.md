# Unweighted Graph Class

This C++ code defines a class `unweightedGraph` that represents an unweighted graph using an adjacency list. It provides various graph operations and algorithms such as depth-first search (DFS), breadth-first search (BFS), checking if two nodes are connected, checking if the graph is strongly connected, and detecting cycles in the graph.

## Usage

You can use this class to create an unweighted graph and perform different operations on it. Here's an example of how to use the class:

```cpp
    // Create an instance of unweightedGraph with 5 vertices
    unweightedGraph graph(5);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Perform operations on the graph
    bool isConnected = graph.isConnected(); // Check if the graph is connected
    bool hasCycle = graph.hasCycle(); // Check if the graph has a cycle

    // Print the result
    std::cout << "Is the graph connected? " << (isConnected ? "Yes" : "No") << std::endl;
    std::cout << "Does the graph have a cycle? " << (hasCycle ? "Yes" : "No") << std::endl;
```

Make sure to include the `unweightedGraph.h` header file in your project and compile it along with the implementation file.

## Class Methods

The `unweightedGraph` class provides the following methods:

- `unweightedGraph(int count)`: Constructor to initialize the graph with the given number of vertices.
- `void addEdge(int u, int v)`: Adds an edge between vertices `u` and `v` in the graph.
- `bool isConnected()`: Checks if the graph is connected (all vertices are reachable from any other vertex).
- `bool hasCycle()`: Checks if the graph contains a cycle.
- `void BFS(int start)`: Performs breadth-first search traversal starting from the given vertex.
- `void DFS(int start)`: Performs depth-first search traversal starting from the given vertex.
- `bool checkConnection(int u, int v)`: Checks if there is a path between vertices `u` and `v` in the graph.
- `bool isConnectedStrongly()`: Checks if the graph is strongly connected (there is a directed path between any pair of vertices).
- `unweightedGraph getReverse()`: Returns the reverse of the graph (reverses the direction of all edges).

Feel free to modify and extend the code according to your specific requirements.
