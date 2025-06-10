#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

void Addnode(int val) {
    Node* ptr = new Node();
    ptr->data = val;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (head == NULL) {  // If list is empty, new node is both head and tail
        head = ptr;
		  tail=ptr;

    } else {
        tail->next = ptr;
        ptr->prev=tail;
        tail = ptr;
    }
}

void printlist() {
    Node* temp = head;
    cout << "The Doubly Linked List is:\t";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deleteNode(int keyval) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL && temp->data != keyval) 
	{
        temp = temp->next;
    }

    if (temp == NULL) {  // Key not found
        cout << keyval << " not found!" << endl;
        return;
    }

    if (temp == head) {  // Case: Delete head node
        head = head->next;
        if (head) 
		head->prev = NULL;
        else tail = NULL;  // If list becomes empty
    } 
    
    else if (temp == tail) {  // Case: Delete tail node
        tail = tail->prev;
        tail->next = NULL;
    } 
    else {  // Case: Delete a middle node
        temp->prev->next = temp->next; //explained in notebook 
        temp->next->prev = temp->prev;
    }

    delete temp;
}

int main() {
    int n, value,delKey;
    cout << "Enter the number of nodes you want in the Linked List:\t";
    cin >> n;

    for (int i = 0; i < n; i++) 
	{
        cout << "Enter the value of the nodes:\t";
        cin >> value;
        Addnode(value);
        printlist();
    }

    cout << "Enter the value of the node to delete:\t";
    cin >> delKey;
    deleteNode(delKey);
    printlist();

    return 0;
}

