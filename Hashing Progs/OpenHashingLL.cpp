// hashmap using linkedlist (insertion at front to save traversal time and is hence fast traversal)
#include<iostream>
using namespace std;

struct Node //making a struct for our linkedlist which will be chained
{
	int data;
	Node* next;
	
};

const int SIZE = 5; //available slots ya buckets

Node* hashTable[SIZE]; //the hashmap is of size 5

void initializetable()
{
	for(int i=0; i<SIZE ;i++)
	{
		hashTable[i]=NULL;  //initiliaze the hashtable with null values 
	}
}

int hashfunction(int value)
{
	return value%SIZE; //return hashfunction to keep the track of within bounds indices
}

void insert(int value)
{
	int index = hashfunction(value); //to store the index of the given value
	
	Node* newnode =  new Node(); //make a new node 
	newnode->data=value; //save the value part
	newnode->next=NULL; //the next initially points to null
	
	if(hashTable[index]==NULL) //if there is not node initially
	{
		hashTable[index]=newnode; //make the newnode as the first node of the hashtable 
	}
	else{ //else insert at the front 
		newnode->next=hashTable[index]; //newnode's next point to current head(like LL insert at beginning example) hence the current head becomes second element  
		hashTable[index]=newnode; //and the new head now points to the newly added node inserting it in the front
	}
	
	
}

void display()
{
	cout<< "THE HASH TABLE IS " << endl;
	for(int i=0; i<SIZE ;i++)
	{

	cout<< "Index " << i << " : " ;
	
	Node* temp = hashTable[i];
	while(temp!=NULL)
	{
		cout << temp->data << "->" ;
		temp=temp->next;
	}
	cout << "NULL\n" ;
}
}

int main()
{
	initializetable();
	
	int num;
	cout << "Enter the number of values to insert:\t";
	cin>> num;
	
	for(int i=0; i<num ;i++)
	{
		int value;
		cout<< "Enter Value " << i << ": ";
		cin>> value;
		insert(value);
	}
	display();
	return 0;
}

