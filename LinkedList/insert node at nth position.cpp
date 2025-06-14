#include<iostream>
#include<cstdlib>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head = NULL;

void addnode(int n, int position)
{
	Node* newnode = new Node();
	
	newnode->data= n;
	newnode->next = NULL;
	
	 if(head==NULL) //case 1 : if head is NULL means if there is no node in the list then
	 {
	 	head=newnode;
		 return; //assign the newly created node as the head
	 }
	 
	 if(position==1) //case 2: if position starts at head
	 {
	 	newnode->next=head;
	 	head=newnode;
	 	return;
	 }
	 /* REPLACEMENT FOR ABOVE
	  if (head == NULL || position == 1) {  // Case: Insert at head
        newnode->next = head;
        head = newnode;
        return;
    }*/ 
	 
	 
	//case 3: to insert at n position
	/*building links explained above
	 	first pointer of temp(A) and its temp->next is (B)
	 	then new (X) nodes get created and its next pointer points to B so a half link 
	 	establishes as (X)->(B) then in next line the temp->next link gets reassigned
	 	to newnode which is (X) and hence completes the linking as [A] -> [X] -> [B] -> [C] -> [D]*/
	 Node* temp=head;
	 for(int i=1; i<position-1 && temp->next!=NULL; i++) //reach till position "i= 1 in a linked list means head (the first node), not an index"
	 {
	 	temp=temp->next; //traverse
	 }
	 	
	 	newnode->next = temp->next; //[X] -> [B] train link analogy 
	 	temp->next= newnode; //[A] -> [X] -> [B] -> [C] -> [D] links completes 
	 
	
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
	int nodes, num, pos;
	cout<< "enter the number of nodes u want to enter:\t";
	cin>> nodes;
	for(int i=0; i<nodes; i++)
	{
		cout<< "enter the number you want in Linkedlist:\t";
	cin>> num;
	cout<< "enter the position you want the node at:\t";
	cin>> pos;
	addnode(num,pos);
	printlist();
	}
	
	
	freelist();
 return 0;
}


