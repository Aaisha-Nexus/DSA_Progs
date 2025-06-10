//circular queue implemenation using linkedlist for dynamic
#include<iostream>
using namespace std;

struct Queue {
	int data;
	Queue* next;
};

Queue* front = NULL; //initially front and rear is null
Queue* rear = NULL;

void enQueue()
{
	Queue* ptr = new Queue();
	int value;
	cout<< "Enter data:\t";
	cin>> value;
	ptr->data=value;
	ptr->next=NULL;
	
	if(front==NULL){ //if front is null means newnode becomes both front and rear
	   front=ptr;
	   rear=ptr;
	   rear->next=front; //to maintain circularity point the last element back to first	
	}
	else //if it wasnt null means queue exist then update the pointers
	{
		rear->next=ptr; //assign new value at the end 
		rear=ptr; //update the rear
		rear->next=front; //again now point new rear to the front for circularity
		
	}
}

void deQueue()
{
	if(front==NULL){
		cout<< "Queue is empty! no element to remove" << endl;
		return;
	}
	
	if(front==rear) { //if only one node is present in a circular queue
		delete front;
		front=NULL; //make both null
		rear=NULL;
	}
	
	else //if more than one element is there in queue
	{
		Queue* temp= front;
		front= front->next;
		rear->next=front; //to maintain circularity point the rear to new front 
		delete temp; //them delete the old front 
	}
}

void print()
{
	if(front==NULL)
	{
		cout<< "Queue is empty!" << endl;
		return;
	}
	
	Queue* temp=front;
	cout<< "The Queue is : " << endl;
	do
	{
		cout <<  temp->data << "\n";
		temp=temp->next;
	} while(temp!=front); //do till queue reached front again(stop till circular queue is compleetd)
	cout << "Back to first element" << endl; 
}
int main ()
{
	int size;
	cout<< "Enter the size of the queue:\t";
	cin>> size;
	for( int i=0; i<size; i++)
	{
	   enQueue();
	   print();	
	}
	char ans;
	cout<< "Do you want to remove an element? (y/n)\t";
	cin>> ans;
	
	if(ans=='y' || ans=='Y')
	{
		deQueue();
		print();
	}
	
	return 0;
}
