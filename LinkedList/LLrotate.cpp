#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};


Node* head = NULL;

// Function to insert node at end
void insert(int val) {
    Node* newNode = new Node();   // Naya node banaya
    newNode->data = val;          // Data set kiya
    newNode->next = NULL;         // Next NULL rakha

    if (head == NULL) {
        head = newNode;           // Agar list khaali hai to head newNode ban gaya
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;    // Last node tak gaye
        }
        temp->next = newNode;     // Last node ka next newNode ban gaya
    }
}

// Function to rotate list left by k nodes
void rotateLeft(int k) 
{
    for (int i = 0; i < k; i++) //k times pehle node utha k last mein daaldo
	{
        if (head == NULL || head->next == NULL) return;  // Agar 0 ya 1 node hai to kuch mat karo

        Node* first = head;         // First node ko hold kiya
        head = head->next;          // Head ko next node par le aaye
        first->next = NULL;         // Pehle node ka next NULL kar diya

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;      // List ke end tak gaye
        }
        temp->next = first;         // End par first node ko jod diya
    }
}

// Display function
void display(Node* node) {
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int n, val, k;
    cout << "Kitne elements dalna chahte ho? ";
    cin >> n;

    cout << "Values do: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(val);  // List mein value insert kar rahe hain
    }

    cout << "Kitne elements se rotate karna hai? ";
    cin >> k;

    cout << "Original List: ";
    display(head);

    // Rotate list
    rotateLeft(k);

    cout << "Rotated List: ";
    display(head);

    return 0;
}

