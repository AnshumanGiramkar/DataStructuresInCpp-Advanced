#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> matrixToList(const vector<vector<int>>& matrix, int numVertices) {
    vector<vector<int>> list(numVertices);

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (matrix[i][j] == 1) {
                list[i].push_back(j);
            }
        }
    }
    return list;
}
vector<vector<int>> listToMatrix(const vector<vector<int>>& list, int numVertices) {
    vector<vector<int>> matrix(numVertices, vector<int>(numVertices, 0));

    for (int i = 0; i < numVertices; i++) {
        for (int j : list[i]) {
            matrix[i][j] = 1;
        }
    }
    return matrix;
}
vector<vector<int>> acceptMatrix(int numVertices) {
    vector<vector<int>> matrix(numVertices, vector<int>(numVertices, 0));

    cout << "Enter the adjacency matrix (0/1) for " << numVertices << " vertices:\n";

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}
vector<vector<int>> acceptList(int numVertices) {
    vector<vector<int>> list(numVertices);

    cout << "Enter the adjacency list for " << numVertices << " vertices:\n";

    for (int i = 0; i < numVertices; i++) {
        cout << "Enter the number of neighbors for vertex " << i << ": "<<endl;
        int numNeighbors;
        cin >> numNeighbors;

        cout << "Enter the neighbors for vertex " << i << ": ";
        for (int j = 0; j < numNeighbors; j++) {
            int neighbor;
            cin >> neighbor;
            list[i].push_back(neighbor);
        }
    }
    return list;
}
void displayMatrix(const vector<vector<int>>& matrix, int numVertices) {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void displayList(const vector<vector<int>>& list, int numVertices) {
    cout << "Adjacency List:\n";
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i << ": ";
        for (int neighbor : list[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;
    int numVertices, numEdges;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> adjacencyMatrix;
    vector<vector<int>> adjacencyList;

    do {
        cout << "\n---- MENU ----\n";
        cout << "1. Convert Adjacency Matrix to Adjacency List\n";
        cout << "2. Convert Adjacency List to Adjacency Matrix\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                adjacencyMatrix = acceptMatrix(numVertices);
                adjacencyList = matrixToList(adjacencyMatrix, numVertices);
                displayList(adjacencyList, numVertices);
                break;
            case 2:
                adjacencyList = acceptList(numVertices);
                adjacencyMatrix = listToMatrix(adjacencyList, numVertices);
                displayMatrix(adjacencyMatrix, numVertices);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
