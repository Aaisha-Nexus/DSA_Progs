#include <iostream>
using namespace std;

// Binary Tree ka node structure
struct BTNode {
    int data;
    BTNode* left;  // Left child ka pointer
    BTNode* right; // Right child ka pointer
    
    BTNode(int val) : data(val), left(NULL), right(NULL) {}  // Constructor
};

// Doubly Linked List ka node structure
struct DLLNode {
    int data;
    DLLNode* prev;  // Previous pointer
    DLLNode* next;  // Next pointer
    
    DLLNode(int val) : data(val), prev(NULL), next(NULL) {}  // Constructor
};


DLLNode* dllHead = NULL;  // DLL ka head
DLLNode* dllPrev = NULL;  // Previous pointer


// Recursive function to convert Binary Tree ko DLL mein
void BTtoDLL(BTNode* root) 
{
    if (!root) return;  // Agar root NULL hai to kuch na karo
    BTtoDLL(root->left);  // Left subtree ko convert karo
    
    if (!dllPrev) {  // Agar DLL khaali hai
        dllHead = new DLLNode(root->data);  // Pehla node set karo
        dllPrev = dllHead;  // Pehle node ko prev set karo
    } else {  
        DLLNode* newNode = new DLLNode(root->data);  // Naya DLL node banao
        dllPrev->next = newNode;  // Previous node ka next new node ho
        newNode->prev = dllPrev;  // Naya node ka prev previous node ho
        dllPrev = newNode;  // Naya node ko prev banado
    }
    
    BTtoDLL(root->right);  // Right subtree ko convert karo
}

void printTree(BTNode* root, int space = 0, int gap = 6) {
    if (root == NULL) return;
    
    space += gap;
    printTree(root->right, space); // Right child first
    
    cout << string(space, ' ') << root->data << endl; // Print current node with spacing
    
    printTree(root->left, space); // Left child
}

// Main function to demonstrate Binary Tree to DLL conversion
int main() 
{
    // Manually creating Binary Tree
    BTNode* root = new BTNode(1);
    root->left = new BTNode(2);
    root->right = new BTNode(3);
    root->left->left = new BTNode(4);
    root->left->right = new BTNode(5);

    // Print the Binary Tree before conversion
    cout << "Binary Tree structure (sideways):\n";
    printTree(root);
    cout << endl;

    // Convert to DLL
    BTtoDLL(root);

    // Print DLL
    cout << "Converted DLL ke elements: ";
    DLLNode* temp = dllHead;
    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    return 0;
}

