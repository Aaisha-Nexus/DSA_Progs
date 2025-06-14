#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// structure for an edge
struct Edge {
    int src;
    int dest;
    int weight;
};

// Comparator for sorting edges by weight because in Kruskal we pick the edge with minimum weight first 
bool compareByWeight(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to find the parent (root) of a node
int findParent(int node, vector<int>& parent) {
    while (node != parent[node]) 
	{
        node = parent[node]; // keep up to find the root
    }
    return node;
}

// Function to join two sets (combine components)
void unionSets(int u, int v, vector<int>& parent)
 {
    int pu = findParent(u, parent); // find parent of u
    int pv = findParent(v, parent); // find parent of v
    if (pu != pv) 
	{
        parent[pu] = pv; // connect u's group with v's group
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges(E); // to store all edges
    for (int i = 0; i < E; i++) {
        cout << "Enter src, dest, weight for edge " << i + 1 << ": ";
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    // Sort all edges by weight
    sort(edges.begin(), edges.end(), compareByWeight);

    vector<int> parent(V); // to track parent of each node 

    // Initially, each node is its own parent (each node is in its own group)
    for (int i = 0; i < V; i++) 
	{
        parent[i] = i;
    }

    vector<Edge> mst; // to store final MST edges
    int totalWeight = 0; // adds up all MST edge weights

    // Loop through edges and build MST
    for (int i = 0; i < E && mst.size() < V - 1; i++)  // In MST, always V - 1 edges cause no loop as it is a Tree 
    {
        int u = edges[i].src;  // store the source and destination in u and v variables 
        int v = edges[i].dest;

        int pu = findParent(u, parent);
        int pv = findParent(v, parent);

        // Only connect if they are in different groups (no cycle)
        if (pu != pv) 
		{
            mst.push_back(edges[i]); // if not forming a cycle, include the edge
            totalWeight += edges[i].weight; // add to the total weight
            unionSets(pu, pv, parent); // merge the groups
        }
    }

    // Display the MST
    cout << "\nMST using Kruskal's Algorithm:\n";
    for (int i = 0; i < mst.size(); i++) {
        cout << mst[i].src << " -- " << mst[i].dest << "  (weight: " << mst[i].weight << ")\n";
    }
    cout << "Total MST Weight: " << totalWeight << endl;

    return 0;
}

