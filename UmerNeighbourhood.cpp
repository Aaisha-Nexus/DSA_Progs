#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dirX[] = {0, 1, 0, -1}; // 4 valid directions right, down, left, up acc to x and y coordinates
int dirY[] = {1, 0, -1, 0};

int main() 
{
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    char A[n][m]; //2d array for umer neighbourhood
    bool visited[n][m] = {false};

	int sx, sy, dx, dy; //sx and sy source ko represent kar rahe and dx dy destination ko
	
    cout << "\nEnter the matrix (use 'U', 'H', 'X', and '-' for path):\n";
    for (int i = 0 ; i < n ; i++) 
	{
        for (int j = 0 ; j < m ; j++)
		 {
            cin >> ws; //whitespaces ko ignore krdo
            cin.get(A[i][j]);

            if (A[i][j] == 'U')  //Here umer is the source 
			{
                sx = i;
                sy = j;
            } else if (A[i][j] == 'H') //house is the destination to reach
			{
                dx = i;
                dy = j;
            }
        }
    }

    //Display matrix 
    cout << "\nGrid is:\n";
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) 
		{
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

	
    queue<pair<int, int> > q; //x and y ka pair queue mein store hoga
    vector<pair<int, int> > path; //path store krne k liye 
    q.push({sx, sy}); //starting posiiton ko queue mein push karke
    visited[sx][sy] = true; //iske visited ko true kardo

    int steps = 0; //steps ka counter
    bool found = false;

	//bfs wali logic 
while (!q.empty() && !found) //jab tak queue khali na hojaye aur destination na mil jaye tab tak chalo
{
    int sizeofqueue = q.size(); //ek level pe jitne elements hain unki count jaise hum normal bfs mein adjanceny list krte the

    for (int i = 0; i < sizeofqueue ; i++) // same kaam as while (sz--) but in a noob-style for loop
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

        for (int i = 0 ; i < 4 ; i++) //4 possible paths ko explore karne k liye 
        {
            int newX = x + dirX[i]; //current direction aur index k hisab se new x aur y assign kardo 
            int newY = y + dirY[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m && //simple condition for not out of bounds in matrix
                !visited[newX][newY] && //aur woh cell visit na huwa ho
                (A[newX][newY] == '-' || A[newX][newY] == 'H'))  //aur walkable path bus - hosakta hai ya H hosakta hai AGAR YEH 3 CONDITION FULFILL HAIN TOH 
            {
                visited[newX][newY] = true; //visited ko true kardo
                q.push({newX, newY});
            }
        } 
    }

    if (!found) steps++; //agar destination nahi mili toh poora ek level explore karke steps ko increase kardo bfs is level by level 
}


    if (found) //agar path mil gaya hai toh 
	{
        cout << "\nMinimum steps to reach home: " << steps << endl; //steps print kara do 
        cout << "\nPath used (i, j):\n"; //aur path using indexes print karado
        for (int i = 0; i < path.size(); i++) 
		{ // Output the path
            cout << "(" << path[i].first << ", " << path[i].second << ")\n";
        }
    } else // nahi toh path nahi mila 
	 {
        cout << "\nUmer cannot reach home. Output: -1\n";
    }

    return 0;
}
