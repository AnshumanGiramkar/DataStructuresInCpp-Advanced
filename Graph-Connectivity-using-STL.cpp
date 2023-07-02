#include <iostream>
#include <vector>
bool isConnected(const std::vector<std::vector<int>>& adjList, int vertex1, int vertex2) {
    
    for (int neighbor : adjList[vertex1]) {
        if (neighbor == vertex2) {
            return true; 
        }
    }
    return false;
}

int main() {
    int numVertices;
    std::cout << "Enter the number of vertices: ";
    std::cin >> numVertices;

    std::vector<std::vector<int>> adjList(numVertices);

    std::cout << "Enter the adjacency list:\n";
    for (int i = 0; i < numVertices; ++i) {
        int numNeighbors;
        std::cout << "Enter the number of neighbors for vertex " << i << ": "<<std::endl;
        std::cin >> numNeighbors;

        std::cout << "Enter the neighbors for vertex " << i << ": "<<std::endl;
        for (int j = 0; j < numNeighbors; ++j) {
            int neighbor;
            std::cin >> neighbor;
            adjList[i].push_back(neighbor);
        }
    }
    int vertex1, vertex2;
    std::cout << "Enter two vertices to check if they are connected: ";
    std::cin >> vertex1 >> vertex2;

    bool connected = isConnected(adjList, vertex1, vertex2);

    if (connected) {
        std::cout << "Vertex " << vertex1 << " and vertex " << vertex2 << " are connected.\n";
    } else {
        std::cout << "Vertex " << vertex1 << " and vertex " << vertex2 << " are not connected.\n";
    }

    return 0;
}
