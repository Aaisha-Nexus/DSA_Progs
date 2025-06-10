#include<iostream>
#include<cstdlib>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head = NULL;

void Addnode(int val)
{
	Node* temp = head;
	Node* ptr = new Node();
	//for circular linkedlist
	 ptr->data=val;
	 if(head==NULL) //if head was null then make a newnode as head and its next will also point to head itself because it is a circular linkedlist
	 
	 {
	 	head=ptr;
	 	ptr->next=head; //head point itself back after adding first node because it is a circular linkedlist
	 }
	 
	else {
	 Node* temp = head;
	   while(temp->next!=head) //loop till head->next is not equal to head means it will traverse till it reaches back to head
	    {
	    	temp=temp->next;
		}
		temp->next=ptr; //place the node at the end of the traversal
		ptr->next=head; //and then link the newly added node back to the end to maintain circularity
	 }
}

void printlist()
{
	Node* temp=head;
	cout<< "The circular Linkedlist is:\t";
	do
	{
		cout<< temp->data << "->";
		temp=temp->next;
	}while(temp!=head);
	cout<< "Back to head" << endl;
}

void search( int keyval)
{
	bool flag=false;
	Node* temp=head;
	do{
	if(temp->data==keyval)
	{
		cout<< keyval << " found! " << endl;
		flag=true;
		return;
	}
	temp=temp->next;
}while(temp!=head);
cout<< keyval << " not found! " << endl;
}

int main()
{
	int n,value,key;
	cout<< "Enter the number of nodes you want in Linkedlist:\t";
	cin>> n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the value of the nodes:\t";
		cin>> value;
		Addnode(value); //calling Addnode function to insert nodes
		printlist(); //calling printlist function 
	}
	cout<< "Enter the key u want to search:\t";
	cin>> key;
	search(key); //calling search function
	return 0;
}
