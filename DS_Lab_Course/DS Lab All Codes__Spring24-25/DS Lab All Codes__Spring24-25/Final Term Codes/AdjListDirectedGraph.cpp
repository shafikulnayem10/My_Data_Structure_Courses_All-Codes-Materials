#include <iostream>
using namespace std;

int main() {
    int nodes, edges;

    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Enter number of edges: ";
    cin >> edges;

    int adjList[50][50] = {0};
    int array[50] = {0};

    cout << "Enter " << edges << " edges:\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        // Since the graph is directed
        adjList[u][array[u]++] = v;
    }

    cout << "\nAdjacency List (Directed Graph):\n";
    for (int i = 0; i < nodes; i++) {
        cout << i << ": ";
        for (int j = 0; j < array[i]; j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}


