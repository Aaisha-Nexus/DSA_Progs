#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;
//function to add node
void Addnode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList() {
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to swap two nodes for all cases ( if either node is head, adjancent nodes, internal nodes)
void swapNodes(int x, int y) {
    if (x == y) {
        cout << "Both nodes are the same, no swapping needed." << endl;
        return;
    }

    Node* prevX = NULL, *currX = head; //here currX is used to track the first X node which is current and similarly for Y
    Node* prevY = NULL, *currY = head; //the prevX and Y are used too track the 1 previous node of currX and Y for later swapping

    // Search for x
    while (currX != NULL && currX->data != x) {
        prevX = currX; //assign the current node to the prevX later for swapping
        currX = currX->next; //traverse to the next node until you find the particular node
    }

    // Search for y
    while (currY != NULL && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    // If either node is missing, return
    if (currX == NULL || currY == NULL) {
        cout << "One or both elements not found in the list." << endl;
        return;
    }

    // Handling adjacent nodes separately    like 1->2->3->4->5->NULL and if i want to swap adjancent 2(currX) and 3(currY) 1->3->2->4->5->NULL
    if (currX->next == currY) {  // X is before Y like 2 is before 3 
        currX->next = currY->next;  // then after swap it the link after 2 shall be of 4 like 2->4 so currX(2)->next = currY(3)->next which is 4
        currY->next = currX; // currY(3)->next now points to currX which is 2 so links becomes 3->2->4
        if (prevX != NULL) {  //if the prevX is not null then
            prevX->next = currY; //link the prevX(1) ka next pointer to currY(3) so link becomes 1->3
        } else {
            head = currY; //else if it was null and currX was head so now make 3 as new head
        }
    }
    else if (currY->next == currX) {  // Y is before X MIRROR CASE FOR Y SITUATION
        currY->next = currX->next;
        currX->next = currY;
        if (prevY != NULL) {
            prevY->next = currX;
        } else {
            head = currX;
        }
    }
    else {  // General case: Not adjacent(internal nodes)
        if (prevX != NULL) { //if the prevX is not null then
            prevX->next = currY;  //link the prevX(1) ka next pointer to currY(3) so link becomes 1->3
        } else {
            head = currY;//else if it was null and currX was head so now make 3 as new head
        }

        if (prevY != NULL) {
            prevY->next = currX;
        } else {
            head = currX;
        }
        //swapping pointers or links 
        Node* temp = currY->next; //save the node after currY to preserve the list from there like 1->2->3->4->5->null HERE SAVE 4 in temp as it is currY(3)->next
        currY->next = currX->next; // link after 3 now points to 2 so link becomes 3->2
        currX->next = temp; //after 2 it points back to temp which was 4 like 2->4
    }                       //so after swap becomes 1->3->2->4->5->NULL as (1->3) is already handled above

    cout << "Swapped " << x << " and " << y << " successfully!" << endl;
}

int main() {
    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        Addnode(value);
        printList();
    }

    int x, y;
    cout << "Enter two values to swap: ";
    cin >> x >> y;

    swapNodes(x, y);
    printList();

    return 0;
}

