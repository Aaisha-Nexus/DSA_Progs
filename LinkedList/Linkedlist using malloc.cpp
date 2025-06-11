#include <iostream>
#include <cstdlib> // for malloc and free
using namespace std;

struct Node {
    int data;      // For storing data value
    Node* next;    // Pointer to hold the memory address of the next node
};

Node* head = NULL; // Initialize head with nullptr

void addNode(int value) {  // Function to add a node to the linked list
    Node* ptr = (Node*)malloc(sizeof(Node)); 
    if (!ptr) {  
        cout << "malloc function failed" << endl;
        exit(1);
    }

    ptr->data = value;
    ptr->next = NULL;  

    if (head == NULL) {  // Fix: Use == instead of =
        head = ptr;  // If head is empty, make new node the head
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

void printList() {  // Function to print the list
    Node* temp = head;
    
    cout << "Elements in the linked list: ";
    
    while (temp != NULL) {  // Fix: Use nullptr instead of null
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void freeList() {  // Function to free memory
    Node* temp = head;
    
    while (temp != NULL) {  // Fix: Use nullptr instead of null
        Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    head = NULL;
}

int main() {
    // Add nodes to the list
    addNode(10);
    addNode(20);
    addNode(30);
    addNode(40);

    // Print the list
    printList();

    // Free the allocated memory
   free(head);

    return 0;
}

