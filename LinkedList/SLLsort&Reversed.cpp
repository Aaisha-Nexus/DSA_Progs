// SINGLY LINKEDLIST SORT WHILE INSERTION AND COPY AND REVERSE 
#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head= NULL;

//insert function along with sort
void insertandSort(int val)
{
	Node* ptr = new Node(); //create a new node
	ptr->data=val; //data takes value 
	ptr->next=NULL; //next points to null
	
	if(head==NULL || val < head->data) //the value should be less than head's value like 2->3-> so Head is 2 it should be less 
	{
		ptr->next=head; //if position starts at head
		head=ptr; //1 can be added like 1->2->3->
		return;
	}
	
	Node* temp=head;
	while(temp->next!=NULL && temp->next->data < val ) //inserting 4 in 2->3->5 would stop at 3, to insert after it 2->3->4-> so 4 is 3 is less than 4
	{
		temp=temp->next;
	}
	 
	    ptr->next=temp->next; //[X] -> [B] train link analogy , if temp was (A) it was like [A]->[B] so temp->next "->B"
	    temp->next=ptr; // Link the last node's next pointer to the newly created node //[A] -> [X] -> [B] -> [C] -> [D] links completes 
	
	
}

void printnode(Node* node) //this printnode will work for both original and copy 
{

	while(node!=NULL)
	{
		cout << node->data << "->";
		node=node->next;
	}
	cout << "NULL" << endl;
}

Node* copylist(Node* head) //passing head as pointer changes will be affected in local copy only 
{
     while(head==NULL) //if list is empty no value to copy 
	 {
	 return NULL; 
	 }
	 
	 Node* newhead = NULL; //points to the first node of the copied list
	 Node* newtail =NULL; //used in inserting nodes at the end of the copied list
	 
	 while(head!=NULL)
	 {
	 	Node* newnode = new Node(); //make new node for each to copy
	 	newnode->data=head->data; //copy data of head into new node 
	 	newnode->next=NULL;
	 	
	 	if(newhead==NULL) // if list is empty, make both newhead and newtail point to newnode
	 	{
	 		newhead=newnode;
	 		newtail=newnode;
		 }
		 else 
		 {
		 	newtail->next=newnode; //current last node's next pointer to point to this new node
		 	newtail=newnode; //now make this newly added node as the tail
		 }
		 head=head->next; //keep traversing
	}	
	  return newhead;
}


Node* reverseprint (Node* head)
 
{
	Node* prev = NULL;
	Node* curr = head;
	Node* next = NULL;
	while(curr!=NULL) //if it becomes null then return 
	{
	    //NULL<-1->2->3->null;
	     next=curr->next;  //next=2
	     curr->next=prev; // 1->next=NULL
	     prev=curr; // prev=1; it will look like this  ->1  '1 will come behind'
	     curr=next; // 2 becomes temp it looks like 2->1->null and so on till 3->2->1->null
	     
	}
	  return prev; //new head of reversed list which is now 3 

}

int main() 
{
    int n, val;
    cout << "Enter the number of nodes you want in the LinkedList: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> val;
        insertandSort(val);
        cout << "Current List: ";
        printnode(head);
    }

    // Copy and reverse
    Node* copyList= copylist(head);
    cout << "Copied List before reverse: ";
    printnode(copyList);
    Node* reverselist = reverseprint(copyList);
    cout << "Reversed Copied List: ";
    printnode(reverselist);

    return 0;
}
