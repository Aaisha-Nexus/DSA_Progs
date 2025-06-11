#include<iostream>
#include<cstdlib>
using namespace std;

struct Node{ 
	int data; // |data space|
	Node* next; // [ data | pointer* to next ]
};
 
 Node* head = NULL;  //initialise head to null HEAD->[]
 
 void addnode(int value) //function to add node
 {
 	Node* ptr = new Node(); //creation of new node Ptr->[]
	 
	 ptr->data = value; //points to the data part of the node
	 ptr->next = NULL; //the address part points to NULL
	 
	
	 if(head==NULL) //if head is NULL means if there is no node in the list then
	 {
	 	head=ptr; //assign the newly created node as the head
	 }
	 else{ //otherwise if there is a node then 
	 	Node* temp= head;   //make a temporary node and assign it the value of head so the head value gets saved 
	 	 while(temp->next!=NULL) /*now easily manipulate the linkedlist using temp node 
		                           keep the while loop going like keep traversing until
								   you find the last node which means its "next" value points to NULL*/ 
	 	 {
	 	 	temp=temp->next;      //till then keep going traversing like [1]->[2]->[3]->NULL
	 	 	                                                        //    ^    ^    ^    ^ ----^
		  }
		  temp->next=ptr;  // Link the last node's next pointer to the newly created node
		                // now it looks like then [1]->[2]->[3]->[4]->
	 }
	 	 
 }
 
 void printlist() //function to print the list
 {
 	Node* temp=head; //again saving the head node for future manipulation
 	cout<< "The linkedlist is:\t";
 	while(temp!=NULL) //traverse 
 	{
 		
 		cout<< temp->data << "->"; //print the data part of the list [1]->[2]->[3]->[4]->
 		temp=temp->next;  // and then keep traversing till end 
	 }
	  cout << "NULL" << endl; //after the end print NULL to mark the end of the list [1]->[2]->[3]->[4]->NULL

 	
 }
 
 void freelist() //function to free the memory
 {
 	Node* temp=head;
 	while(temp!=NULL)
 	{
 		Node* nextnode = temp->next; // Store the next node's address before deleting the current node
 		 delete temp; // Delete the current node and move to the next node
 		 temp= nextnode; //inside the temp now save the adress of the nextnode
	 }
	 head=NULL; // After freeing all nodes, set head to NULL to indicate an empty list
 }
 
 int main()
 {
 	int n , val;
 	cout<< "Enter the number of nodes you want in a Linkedlist:\t";
 	cin>> n;
 	for(int i=0;i<n;i++)
 	{
 		cout<< "Enter the value in a linkedlist:\t";
 		cin>> val;
 		addnode(val); //to add the numbers in the list
 		printlist(); //to print the list after adding each node
	 }
	 
	 freelist(); //to free the memory
 	return 0;
 }































/* SAME CODE USING MALLOC
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
	int n,x;
    cout<< "enter the total nodes to add in the Linkedlist:\t";
    cin>> n;
    for(int i=0;i<n;i++)
    {
    	cout<< "enter the node:\t";
    	cin>> x;
    	addNode(x);
    	printList();
	}
    
    // Free the allocated memory
   freeList();

    return 0;
} */

