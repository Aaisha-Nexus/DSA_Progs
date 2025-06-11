//Doubly linked list sort while insert, copy, reverse, min and max ;
#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void insertandSort(int val)
{
	Node* ptr =  new Node();
	ptr->data=val;
	ptr->next=NULL; //initially prev and next both are null
	ptr->prev=NULL;
	
	if(head==NULL) // case 1: if the list is empty then head and tail both is the newly added node
	{ 
        head = ptr;
        tail = ptr; // First node is both head and tail
	}
		
	else if(val < head->data) //case 2: insert in beginning val should be less than head 
	{					//want to insert 1 where initially 2 was head 
		 ptr->next=head; // NULL<->1<->2<->3<->NULL
		 ptr->prev=NULL; //after adding node in beginning its prev is NULL
		 head->prev=ptr; //link the old head to the new node so new head is 1
		 head=ptr; //update the new head (assign the ne wnode to the head)
		 return;
	}
	
	else // case 3: if nodes exist then add in end or middle as needed 
	 {
	 	Node* temp= head;
	 	while( temp->next!=NULL && temp->next->data < val) //1<->2<->3<->NULL you want to add 4 
	 	{
	 		temp=temp->next; //traverse till 3 as temp->null and its less than new val 4 
		 }
		 
		 ptr->next=temp->next; //pointer of 4's next ptr->next = temp->next which was null so its look 4<->NULL
		 ptr->prev=temp; //link prev with temp which was 3 so now it looks like 1<->2<->"3<->4<->NULL"
		 
		 if(temp->next!=NULL) // 1<->3<->NULL //example we want to add 2 in between 1 and 3 
		 {
		 	temp->next->prev = ptr; //update the prev pointer of the next node  //here temp(1) temp->next means 3 and its prev means before it assign ptr means 1<->2<->3<->null
		 }
		 temp->next = ptr; // 1's next is the ptr means 2 so 1<->2<->3<->NULL
		 
		 if(ptr->next==NULL) //if adding at end then update the tail  ex; 1<->2<->3<->NULL //here 3 is ptr and its next is NULL so make 3 as tail
		 {
		 	tail=ptr;
		 }
	}
}

void printNode(Node* node) //priting by passing head copy
{
	while(node!=NULL)
	{
		cout<< node->data << "->";
		node=node->next;
	}
	cout << "NULL" << endl;
}

Node* copyList(Node* head)
{
	
	
	if(head==NULL) //if no node then return nothing to copy
	{
		return NULL;
	}
	
	Node* newtail=NULL; //initially new head and tail are null
	Node* newhead = NULL;

	while(head!=NULL)
	{
		Node* newnode = new Node(); //make a new node 
		newnode->data=head->data; //copy the data 
		newnode->next=NULL;    // 1<->2<->3<->NULL
		
		newnode->prev=newtail; //initially newtail was null so prev is now null then it moves to 1,2 and stops at 3 
		
		
	 	if(newhead==NULL) //inserting at head
	 	{
	 		newhead=newnode; //the newly added node is the newhead itself
		 }
		 else 
		 {
		 	newtail->next=newnode; //link newtails next to newnode like if 2 was newtail then 2<->3 linkw with 3 
		 }
		 newtail= newnode; //then assign 3 as the newtail
		 head=head->next; //traverse the original list
	}	
	  return newhead;
}

Node* reverseprint (Node* head)
 {
	                      // 1<->2<->3<->NULL;
	Node* curr = head; //initially points to 1 which is head
	Node* temp=NULL;
	while(curr!=NULL) //till its not null keep traversing  
	{
	    //swapping next and prev
	    temp=curr->prev; //1)assigns null initially , 2) now temp is 1  3) now 3's prev is 2 so temp=2 
	     curr->prev=curr->next; //1)2 becomes prev so like 2<->1 2)3 becomes curr's prev means 3<->2 (3) NULL prev prev of 3 like NULL<->3
	     curr->next=temp;  //1's next now becomes null so it looks like 2<->1<->NULL 2) link 1<->null with curr now looking like 3<->2<->1<->null (3) 2 becomes cur's nect like NULL<->3<->2<->1
	     
	     //next node in original list
	     curr=curr->prev; // 1)now curr is updated to 2 (2) now curr points to curr's prev which is now 3  (3) 3's prev which is NULL now becomes curr and loops end 
	     
	}
	  if(temp!=NULL) //now loop ends and temp is 2
	  {
	  	head=temp->prev; //new head becomes temp-> prev means 2's prev which was 3 in  [H]->3<->2<->1<->null
	  }
	return head; //return 3 and attached LL
}

Node* findMin(Node* head) //to find min traverse the list and keep track of mind 
{
	if(head==NULL)
	{
		return NULL;
	}
	
	Node* curr = head;   //1<->2<->3<->null
	Node* minimumNode =head; //assigning head to minimum for comparisons means 1 is assigned  
	while(curr!=NULL)
	{
		if(curr->data < minimumNode->data) //if the current data is less than minimum value (which was initially head) check 1 then its not less so moves to 2 its less so min is still 1 and so on 3 
		minimumNode=curr;  //update the minimum by that current value which will be 1 throughout
		curr=curr->next; //move to next node 
	}
		
	
	return minimumNode; //after loop ends min value is 1 so it gets returned 
}

Node* findMax(Node* head) //to find min traverse the list and keep track of mind 
{
	if(head==NULL)
	{
		return NULL;
	}
	
	Node* curr = head;
	Node* maximumNode =head; //assigning head to maximum for comparisons meanas 1 is assigned 
	while(curr!=NULL)
	{
		if(curr->data > maximumNode->data) //if the current data is greater than maximum value (which was initially head) then update maximum
		maximumNode=curr;  //update the minimum by that current value [it will check with 1 , then 2 max becomes 2 then comapres 2 with 3 max becomes 3 ]
		curr=curr->next; 
	}
		
	
	return maximumNode; //return 3 
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
        printNode(head);
    }

    // Copy and reverse
    Node* copylist= copyList(head);
    cout << "Copied List before reverse: ";
    printNode(copylist);
    Node* reverselist = reverseprint(copylist);
    cout << "Reversed Copied List: ";
    printNode(reverselist);
    
    Node* MinNode = findMin(head);
    cout<< "The Minimum node is " << MinNode->data << endl;
     Node* MaxNode = findMax(head);
    cout<< "The Maximum node is " << MaxNode->data << endl;
    

    return 0;
}
