#include <iostream> //DOUBLYLINKEDLIST PROGRAM
using namespace std;

struct Node {
    int data;
    Node* next;  
    Node* prev; // Pointer to the previous node because of the doublylist now
};

Node* head = NULL; 
Node* tail = NULL; // Keeping track of the last node for easier insertion

void Addnode(int val) {
    Node* ptr = new Node(); // Create a new node
    ptr->data = val;
    ptr->next = NULL; // Initially, it has no next node
    ptr->prev = NULL; //Initially, it has no previous node

    if (head == NULL) { // If the list is empty
        head = ptr;
        tail = ptr; // First node is both head and tail
    } 
	else 
	{
        tail->next = ptr; // Link the current last node's next pointer to new node
        ptr->prev = tail; // Link new node back to second (previous) last node
        tail = ptr; // Update tail to new node
    }
}

void printlist() {
    Node* temp = head;
    cout << "The Doubly Linked List is:	";
    while (temp != NULL) {
        cout << temp->data << " <-> "; //helps visualize doubly
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void search(int keyval) { //searching in doublyLL
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == keyval) {
            cout << keyval << " found!" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << keyval << " not found!" << endl;
}

int main() {
    int n, value, key;
    cout << "Enter the number of nodes you want in the Doubly Linked List:	";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter the value of the node:	";
        cin >> value;
        Addnode(value);
        printlist();
    }
    cout << "Enter the key you want to search:	";
    cin >> key;
    search(key);
    return 0;
}

