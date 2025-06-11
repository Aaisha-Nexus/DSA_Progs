#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Normal insertion at end (preserves order)
void insert(int val) {
    Node* ptr = new Node();
    ptr->data = val;
    ptr->next = NULL;

    if (head == NULL) {
        head = ptr;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

// Reverse the list and return new head
Node* reverseList(Node* node) {
    Node* prev = NULL;
    Node* curr = node;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Compare two linked lists
bool isEqual(Node* a, Node* b) {
    while (a != NULL && b != NULL) {
        if (a->data != b->data)
            return false;
        a = a->next;
        b = b->next;
    }
    return (a == NULL && b == NULL); // Both must reach NULL
}

// Make a copy of the list
Node* copyList(Node* node) {
    if (node == NULL) return NULL;
    Node* newHead = new Node{node->data, NULL};
    Node* curr = newHead;
    node = node->next;

    while (node != NULL) {
        curr->next = new Node{node->data, NULL};
        curr = curr->next;
        node = node->next;
    }
    return newHead;
}

// Print the list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        insert(val);
    }

    cout << "\nOriginal List: ";
    printList(head);

    Node* copied = copyList(head);
    Node* reversed = reverseList(copied);

    cout << "Reversed Copy: ";
    printList(reversed);

    if (isEqual(head, reversed)) {
        cout << "\n The linked list is a palindrome." << endl;
    } else {
        cout << "\n The linked list is NOT a palindrome." << endl;
    }

    return 0;
}

