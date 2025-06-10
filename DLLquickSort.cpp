#include <iostream> //DOUBLYLINKEDLIST Quicksort
using namespace std;

struct Node {
    int data;
    Node* next;  
    Node* prev; // Pointer to the previous node because of the doublylist now
    int index; //
};

Node* head = NULL; 
Node* tail = NULL; // Keeping track of the last node for easier insertion

int totalNodes = 0; // Global variable total nodes count karne k liye joh counter ko use karega 
void Addnode(int val) {
    Node* ptr = new Node(); // Create a new node
    ptr->data = val;
    ptr->next = NULL; // Initially, it has no next node
    ptr->prev = NULL; //Initially, it has no previous node

    if (head == NULL)
	 { // If the list is empty
        head = ptr;
        tail = ptr; // First node is both head and tail
    } else {
        tail->next = ptr; // Link the current last node's next pointer to new node
        ptr->prev = tail; // Link new node back to second (previous) last node
        tail = ptr; // Update tail to new node
    }
    static int counter = 0;
	ptr->index = counter++;
	totalNodes= counter;

}

//function to swap the nodes
void swapData(Node* a, Node* b) {
    int temp = a->data; // a ka data temp mein daldo
    a->data = b->data; //b ka data a mein daldo
    b->data = temp; //aur temp (jisme pehle ka a ka data hai) woh b mein daldo
}

//function to set pivot and partition the list
Node* partition(Node* start, Node* end) 
{
    int pivot = end->data; //end the of list (akhri node) ko pivot bana do
    Node* i = start->prev; //i ko left se ek pehle (jaise array mein array se bhi pehle) wahan point karado (NULL hoga pehle iteration mein)

    Node* j = start; //j pehle node of the list se start karo 
    while (j != end) //jab tak j end yani pivot tak na pohonch jaye 
	 {
        if (j->data < pivot) //compare karo kya j ka data pivot se chota hai 
		{
            if (i == NULL) //Agar i abhi NULL hai (pehla small element mila hai)
			{
                i = start; // i ko start pe le jao
            } else
			 {
                i = i->next; //warna i ko ek aagey le jao similar to i++
            }
            swapData(i, j); //agar chota hai toh swap kardo i aur j ko 
        }
        j = j->next; //j jo bhi ek aagey barha do like j++
    }

	// Ab pivot ko correct jagah pe shift karna hai (i ke baad)
    if (i == NULL) 
	{
        i = start;
    } else
	 {
        i = i->next;
    }

    swapData(i, end); //simialr to swap(arr, i+1, right) last element kp i+1 se swap kardo 
    return i; //aur naye i (pivot) ko return kardo 
}

//main quicksort which will be called 
void quickSort(Node* start, Node* end)
 {
    if (start != NULL && end != NULL && start != end && start != end->next) //ab tak start aur end valid, distinct, aur sorted hone qabil hain 
	{
        Node* pivot = partition(start, end); //partition call karo aur pivot lo
        quickSort(start, pivot->prev); //recursively left sort karo
        quickSort(pivot->next, end); //recursively right sort kardo
    }
}

//function to print the list
void printlist() {
    Node* temp = head;
    cout << "The Doubly Linked List is:	";
    while (temp != NULL) {
        cout << temp->data << " <-> "; //helps visualize doubly
        temp = temp->next;
    }
    cout << "NULL" << endl;
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
    cout << "\n****After Applying Quicksort*****	" << endl;
    quickSort(head,tail); //this head and tail goes as start and end 
    printlist();
    
    cout << "Total number of nodes are: " << totalNodes << endl; //display total count using counter
    
    return 0;
}
