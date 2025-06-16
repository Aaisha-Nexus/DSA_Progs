#include<iostream> //DYNAMIC STACK IMPLEMENTATION
using namespace std;

// Node creation
struct Node {
    int data;
    Node* next;
};

// Top pointer for stack
Node* top = NULL; //just like it was top=-1

// Function to check if the stack is empty
bool IsEmpty() {
    return top == NULL;
}


// Function to display the stack
void DisplayStack() {
    if (IsEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Current Stack: [ ";
    Node* temp = top;
    while (temp!=NULL) {
        cout << temp->data << " "; //diplay values 
        temp = temp->next; //traverse the list
    }
    cout << "]" << endl;
}  

// Function to push an element onto the stack
void Push() {
    int val;
    cout << "Enter the value you want to push?:\t";
    cin >> val;
    Node* newNode = new Node(); //dynamically creating newnode
    newNode->data = val; //getting the value in data part of the node
    newNode->next = top; //Connects the new node to the current top node. EXAMPLE : top -> [20 | *] -> [10 | NULL] here the newnode->next means 20 k next ko =top means 10 assign kardo
    top = newNode; //make the newnode the new top now  HERE top -> [20 | *] // now the 20 becomes current top
    cout << val << " pushed into stack!" << endl;
    DisplayStack();
}

// Function to pop an element from the stack
void Pop() {
    if (top == NULL) {
        cout << "Stack Underflow! No elements to pop." << endl;
        return;
    }
    cout << "Popped element: " << top->data << endl;
    Node* temp = top; //store the current top
    top = top->next; //Moves top to the next node (removing the topmost one) EXAMPLE BEFORE POP  top -> [20 | *] -> [10 | NULL] (its pointing the top->next which is 10 as new top
    delete temp; //delete the old top node HERE AFTER POP top -> [10 | NULL] After deleting 20 it looks like this 10 becomes new top 
    DisplayStack();
}

// Function to return the top element of the stack
int Peek() {
    if (top == NULL) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return top->data; //just returns the data value from top peeking 
}


// Function to display menu
void Menu() {
    cout << "\nStack Menu:\n"
         << "1) Push\n"
         << "2) Pop\n"
         << "3) Peek\n"
         << "4) Check if Empty\n"
         << "5) Display Stack\n"
         << "6) Exit the program\n";
}

// Main function
int main() {
    cout << "WELCOME TO STACK IMPLEMENTATION USING LINKED LIST\t" << endl;
    int option;
    do {
        Menu();
        cout << "Choose the action you want to perform (1-6):\t";
        cin >> option;
        switch (option) {
            case 1:
                Push();
                break;
            case 2:
                Pop();
                break;
            case 3:
                cout << "Top element: " << Peek() << endl;
                break;
            case 4:
                if(IsEmpty())
			{
				cout<< "Stack is Empty!"<< endl;
			}
		    else { 
		        cout<< "Stack is NOT Empty!" << endl;
			}
			break;
            case 5:
                DisplayStack();
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid option! Choose again." << endl;
        }
    } while (option != 6);
    return 0;
}

