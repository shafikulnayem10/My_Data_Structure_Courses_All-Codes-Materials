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

        // Since the graph is undirected

        // Use these 2 lines if you want to show self loop 2 times for undirected graph
        //adjList[u][array[u]++] = v;
        //adjList[v][array[v]++] = u;

        // Use this conditional lines if you want to show self loop only once
        if(u==v)
        {
            adjList[u][array[u]++] = v;
        }
        else
        {
            adjList[u][array[u]++] = v;
            adjList[v][array[v]++] = u;
        }
    }

    cout << "\nAdjacency List (Undirected Graph):\n";
    for (int i = 0; i < nodes; i++) {
        cout << i << ": ";
        for (int j = 0; j < array[i]; j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}

