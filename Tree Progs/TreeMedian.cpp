#include <iostream>
#include <algorithm> // for sort
#include <queue> // for queue to traverse the tree
#include <vector> // for using vectors
using namespace std;

// Struct for a node in the 4-ary tree
struct Node {
    int data;
    Node* C1;
    Node* C2;
    Node* C3;
    Node* C4;

    // New node banate waqt saare children NULL honge by this constructor 
    Node(int val) {
    data = val;
    C1 = NULL;
    C2 = NULL;
    C3 = NULL;
    C4 = NULL;
}

};

//to calc the median 
int getMedian(const vector<int>& arr) 
{
    int size = arr.size();
    vector<int> sortedArr = arr;  // Create a copy to sort
    sort(sortedArr.begin(), sortedArr.end()); // Sort array to find median
    if (size % 2 == 0) 
    {
        return (sortedArr[size / 2 - 1] + sortedArr[size / 2]) / 2.0;  //  agar size even ho to beech ke 2 elements ka average
    } 
    else 
    {
        return sortedArr[size / 2]; //for odd simply size/2
    }
}

//function to divide array in 4 parts (subtrees)
void divideArr(const vector<int>& arr, int root, vector<int>& S1, vector<int>& S2, vector<int>& S3, vector<int>& S4) //here pass by reference ta ke original mein bhi changes reflect hojayein
{
    for (int i = 0; i < arr.size(); i++) // loop through the sorted array
    {
        if (arr[i] < root / 2)  //divisions according to the condistion provided 
        {
            S1.push_back(arr[i]); // sabse choti values
        }
        else if (arr[i] >= (2 * root) / 3 && arr[i] < (3 * root) / 2) 
        {
            S2.push_back(arr[i]); // thodi badi values
        }
        else if (arr[i] >= (3 * root) / 2 && arr[i] < 2 * root) 
        {
            S3.push_back(arr[i]); // aur thodi badi values
        }
        else if (arr[i] >= 2 * root) 
        {
            S4.push_back(arr[i]); //sabse bari values 
        }
    }
}

// Recursive function to build the 4-ary tree
Node* buildTree(vector<int>& arr) {
    if (arr.empty()) return NULL; // agar array khaali ho to NULL return karo

    int rootVal = getMedian(arr); // median ko root banate hain
    Node* root = new Node(rootVal); // root new node ban gaya

    vector<int> S1, S2, S3, S4;
    divideArr(arr, rootVal, S1, S2, S3, S4); // array ko 4 parts mein divide kar diya

    //har part ke liye recursively subtree build karenge
    root->C1 = buildTree(S1);
    root->C2 = buildTree(S2);
    root->C3 = buildTree(S3);
    root->C4 = buildTree(S4);

    return root; // pura tree return hoga
}

// Simplified function to print the tree level-wise
void printTree(Node* root) {
    if (root==NULL) return; // agar tree khaali ho to kuch mat karo

    queue<Node*> q; //queue banaya 
    q.push(root); // pehle root daala queue mein

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " "; // Print current node

        // agar children exist karte hain to unko queue mein daal do
        if (curr->C1) q.push(curr->C1);
        if (curr->C2) q.push(curr->C2);
        if (curr->C3) q.push(curr->C3);
        if (curr->C4) q.push(curr->C4);
    }
    cout << endl;
}

// Function to calculate the height of the tree
int getHeight(Node* root) {
    if (root==NULL) return 0; // agar node NULL ho to height 0

    // har child ka height nikaalo 
    int h1 = getHeight(root->C1);
    int h2 = getHeight(root->C2);
    int h3 = getHeight(root->C3);
    int h4 = getHeight(root->C4);
    
	int maxHeight = max(max(h1, h2), max(h3, h4)); //aur sabse bada wala choose karo
	return 1 + maxHeight; // current node ke liye +1

}

// Function to print level and height of each node
void printLevelAndHeight(Node* root, int level) {
    if (root==NULL) return; // If node is NULL, do nothing

    // Print node value, level, and height
    cout << "Node: " << root->data << ", Level: " << level << ", Height: " << getHeight(root) - 1 << endl;

     // children ke liye recursion lagao level + 1 ke saath
    printLevelAndHeight(root->C1, level + 1);
    printLevelAndHeight(root->C2, level + 1);
    printLevelAndHeight(root->C3, level + 1);
    printLevelAndHeight(root->C4, level + 1);
}

int main() {
    int size;
    cout << "Enter the size:\t";
    cin >> size;

    vector<int> arr(size);  // Using vector instead of raw array
    cout << "Enter the elements:\t";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "\nArray is:\t";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nThe median is:\t";
    int median = getMedian(arr);
    cout << median << endl;


    Node* root = buildTree(arr); // Build the 4-ary tree
    cout << "Tree Level-wise: ";

    printTree(root); // Print tree

	cout << "\n\nNode Levels and Heights:\n";
	printLevelAndHeight(root, 0);
    return 0;
}

