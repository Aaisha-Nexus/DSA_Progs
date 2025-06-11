#include <iostream>
#include <queue>
using namespace std;

// Doubly Linked List ka node structure
struct DLLNode {
    int data;
    DLLNode* prev;  // Pichla node ka pointer (DLL ka key feature)
    DLLNode* next;  // Agla node ka pointer (DLL ka key feature)
    
    DLLNode(int val) : data(val), prev(NULL), next(NULL) {}  // Constructor
};

// Binary Tree ka node structure
struct BTNode {
    int data;
    BTNode* left;  // Left child ka pointer
    BTNode* right; // Right child ka pointer
    
    BTNode(int val) : data(val), left(NULL), right(NULL) {}  // Constructor
};

// DLL mein node insert karne ka function
DLLNode* insertDLL(DLLNode* head, int val) {
    DLLNode* node = new DLLNode(val);  // Naya node create karo
    if (!head) {  // Agar list khaali hai
        return node;  // Naya node hi head hoga
    }
    DLLNode* temp = head;
    while (temp->next) {  // Last node tak pohoncho
        temp = temp->next;
    }
    temp->next = node;  // Last node ka next pointer naya node ho jayega
    node->prev = temp;  // Naye node ka prev pointer previous node hoga
    return head;  // Updated head return karo
}

void printDLL(DLLNode* head) {
    cout << "The Doubly Linked List is:   ";
    DLLNode* temp = head;
    while (temp) {
        cout << temp->data << " <-> ";  // DLL format mein print
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


// DLL ko Binary Tree mein convert karne ka function
BTNode* convertDLLtoBT(DLLNode* head) {
    if (!head) return NULL;  // Agar DLL khaali hai to return NULL
    
    queue<BTNode*> q;  // Queue ka use karke Binary Tree banayenge
    BTNode* root = new BTNode(head->data);  // DLL ke pehle node ka data root hoga
    q.push(root);  // Root ko queue mein push karo
    head = head->next;  // DLL ka agla node
    while (head) {
        BTNode* parent = q.front();  // Parent node ko queue se nikaalo
        q.pop();  // Queue se front node nikaalo
        
        // Left child create karo
        BTNode* leftChild = new BTNode(head->data);
        parent->left = leftChild;  // Parent ka left child set karo
        q.push(leftChild);  // Left child ko queue mein push karo
        head = head->next;  // DLL ka next node
        
        // Right child create karo (agar next node hai)
        if (head) {
            BTNode* rightChild = new BTNode(head->data);
            parent->right = rightChild;  // Parent ka right child set karo
            q.push(rightChild);  // Right child ko queue mein push karo
            head = head->next;  // DLL ka next node
        }
    }
    return root;  // Binary Tree ka root return karo
}

// Binary Tree ka inorder traversal
void inorderBT(BTNode* root) {
    if (!root) return;
    inorderBT(root->left);  // Left subtree ka inorder
    cout << root->data << " ";  // Root node ka data print karo
    inorderBT(root->right);  // Right subtree ka inorder
}

// Main function
int main() {
    DLLNode* head = NULL;  // DLL ka head initialize karo
    int n, val;
    cout << "How many elements for DLL? ";  // User se node count pucho
    cin >> n;
    
    // DLL mein nodes insert karo
    cout << "Enter Values : ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        head = insertDLL(head, val);  // DLL mein naya node add karo
    }
    
    // DLL ko print karo
    printDLL(head);


    // DLL ko Binary Tree mein convert karo
    BTNode* root = convertDLLtoBT(head);
    cout << "Constructed Binary Tree's Inorder traversal: ";
    inorderBT(root);  // Constructed Binary Tree ka inorder traversal print karo
    cout << endl;

    return 0;
}

