#include<iostream>
using namespace std;

// Global variables for rows and columns (user input se set honge)
int rows, cols;

// Graph ko represent karne ke liye adjacency matrix banayi gayi hai
bool matrix[10][10] = {false}; // Initial sab values false (edge nahi hai)

// Har edge ki value temporarily lene ke liye variable bool hai 
bool edge;

// Stack DFS k liye 
int stack[10];

// Queue (BFS ke liye)
struct Queue
{
    int size;       // Queue ka maximum size
    int front, rear; // Queue ke front aur rear pointers
    int *arr;       // Dynamically allocated array
};

// Nayi queue create karne ke liye function 
Queue* createQueue(int size)
{
    Queue* q = new Queue;        // Queue ke liye memory allocate ki
    q->size = size;              // User defined size set ki
    q->front = -1;               // Initially front and rear empty hain
    q->rear = -1;
    q->arr = new int[size];      // Array bhi dynamic hai
    return q;
}

// Graph ke andar edges insert karne ka function
void insert(int ans)  // 1 = Directed, 0 = Undirected
{
    // Matrix ko initially false se fill kar do
    for(int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < cols; j++) 
        {
            matrix[i][j] = false;
        }
    }

    // Directed graph ke liye input logic
    if(ans == 1)
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                cout << "Enter edge from " << i << " to " << j << ": ";
                cin >> edge;
                matrix[i][j] = edge; // Sirf i to j direction mein edge set karo cause directed hai 
            }
        }
    }

    // Undirected graph ke liye input logic
    else if(ans == 0)
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                cout << "Enter edge between " << i << " and " << j << ": ";
                cin >> edge;
                matrix[i][j] = edge;    // i to j
                matrix[j][i] = edge;    // j to i (kyunke undirected hai) toh dono taraf hoga 
            }
        }
    }
    else
    {
        cout << "Invalid input. Enter 1 for directed or 0 for undirected.\n";
    }
}

// Check queue full to nahi ho gaya
bool isFull(Queue* q)
{
    if(q->rear == q->size - 1)
        return true;
    return false;
}

// Check queue khaali hai ya nahi
bool isEmpty(Queue* q)
{
    if(q->front == -1 || q->front > q->rear)
        return true;
    return false;
}

// Queue mein value daalne ka function
void enQueue(struct Queue* q, int value)
{
    if(isFull(q))
    {
        cout << "Queue is full\n"; // Agar queue full ho gaya then yeh display kardo 
    }
    else
    {
        if(q->front == -1)  // Pehli dafa insert ho raha hai
        {
            q->front = 0;
        }
        q->rear++;              // Rear ko aage badhao
        q->arr[q->rear] = value; // Value daalo
    }
}

// Queue se value nikalne ka function
int deQueue(struct Queue* q)
{
    int a = -1;
    if(isEmpty(q))
    {
        cout << "Queue is empty\n"; // Agar queue empty hai toh yeh display karo
    }
    else
    {
        a = q->arr[q->front]; // Front element nikaalo
        q->front++;           // Front ko aage badhao
    }
    return a;
}

// Breadth First Search (BFS) traversal function
void bfs(int source)
{
    Queue* q = createQueue(20);    // 20 elements ki queue create ki
    int visited[10] = {0};         // Visited array banaya, sab 0 (unvisited)
    visited[source] = 1;           // Source node ko visited mark kiya
    cout << "\nBFS Traversal: ";
    cout << source << " ";         // Source node print kiya
    enQueue(q, source);            // Source node ko queue mein daala

    // Jab tak queue khaali na ho jaaye
    while(!isEmpty(q))
    {
        int node = deQueue(q);     // Ek node dequeue kiya
        for (int i = 0; i < cols; i++) // Us node ke neighbours check karo
        {
            // Agar edge hai aur neighbour visit nahi hua
            if(matrix[node][i] && visited[i] == 0)
            {
                visited[i] = 1;     // Visit mark karo
                cout << i << " ";   // Node print karo
                enQueue(q, i);      // Queue mein daalo
            }
        }
    }
}


// DFS traversal 
void dfs(int node, int visited[] = NULL)
{
	
     int localVisited[10] = {0}; //  visited array — sirf pehli call me initialize hoga

    if (visited == NULL)            // Agar pehli call hai to use karo
        visited = localVisited;

    visited[node] = 1;                 // Node ko visited mark karo
    cout << node << " ";              // Node print karo (visit)

    for (int i = 0; i < cols; i++)     // Uske saare neighbours check karo
    {
        if (matrix[node][i] && !visited[i]) // Agar edge hai aur wo node visit nahi hua
        {
            dfs(i, visited);          // Recursively call DFS on neighbour
        }
    }
}


// Adjacency matrix print 
void printMatrix()
{
    cout << "\nAdjacency Matrix:\n";
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}


int main()
{
    int ans;     // Graph type (1 = Directed, 0 = Undirected)
    int source;  // Traversal start karne ka source node

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter 1 for Directed Graph, 0 for Undirected Graph: ";
    cin >> ans;

    insert(ans);          // Graph input lena
    printMatrix();        // Adjacency matrix print karna

    cout << "Enter source node for traversal: ";
    cin >> source;

    bfs(source);          // BFS call karna
    cout<< "\nDFS Traversal:" ;
    dfs(source);          // DFS call karna

    return 0;
}

