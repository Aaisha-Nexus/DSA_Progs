//Doubly insert,del,min move to end, max move to first, total nodes and middle of LL
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
	
	Node(int val) //constructor called when a node is created 
	{
		data=val;
		next=NULL;
		prev=NULL;
	}
};
Node* head = NULL;
Node* tail = NULL;

void insertNode(int val) { //normal insert node without sorting 
	Node* ptr = new Node(val);
	ptr->data = val;
	ptr->next = NULL;
	ptr->prev = tail;

	if (head == NULL) {  // If list is empty, new node is both head and tail
		head = tail = ptr;
	} else {
		tail->next = ptr;
		ptr->prev = tail;
		tail = ptr;
	}
}

void deleteNode(int keyval) {
	if (head == NULL) {
		cout << "List is empty!" << endl; // If list is empty, nothing to delete
		return;
	}

	Node* temp = head;

	// Traverse until you find the node with the key value
	while (temp != NULL && temp->data != keyval) {
		temp = temp->next;
	}

	if (temp == NULL) {  // Key not found
		cout << keyval << " not found!" << endl;
		return;
	}

	if (temp == head) {  // Case: Delete head node
		head = head->next;
		if (head != NULL)
			head->prev = NULL;
		else
			tail = NULL;  // If list becomes empty
	} 
	else if (temp == tail) {  // Case: Delete tail node
		tail = tail->prev;
		if (tail != NULL)
			tail->next = NULL;
		else
			head = NULL;  // If list becomes empty
	}
	else {  // Case: Delete a middle node
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}

	delete temp;
}


Node* findMin(Node* head) //to find min traverse the list and keep track of mind 
{
	if(head==NULL)
	{
		return NULL;
	}
	
	Node* curr = head;   //1<->2<->3<->null
	Node* minimumNode = head; //assigning head to minimum for comparisons means 1 is assigned  
	while(curr!=NULL)
	{
		if(curr->data < minimumNode->data) //if the current data is less than minimum value (which was initially head) check 1 then its not less so moves to 2 its less so min is still 1 and so on 3 
			minimumNode = curr;  //update the minimum by that current value which will be 1 throughout
		curr = curr->next; //move to next node 
	}
		
	//detach it from old place so maintain links 
	if (minimumNode->prev != NULL)
	{
		minimumNode->prev->next = minimumNode->next;
	}
	if (minimumNode->next != NULL)
	{
		minimumNode->next->prev = minimumNode->prev;
	}
	
	//do connects move it to first
	if (minimumNode != head) { //only move if min node is not already at head
		minimumNode->prev = NULL; //min comes in front so its prev becomes NULL
		minimumNode->next = head; //min comes in front so its next point to curr head 
		if (head != NULL)
			head->prev = minimumNode; //curr's prev points now to min so it automatically comes later than min
		head = minimumNode; //now point the head to min which is now at first place 
	}
	
	return head;
}


Node* findMax(Node* head) 
{
	if (head == NULL)
		return NULL;

	Node* curr = head;
	Node* maximumNode = head; //assigning head to maximum for comparisons 

	// Find the maximum node
	while (curr != NULL)
	{
		if (curr->data > maximumNode->data)
			maximumNode = curr;
		curr = curr->next;
	}

	// If the maximum node is already at the end, no need to move
	if (maximumNode == tail)
		return head;

	// If maximum node is head
	if (maximumNode == head)
	{
		head = head->next;
		if (head != NULL)
			head->prev = NULL;
	}
	else
	{
		// Disconnect maximumNode from its current position
		if (maximumNode->prev != NULL)
			maximumNode->prev->next = maximumNode->next;
		if (maximumNode->next != NULL)
			maximumNode->next->prev = maximumNode->prev;
	}

	// Move maximumNode to end
	tail->next = maximumNode;
	maximumNode->prev = tail;
	maximumNode->next = NULL;
	tail = maximumNode;

	return head;
}


void totalNodes(Node* head) //traverse the list and keep counting the nodes 
{
	int count = 0;
	Node* temp = head;
	while (temp != NULL) 
	{
		count++;
		temp = temp->next;
	}
	cout << "Total nodes are: " << count << endl;
}

void middleNode(Node* head) //slow fast pointer concept fast moves 2 step slow moves 1 step when fast reaches end slow will be at middle
{
	Node* slow = head;
	Node* fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow != NULL)
		cout << "Middle node is: " << slow->data << endl;
}

void printNode(Node* node) //priting by passing head copy
{
	while(node!=NULL)
	{
		cout<< node->data << "<->";
		node=node->next;
	}
	cout << "NULL" << endl;
}

int main() {
	int n, value, delKey;
	cout << "Enter the number of nodes you want in the Linked List:\t";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Enter the value of the nodes:\t";
		cin >> value;
		insertNode(value);
		printNode(head);
	}

	cout << "Enter the value of the node to delete:\t";
	cin >> delKey;
	deleteNode(delKey);
	printNode(head);

	head = findMin(head);
	cout << "After moving minimum to front:\n";
	printNode(head);

	head = findMax(head);
	cout << "After moving maximum to end:\n";
	printNode(head);

	totalNodes(head);
	middleNode(head);

	return 0;
}

