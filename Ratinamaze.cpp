#include <iostream>
#include <queue>
#include <vector> //mouse ka path is mein store hoga aagey
using namespace std;

// 8 directions: up, down, left, right, and diagonals
int dirX[] = {0, 1, 0, -1, -1, 1, -1, 1};  //yeh saare valid movements honge 
int dirY[] = {1, 0, -1, 0, 1, 1, -1, -1};

int main() 
{
    int n, m;
    cout << "Enter the number of rows:\t";
    cin >> n;
    cout << "Enter the number of columns:\t";
    cin >> m;

    int A[n][m]; //normal 2d array
    bool visited[n][m] = {false}; //ek visited ka array hoga usi original size ka jis mein visited paths ko check kiya jaye ga

    //matrix input
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cout << "Enter 0 or 1 for A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    // matrix display
    cout << "\nThe initial matrix is:\n";
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    int sx, sy, dx, dy; // starting aur ending coordinates path find karke k liye 
    cout << "\nEnter start coordinates (x y): ";
    cin >> sx >> sy;
    cout << "Enter destination coordinates (x y): ";
    cin >> dx >> dy;


    // BFS wali logic 
    queue<pair<int, int> > q; //queue array ka pair like x aur y ka  
    vector<pair<int, int> > path; // path store krne k liye later to print path
    q.push({sx, sy}); //queue mein starting indexes push kardo
    visited[sx][sy] = true; //aur starting ko true kardo 
    
    bool found = false;

    while (!q.empty()) //jab tak queue empty na hojaye 
	 {
        int x = q.front().first; //particular coordinate like {0,0} ke x pehla 0 aur y dusra 0 x and y mein store karake pop kardo 
        int y = q.front().second;
        q.pop();

        path.push_back({x, y}); // joh bhi current cell mein mujood ho path mein add kardo 

        if (x == dx && y == dy) //agar sahi dest mil gayi hai toh
		{
            found = true; //found ko true karke nikal aao
            break;
        }

        for (int i = 0 ; i < 8 ; i++) //saari 8 possible directions mein move karsakte ho uper declares hain
		 {
            int newX = x + dirX[i]; //current direction aur index k hisab se new x aur y assign kardo 
            int newY = y + dirY[i];

            // simple condition for not out of bounds in matrix, visit bhi na huwa wa ho, 0 wali walkable path bhi ho 3 condition fulfill honi chahiye 
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && A[newX][newY] == 0) 
			{
                visited[newX][newY] = true; //visit karke queue mein push karte jayein
                q.push({newX, newY});
            }
        }
    }

    if (found) //agar dest mil gayi hai toh path exist karta hai
	 {
        cout << "\nPath exists using BFS and 8 directions!\n";
        cout << "Path used (i, j):\n";
        for (int i = 0; i < path.size(); i++) //paths k indexes print kardo 
		 { 
            cout << "(" << path[i].first << ", " << path[i].second << ")\n";
        }
    } else // nahi toh path nahi mila 
	{
        cout << "\nNo path found.\n";
    }

    return 0;
}
