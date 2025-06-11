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

void deleteFirstNode() {
    if (head == NULL) { // If list is empty then you cannot delete anything
        cout << "List is empty, nothing to delete!" << endl;
        return;
    }

    Node* temp = head;

    // If there is only one node then delete it
    if (head->next == head) {
        delete head;
        head = NULL;
        cout << "List is now empty after deletion." << endl;
        return;
    }

    // Traverse to the last node at of the circular linkedlist  10->20->30->back to head
    Node* last = head;  //last=10
    while (last->next != head) //traverse till end  until u find head back
	{
        last = last->next;  //then reach 30-> 
    }

    // Update head and link last node to new head (updated head)
    head = head->next; //update head which was earlier 10 to making it point to next means 10->next which is 20 now becomes head
    last->next = head; //linking last node to the new head like 30->20(updated head) to maintain circularity

    // Delete the old head
    delete temp; //updated linkedlist becomes 20->30->back to head

    cout << "First node deleted successfully." << endl;
}

int main()
{
    int n,value;
	cout<< "Enter the number of nodes you want in Linkedlist:\t";
	cin>> n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the value of the nodes:\t";
		cin>> value;
		Addnode(value); //calling Addnode function to insert nodes
		printlist(); //calling printlist function 
	}
	
	// Deleting the first node
    cout << "\nDeleting first node..." << endl;
    deleteFirstNode(); //call deletenode function to delere first node
    
    // Print the list after deletion
    printlist();
	return 0;
}
