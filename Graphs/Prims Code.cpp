#include <iostream>
#include <limits.h> // for INT_MAX
using namespace std;

#define MAX 100

int graph[MAX][MAX]; // 2D adjacency matrix
int parent[MAX];     // stores the MST
int key[MAX];        // minimum weight edge to reach a vertex
bool inMST[MAX];     // checks if node is already in MST

// finds the vertex with the smallest key value not in MST
int findMinKey(int n) 
{
    int min = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < n; v++) {
        if (!inMST[v] && key[v] < min) // only consider nodes not in MST
		{
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter the adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++)  // input matrix row by row
	{
        for (int j = 0; j < V; j++) 
		{
            cin >> graph[i][j];
        }
    }

    // initialize arrays
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX; // no edge yet
        inMST[i] = false; //not in MST yet
        parent[i] = -1; // no parent yet
    }

    key[0] = 0; // start from vertex 0, key=0 means pick it first


    for (int count=0; count< V - 1; count++) {
        int u = findMinKey(V); // pick u with the smallest key not in MST 
        inMST[u] = true;       // include u in MST

        // update keys of all adjacent vertices
        for (int v = 0; v < V; v++) 
		{
			// if there is an edge from u to v
            // and v is not yet in MST
            // and weight of u-v is less than current key[v]
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v])
			 {
                key[v] = graph[u][v]; // update key with smaller weight
                parent[v] = u; // update parent to u
            }
        }
    }

    int totalWeight = 0;
    cout << "MST Edges:"<<endl;
    for (int i = 1; i < V; i++) {
        cout<<parent[i]<<"-"<<i<<"(cost: " << graph[i][parent[i]] << ")"<<endl;
        totalWeight += graph[i][parent[i]];
    }

    cout<<"Total weight of MST = "<<totalWeight<<endl;

    return 0;
}
