#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void addnode(int n, int pos) {
    Node* newnode = new Node();
    newnode->data = n;
    newnode->next = NULL;

    if (head == NULL || pos == 1) {  // Case: Insert at head
        newnode->next = head;
        head = newnode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;  // Move to (pos-1)th node
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void insertafter(int key, int newvalue) {
    Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Key not found!\n";
        return;
    }

    Node* newnode = new Node();
    newnode->data = newvalue;
    newnode->next = temp->next;
    temp->next = newnode;
}

void printlist() {
    Node* temp = head;
    cout << "The linked list is:\t";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void freelist() {
    Node* temp = head;
    while (temp != NULL) {
        Node* nextnode = temp->next;
        delete temp;
        temp = nextnode;
    }
    head = NULL;
}

int main() {
    int nodes, val, pos, key, newnodeval;

    cout << "Enter the number of nodes you want in the linked list:\t";
    cin >> nodes;

    for (int i = 0; i < nodes; i++) {
        cout << "Enter the value for node " << i + 1 << ":\t";
        cin >> val;
        cout << "Enter the position you want to insert the node at:\t";
        cin >> pos;
        addnode(val, pos);
        printlist();
        
    }


    cout << "Enter the node after which you want to insert a new node:\t";
    cin >> key;

    cout << "Enter the value of the new node:\t";
    cin >> newnodeval;
    insertafter(key, newnodeval);

    printlist();
    freelist();
    return 0;
}

