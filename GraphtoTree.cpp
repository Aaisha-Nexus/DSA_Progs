#include <iostream>
#include <vector>
using namespace std;

/*
  Undirected Graph mein DFS se cycle detect karne ka tareeqa:
  Agar koi node apne parent ke siwa kisi aur visited node se connect hota nazar aaye,
  matlab cycle hai. Us edge ko hata denge taake graph tree ban jaye.
*/

// DFS function jo cycle dhundhta hai aur cycle wali edge removedEdges mein store karta hai
bool dfsCycle(int node, int parent, vector<int> adj[], vector<int>& vis, vector<pair<int, int>>& removedEdges) {
    vis[node] = 1;  // is node ko ab visit mark kar diya

    // iss node ke saare neighbors check karo
    for (int i = 0; i < adj[node].size(); i++) {
        int neighbor = adj[node][i];

        if (!vis[neighbor]) {
            // agar neighbor pehli dafa visit ho raha hai, to DFS recursively chalao
            if (dfsCycle(neighbor, node, adj, vis, removedEdges)) {
                return true;  // agar recursion se cycle mili, turant wapas aao
            }
        }
        else if (neighbor != parent) {
            // agar neighbor visited hai lekin parent nahi hai to cycle hai
            // yeh edge cycle create kar rahi hai, isko hatao
            removedEdges.push_back({node, neighbor});
            return true;
        }
    }

    // agar iss branch mein koi cycle nahi mili, false return karo
    return false;
}

// pura graph traverse karke cycle edges remove karne wali function
vector<pair<int, int>> removeCycleEdges(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);                  // har node ka visited status
    vector<pair<int, int>> removedEdges;    // cycle wali edges store karne ke liye

    // har connected component ke root node se DFS start karo
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            // parent = -1 matlab yeh root node hai, is ka koi parent nahi
            dfsCycle(i, -1, adj, vis, removedEdges);
        }
    }

    return removedEdges;  // jo edges remove karni hain, return kar do
}

// Undirected graph mein edge add karne ka function
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);  // u -> v
    adj[v].push_back(u);  // v -> u (kyunki undirected graph)
}

int main() {
    int V, E;
    cout << "Vertices aur edges ki tadaad daalo: ";
    cin >> V >> E;

    // adjacency list banalo
    vector<int> adj[V];

    cout << "Edges daalo (u v format):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    // cycle wali edges hatao
    vector<pair<int, int>> toRemove = removeCycleEdges(V, adj);

    // output dikhao
    cout << "\nIn edges ko remove karo taake graph tree ban jaye:\n";
    for (int i = 0; i < toRemove.size(); i++) {
        cout << toRemove[i].first << " - " << toRemove[i].second << endl;
    }

    return 0;
}

