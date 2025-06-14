#include <iostream>
#include <queue>
using namespace std;

// 8 directions define ki hain: up, down, left, right, aur diagonals similar to rat in a maze 
int dirX[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dirY[] = {1, 0, -1, 0, 1, 1, -1, -1};

int main() 
{
    int n, m;
    cout << "Enter number of rows:\t";
    cin >> n;
    cout << "Enter number of columns:\t";
    cin >> m;

    char A[n][m]; // 2D matrix
    bool visited[n][m] = {false}; // Ye array track karega kaunsi cells visit ho chuki hain

    // Matrix input
    for (int i = 0 ; i < n ; i++) 
	{
        for (int j = 0 ; j < m ; j++) 
		{
            cout << "Enter 'L' (Land) or 'W' (Water) for A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    // Matrix display
    cout << "\nInput matrix:\n";
    for (int i = 0 ; i < n ; i++) 
	{
        for (int j = 0 ; j < m ; j++) 
		{
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    int islandCount = 0; // Island counter- yeh final mein total number of islands count karega (cluster ya separate)

    // Har cell check karenge ek ek karke
    for (int i = 0 ; i < n ; i++)
	 {
        for (int j = 0 ; j < m ; j++) 
		{
            // Agar current cell 'L' hai aur abhi tak visit nahi hui
            if (A[i][j] == 'L' && !visited[i][j]) 
            {
                islandCount++; // Naya island mil gaya

                // Ab poore island ko visit karne ke liye BFS karenge path track hota jayega and queue mein dalte jayenge wali logic
                queue<pair<int, int> > q; // Queue mein x, y pairs dalenge for storing and processing the cooridnates 
                q.push({i, j}); // current 'L' wali cell ko queue mein daal diya
                visited[i][j] = true; // aur usay visited bhi mark kardiya

                while (!q.empty()) 
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    // Ab 8 directions mein check karenge connected L cells
                    for (int d = 0; d < 8; d++) 
                    {
                        int newX = x + dirX[d];
                        int newY = y + dirY[d];

                        // Conditions:
                        // 1. new coordinates matrix ke andar hon
                        // 2. 'L' ho for island check
                        // 3. pehle visit na hui ho
                        if (newX >= 0 && newX < n && newY >= 0 && newY < m 
                            && A[newX][newY] == 'L' && !visited[newX][newY]) 
                        {
                            visited[newX][newY] = true; // Mark visited
                            q.push({newX, newY}); // Queue mein daaldo taake uske neighbors check kar sakein
                        }
                    }
                }
            }
        }
    }

    cout << "\nTotal number of islands in the matrix is: " << islandCount << endl;

    return 0;
}

