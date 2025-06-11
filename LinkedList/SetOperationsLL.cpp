#include<iostream> //set operations on linkedlist
using namespace std;


struct Node {
    int data;
    Node* next;
    
    Node(int val) { //constructor to avoid writing input and next again and again
        data = val;
        next = NULL;
    }
};

void insertNode(Node* &head, int val) //passing head by reference to reflect changes 
 {
    Node* newnode = new Node(val);
    
    if (head == NULL) //if list is empty make the newnode as head
	{
        head = newnode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

bool search (Node* head, int key) //search funtion to find if the element already exists of not 
{
	Node* temp=head;
	while(temp!=NULL)
	{
		if(temp->data==key)
		return true;
		temp=temp->next;
	}
	return false;
}

//UNION OPERATION
Node* unionOperation(Node* list1, Node* list2) 
{
  Node* finalList =  NULL; //initially set final list to null
  
  //copy all elements of list1 into result which happens in union
  Node* temp = list1;
  while(temp!=NULL)
  {
  	insertNode(finalList, temp->data);
  	temp=temp->next;
  }
  
  //now check for list2 and then add those elements which arent found in finallist
 temp=list2;
  while(temp!=NULL)
  {
  	if(!search(finalList, temp->data)) //here temp->data means data of list 2 meaning if the data of list2 isnt found in final list then only add it in the final list
  	{
  		insertNode(finalList, temp->data);
	  }
	  temp=temp->next;
  }
  
  return finalList;
}

//INTERSECTION OPERATION 
Node* intersection(Node* list1, Node* list2)
 {
    Node* finalList = NULL;
    Node* temp = list1;
    
    while (temp != NULL) 
	{
        Node* temp2 = list2;
        while (temp2 != NULL) 
		{
            if (temp->data == temp2->data) 
			{  // if same data
                insertNode(finalList, temp->data); // insert once
                break; 
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    
    return finalList;
}


//MERGE OPERATION
Node* merge(Node* list1, Node* list2)
{
	Node* mergeList = NULL; //initially merged list is empty
	Node* temp1= list1;
	Node* temp2= list2;
	
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->data<temp2->data) //if list1 data is small as compared to data in list2
			{
				insertNode(mergeList, temp1->data); //then insert data in newlist
				temp1=temp1->next;
			}
			else 
			{
				insertNode(mergeList, temp2->data); //otherwise insert data of list2 in new list
				temp2=temp2->next;
			}
	}
	while(temp1!=NULL) //after merging if any of the list has some remaining nodes 
	{
		insertNode(mergeList, temp1->data); //then insert data in newlist
				temp1=temp1->next;
		}
		while(temp2!=NULL)
		{
			insertNode(mergeList, temp2->data); //otherwise insert data of list2 in new list
				temp2=temp2->next;
			}	
	return mergeList;
}

//DIFFERENCE OPERATION
Node* Diff(Node* list1 , Node* list2)
{
	Node* diff = NULL;
    Node* temp1 = list1;
    						// list1-list2
	while (temp1 != NULL)  //example temp1= {1 3 5 7 9) temp2={1,3,5} diff={7,9}
	{
 	 	
  	if(!search(list2, temp1->data)) //if value not found in list 2  then insert it in final list and ignore elements present in both 
  	{
  		insertNode(diff, temp1->data);
	}
	  
  	temp1 = temp1->next;
    }
        return diff;
}
//CUSTOMISED INSERT
Node* customInsert(Node* head, int item1, int item2) //accepts two items to work on item1-working for item2- inserting it in list
{
	Node* temp=head;
	while(temp!=NULL) //traverse from the start which is head
	{
		if(temp->data== item1) //checking if current nodes data matches with the given item
		{
			Node* newnode = new Node(item2); //creating a newnode with second items value
			newnode->next=temp->next; //Set the new node’s next pointer to current node’s next
			temp->next=newnode; //Set current node’s next to this new node
			
			temp=temp->next->next; // move temp two steps (skip over newnode)
		}
		else 
		{
			temp=temp->next; 
		}
	}
	
	return head; //return entire list 
}
	
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;;
}

int main() {
    Node* list1 = NULL; //initially both are null
    Node* list2 = NULL;
    
    int n;
    cout << "Enter number of elements in list1: ";
    cin >> n;
    
    cout << "Enter " << n << " elements for list1:" << endl;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertNode(list1, val);
    }
   
    
    cout << "Enter number of elements in list2: ";
    cin >> n;
    
    cout << "Enter " << n << " elements for list2:" << endl;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertNode(list2, val);
    }
    
    cout << "List 1: ";
    printList(list1);
    
    cout << "List 2: ";
    printList(list2);
    
    Node* Union = unionOperation(list1,list2);
    cout << "Union of List1 and List 2 : "; 
	 printList(Union);

	Node* Intersection = intersection(list1, list2);
	cout << "Intersection of List1 and List2: ";
	printList(Intersection);
    
    
    Node* Merge =  merge(list1, list2);
    cout << "Merged List is: ";
    printList(Merge);
    
    Node* Difference = Diff(list1, list2);
    cout << "Difference of Lists: ";
    printList(Difference);
    
    int item1, item2;
    cout << "Enter the first item to search for: " ;
    cin>> item1;
    cout << "Enter the second item to enter: ";
    cin>> item2;
    Node* CustomInsert= customInsert(list1, item1, item2);
    cout << "The List after Custom Insert is: ";
    printList(CustomInsert);
    
    return 0;
}







