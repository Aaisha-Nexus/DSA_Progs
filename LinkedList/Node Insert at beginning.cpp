#include<iostream>
#include<cstdlib>
using namespace std;

struct Node
{
	int data;
	Node* next;
	
};
 Node* head = NULL;

 void addnode(int value) 	// no need to traverse the entire list to add bcz u are adding in beginning 
 {
 	Node* ptr= new Node(); //create a new node
 						
 	ptr->data = value;		   // point to assign the value to the data part of the node  
 	ptr->next = head;			// now here instead of traversing, point or link the adress part of the node to the head 
 	head=ptr;		          /* head -> [1 | NULL]  (List contains only one node)
								 ptr -> [2 | next]   (New node created)
								ptr->next = head   (New node points to old head) 
								head = ptr(Head now points to the new node)  head-> [2 | next] -> [1 | NULL] naya node head ban 
								gaya aur naye node ka next pointer "purane head" ko point kar raha so woh ab second ya baad mein chala gaya  */
 }
 
 void printlist()  //same print function
 {
 	Node* temp= head;
 	cout<< "the linkedlist is:\t";
 	while(temp!=NULL)
 	{
 		cout<< temp->data << "->";
 		temp=temp->next;
	 }
	 cout << "NULL" << endl;
 }

 void freelist() //same free memory function
 {
 	Node* temp=head;
 	while(temp!=NULL)
 	{
 		Node* nextnode = temp->next;
 		delete temp;
 		temp= nextnode;
	 }
	 head=NULL;
 }
 
int search()
{
    int key;
    cout << "Enter the key to search:\t";
    cin >> key;
   
    Node* temp = head;
    while (temp != NULL)  // Check the current node as well
    {
        if (temp->data == key)
        {
            cout << "Value found: " << key << endl;
            return 1;  // Return 1 for found
        }
        temp = temp->next;  // Move to the next node
    }

    cout << "Value not found." << endl;
    return 0;  // Return 0 for not found
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
	 search();
	 
	 freelist(); //to free the memory
 	return 0;
 }











/* SAME CODE USING MALLOC
#include<iostream> //linkedlist to insert a node at beginning using malloc
#include<cstdlib>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head = NULL;
void insertnode(int x)
 {
 	Node* ptr = (Node*)malloc(sizeof(Node));
 	if(!ptr)
 	{
 		cout<< "malloc failed" << endl;
 		exit(1);
	 }
	 
	 ptr->data=x;
	 ptr->next=head;
	 head=ptr;
}

  void printlist()
  {
  	Node* temp= head;
  		cout<< "the list is: ";
  		while(temp!=NULL)
  		{
  			cout<< temp->data << "->";
  			temp=temp->next;
		  }
		  cout<< "NULL" << endl;
}
  
void freelist()
{
	Node* temp=head;
	while(temp!=NULL)
	{
		Node* nextnode= temp->next;
		free(temp);
		temp=nextnode;
	}
	head=NULL;
	
}w

int main()
{
	int n,x;
	cout<< "enter total elements to insert in the Linekdlist:\t";
	cin>> n;
	for(int i=0;i<n;i++)
	{
		cout<< "enter the node:\t"; 
		cin>> x;
		cout<< endl;
		insertnode(x);
		printlist();
	}
	freelist();
	return 0;
} */

 
