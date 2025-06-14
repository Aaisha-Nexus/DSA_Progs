#include <iostream>
#include <vector> //using vector to dynamically store the list
#include <queue> //used in BFS 
#include<stack> //Used in DFS
using namespace std;

//edge strcuture as each edge will hold source and destination
struct Edge {
    int src;
    int dest;
};

// Function to add an edge and "vector<Edge> graph[]" means it is array of vectors
void addEdge(vector<Edge> graph[], int src, int dest , bool isDirected) //each vertex(index) will have a list of edges attached to it along with src and dest from user 
  {
    // Add edge from src to dest
    graph[src].push_back({src, dest});
    
    // If it's an undirected graph, also add edge from dest to src
    if(!isDirected)
    {
	graph[dest].push_back({dest, src});
	}
}	

//fuunction to count the degree 
void countDegree(vector<Edge> graph[], int V, bool isDirected)
{
    if (!isDirected) // degree for undirected Graph is the size of list at each vertex 
    {
        cout << "Degree of each vertex in Undirected Graph:" << endl;
        for (int i = 1; i <= V ; i++)
        {
            cout << "Vertex " << i << " has degree " << graph[i].size() << endl;
        }
    }
    else // degree for directed Graph has In and Out accordingly [OUTDEGREE- SIZE OF LIST SHOWS HOW MANY DIRECTLY SRC->DEST] [INDEGREE NEEDS TO GO THROUGH LIST AND CHECK EDGES FOR DEST]
    {
        cout << "In-degree and Out-degree for each vertex in Directed Graph:" << endl;
        
        vector<int> indegree(V, 0); //initiliase in and outdegree with 0
        vector<int> outdegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            outdegree[i] = graph[i].size(); // Out-degree is directly size of list

            for (int j = 0; j < graph[i].size(); j++)
            {
                int destVertex = graph[i][j].dest;
                indegree[destVertex]++;
            }
        }

        for (int i = 1; i <= V; i++)
        {
            cout << "Vertex " <<  i << ": In-degree = " << indegree[i]
                 << ", Out-degree = " << outdegree[i] << endl;
        }
    }
}

/*DFS FUNCTION 
Uses stacks for push and pops teh value from top using LIFO rule*/
vector<int> DFS(int V, vector<Edge> graph[], int dfsstartnode) {
    vector<bool> visited(V + 1 , false);  
    vector<int> dfs;                 
    stack<int> st; //DFS uses Stack implementation 
    
    visited[dfsstartnode] = true; //mark the first starting node as true 
    st.push(dfsstartnode); //and push in the stack 
    
    while(!st.empty()) //till stack is not empty keep running 
    {
    	int node = st.top(); //save the top in node 
        st.pop(); //and pop it as backtracking we do 
        dfs.push_back(node); //push it in dfs traversal 
        
         // Traverse neighbors of 'node'
        for (int j = 0; j < graph[node].size(); j++) 
		{
            int neighbor = graph[node][j].dest; //check for each neighbouring in depth 
            if (!visited[neighbor])  //if its not visited then visit it and mark as true 
			{
                visited[neighbor] = true;
                st.push(neighbor); //push the neighbour in stack 
            }
        }
    }

    return dfs;
}

/*BFS function
	1) use queue for FIFO and add edges to it (Adjacency list has edges of each vertex which are the neighbours)
	2) Take another array/vector which is visited array which will be of bool type and mark 1 to the nodes visited if(!visisted) then put in queue 
	3) Print the nodes which are out of queue and visisted  */
vector<int> BFS(int V, vector<Edge> graph[], int startnode) {
    vector<bool> visited(V + 1 , false); 
    vector<int> bfs;                
    queue<int> q;

    visited[startnode] = true; //mark the starting node as true
    q.push(startnode); //and push in queue 

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        // Traverse neighbors of 'node'
        for (int j = 0; j < graph[node].size(); j++) {
            int neighbor = graph[node][j].dest;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return bfs;
}

// Function to print the adjacency list of the graph
void displayGraph(vector<Edge> graph[], int V) {
    for (int i = 1; i <= V; i++) {
        cout << i << " = {";
        // Traditional for loop to iterate over the vector
        for (int j = 0; j < graph[i].size(); j++) {
            cout << "{" << graph[i][j].src << "," << graph[i][j].dest << "}";
            if (j != graph[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "}" << endl;
    }
}

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Dynamically allocate the adjacency list based on the number of vertices
    vector<Edge> graph[V + 1];

    cout << "Enter the number of edges: ";
    cin >> E;
	    
	    int isDirected;
		cout << "Enter 1 for Directed graph, 0 for Undirected graph: ";
		cin >> isDirected;

    // Take edge inputs from the user
    for (int i = 0; i < E; i++) {
        int src, dest;
        cout << "Enter the source and destination for edge " << (i + 1) << ": ";
        cin >> src >> dest;
        addEdge(graph, src, dest, isDirected);
    }

    // Display the adjacency list of the graph in the desired format
    displayGraph(graph, V);
    
    // Count and display degrees
    countDegree(graph, V, isDirected);
    
    
	
    //BFS display
        int startnode;
    cout << "Enter the starting node for BFS: ";
    cin >> startnode;

	vector<int> result = BFS(V + 1, graph, startnode);

    cout << "BFS Traversal starting from node " << startnode << ": ";
    for (int i = 0; i < result.size(); i++) 
	{
    cout << result[i] << " " ;
	}
	cout << endl;
	
	 //DFS display
        int dfsstartnode;
    cout << "Enter the starting node for DFS: ";
    cin >> dfsstartnode;

	vector<int> dfsresult = DFS(V + 1, graph, dfsstartnode);

    cout << "DFS Traversal starting from node " << dfsstartnode << ": ";
    for (int i = 0; i < dfsresult.size(); i++) 
	{
    cout << dfsresult[i] << " ";
	}


    return 0;
}

