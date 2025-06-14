#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Circular LL mein node insert karna (end par)
Node* insert(Node* head, int value) {
    Node* newNode = new Node(value);

    // Agar list khali hai to naya node khud ko hi point kare
    if (head == NULL) {
        newNode->next = newNode;  // circular
        return newNode;
    }

    // Warna last node tak jao
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    // naya node last ke baad lagao aur circular maintain karo
    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Function to split list into two halves
void splitList(Node* head, Node*& head1, Node*& head2) {
    if (head == NULL || head->next == head) {
        // Agar list empty ya sirf 1 node wali hai
        head1 = head;
        head2 = NULL;
        return;
    }

    // 2 pointers: slow 1 step, fast 2 steps
    Node* slow = head;
    Node* fast = head;

    // Jab tak fast circular complete nahi karta
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;        // 1 step
        fast = fast->next->next;  // 2 steps
    }

    // Agar even number of nodes hain to fast ko ek extra step do
    if (fast->next->next == head)
        fast = fast->next;

    // slow middle pe hai, split yahan se karo
    head1 = head;            // pehla half ka start
    head2 = slow->next;      // doosra half ka start

    // Pehle half ka last node ko head1 se connect karo (circular banane ke liye)
    slow->next = head1;

    // Doosre half ka last node fast hai, usko head2 se connect karo
    fast->next = head2;
}

// Print function
void printList(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(Back to " << head->data << ")" << endl;
}

// Main function
int main() {
    Node* head = NULL;
    int n, val;

    cout << "Enter the number of elements you want? ";
    cin >> n;

    cout << "\n Enter Values in Circular LL: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        head = insert(head, val);  // 
    }
     cout << "\n Original List: ";
     printList(head);
     
    // Split ke baad dono halves ko store karne ke liye do head pointers
    Node* head1 = NULL;
    Node* head2 = NULL;

    // List split karo
    splitList(head, head1, head2);

    // Print dono halves
    cout << "\n--- First Half ---\n";
    printList(head1);

    cout << "\n--- Second Half ---\n";
    printList(head2);

    return 0;
}

