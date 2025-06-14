#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Directed Graph ke liye DFS 
bool dfsCheck(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathvis) 
{
    vis[node] = 1;          // Node ko visited mark karo
    pathvis[node] = 1;      // Aur usay current DFS path mein bhi mark karo

    // Saare adjacent (connected) nodes check karo
    for (int i = 0; i < adj[node].size(); i++) 
	{
        int neighbor = adj[node][i];   // Neighboring node check karo
        
        if (vis[neighbor] == 0) // Agar neighbor visited nahi
		{      
            if (dfsCheck(neighbor, adj, vis, pathvis)) 
			{
                return true;           // Agar DFS se cycle mili toh true return karo
            }
        } 
		else if (pathvis[neighbor] == 1) // Agar neighbor pehle se current DFS path mein hai, toh cycle hai
		{
            
            return true;
        }
    }

    pathvis[node] = 0;  // Current path se node ko hata do (backtracking)
    return false;
}

/* 
Directed graph mein cycle tab count hota hai jab ek path ke andar hi kisi visited node par dobara aa jayein.
Agar koi node already visited hai aur woh current DFS path ka hissa hai (pathvis[node]==1), 
toh iska matlab hai wapas usi path pe ghoom ke aaye ho — so, cycle detected!
*/


// Directed graph mein cycle detect karne ke liye
bool isCyclicDirected(int V, vector<int> adj[]) 
{
    vector<int> vis(V, 0);     // Har node ka visited status
    vector<int> pathvis(V, 0); // Current DFS path ke liye tracking

    for (int i = 0; i < V; i++)
	 {
        if (vis[i] == 0) // Agar node abhi tak visit nahi hua
		 {             
            if (dfsCheck(i, adj, vis, pathvis)) 
			{
                return true;           // Agar kahin se cycle mili
            }
        }
    }
    return false;  // Cycle nahi mili
}

/*
Undirected graph mein agar koi node kisi dusre path se visit ho gayi ho aur woh current node ka parent nahi hai,
toh iska matlab cycle hai. Parent hona normal hai, but agar koi aur direction se usi node pe wapas aayein — CYCLE!
we often come back to the node we just came from in undirected . This is not a cycle, it's just the nature of undirected edges 
0-1, { 1-2, 2-3, 3-4, 4-1 } cycle wala part
If you start BFS from node 0, path may look like:

0 (parent: -1) ? 1 (parent: 0) ? 2 (parent: 1) ? 3 (parent: 2) ? 4 (parent: 3)
Now, when you're at node 4, and you look at its neighbor 1:

1 is already visited and its not the parent of 4 as 4 comes through 3 wala path hence here cycle is detect (1!= parent of 4) 1 is not a parent of 4 

*/

// Undirected Graph ke liye BFS se cycle detection
bool detectbfs(int src, vector<int> adj[], int vis[]) 
{
    vis[src] = 1;  // Source ko visited mark karo (starting point src rehne wala hai)
    queue<pair<int, int>> q;  // Queue of (child, parent) child-parent node ke bad wala node (after) parent(prev node)
    q.push({src, -1});        // Initial node ka parent -1

    while (!q.empty())
	 {
        int child = q.front().first;     // Current node
        int parent = q.front().second;  // Uska parent
        q.pop();

        // Har adjacent node check karo
        for (int i = 0; i < adj[node].size(); i++) {
            int adjNode = adj[child][i];
            if (!vis[adjNode]) 
			{
                vis[adjNode] = 1;           // Agar visit nahi hua toh mark karo
                q.push({adjNode, child});    // Usay queue mein daalo with current node as parent
            }
            else if (adjNode != parent) 
			{
                // Agar already visited hai aur parent bhi nahi hai toh cycle hai
                return true;
            }
        }
    }
    return false;  // BFS khatam, koi cycle nahi mili
}

// Overall Undirected Graph ke liye cycle detection
bool isCycle(int V, vector<int> adj[]) 
{
    int vis[V] = {0};   // Sab nodes ko unvisited rakho
    for (int i = 0; i < V; i++)
	 {
        if (!vis[i]) 
		{
            if (detectbfs(i, adj, vis))
			 {
                return true;   // Kahin se bhi cycle milti hai toh return true
            }
        }
    }
    return false;  // No cycle found
}

// Function to add edge based on graph type (directed ya undirected)
void addEdge(vector<int> adj[], int u, int v, int isDirected) {
    adj[u].push_back(v);       // u ->v connection daalo
    if (!isDirected) 
	{
        adj[v].push_back(u);   // Undirected ke liye v -> u bhi daalo
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    int isDirected;
    cout << "Enter 1 for Directed graph, 0 for Undirected graph: ";
    cin >> isDirected;

    vector<int> adj[V];   // Adjacency list banayi

    // User se saare edges ka input lena
    for (int i = 0; i < E; i++) {
        int src, dest;
        cout << "Enter the source and destination for edge " << (i + 1) << ": ";
        cin >> src >> dest;
        addEdge(adj, src, dest, isDirected);  // Graph mein edge daalo
    }

    // Final check: Graph directed hai toh DFS-based check, warna BFS-based
    if (isDirected) {
        if (isCyclicDirected(V, adj)) {
            cout << "Cycle detected in Directed Graph." << endl;
        } else {
            cout << "No cycle in Directed Graph." << endl;
        }
    } else {
        if (isCycle(V, adj)) {
            cout << "Cycle detected in Undirected Graph." << endl;
        } else {
            cout << "No cycle in Undirected Graph." << endl;
        }
    }

    return 0;
}




