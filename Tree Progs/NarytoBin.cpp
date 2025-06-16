#include <iostream>
using namespace std;


// Har node ka data hai, aur firstChild (pehla bachcha) aur nextSibling (agla bhai/bahen) pointers hain.
struct NaryNode {
    int data;
    NaryNode* firstChild, * nextSibling;
    NaryNode(int val) : data(val), firstChild(NULL), nextSibling(NULL) {} //shuru mein sab NULL hain
};


// bin tree struct
struct BinaryNode {
    int data;
    BinaryNode* left, * right;
    BinaryNode(int val) : data(val), left(NULL), right(NULL) {}
};

//recursively call this function to convert into bin tree
BinaryNode* convert(NaryNode* root) //nary ka root pass karein
{
    // Agar root NULL hai, toh return NULL, yani agar koi node nahi hai toh kuch bhi return nahi hoga
    if (!root) return NULL;
    
    // N-ary node ka ek corresponding binary node banaya
    BinaryNode* bin = new BinaryNode(root->data);
    
    // Sabse pehle hum firstChild ko left banate hain, yeh N-ary ka pehla child hamesha binary tree mein left child hoga
    bin->left = convert(root->firstChild);
    
    // Ab nextSibling ko right bana denge, yeh N-ary tree ka agla sibling binary tree mein right child hoga
    bin->right = convert(root->nextSibling);
    
    // Binary node ko return karte hain
    return bin;
}

// Binary tree ka level-order traversal print karne ka function
void printBinaryTree(BinaryNode* root) {
    if (!root) return;  // Agar root NULL hai toh kuch nahi karenge
    
    queue<BinaryNode*> q;  // Queue ka use karenge level-order traversal ke liye
    q.push(root);  // Root ko queue mein daalenge
    
    // Jab tak queue khali na ho, nodes ko process karte jayenge
    while (!q.empty()) {
        BinaryNode* curr = q.front(); 
		q.pop();  // Queue se ek node uthate hain
        cout << curr->data << " ";  // Node ka data print karte hain
        
        // Agar left child hai toh usay queue mein daalte hain
        if (curr->left) 
		q.push(curr->left);
        
        // Agar right child hai toh usay queue mein daalte hain
        if (curr->right)
		 q.push(curr->right);
    }
    cout << endl; 
}

int main() {
    // Manually create N-ary tree
    NaryNode* root = new NaryNode(1);  // Root node bana rahe hain, data 1
    root->firstChild = new NaryNode(2);  // Root ka pehla child bana rahe hain
    root->firstChild->nextSibling = new NaryNode(3);  // Root ka second sibling (3) bana rahe hain
    root->firstChild->nextSibling->nextSibling = new NaryNode(4);  // Root ka third sibling (4)
    root->firstChild->firstChild = new NaryNode(5);  // First child (2) ka ek aur child (5)

    // call convert function
    BinaryNode* binaryTree = convert(root);
    
    // print level order traversal for confirmation
    printBinaryTree(binaryTree);
    
    return 0;
}

