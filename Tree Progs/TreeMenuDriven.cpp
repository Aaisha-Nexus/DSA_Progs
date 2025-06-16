// menu driven program for trees 
#include <iostream>
#include <iomanip>
using namespace std;

struct bstNode{
	int data;
	bstNode* Lchild;
	bstNode* Rchild;
};

bstNode* insert(bstNode* node, int value)
{
	if(node==NULL)
	{
		bstNode* temp = new bstNode(); //create a new node
		temp->data=value; //take tehe value
		temp->Lchild=NULL; //initially left and right child are null
		temp->Rchild=NULL;
		return temp;
	}
	if(value<node->data) //if value will be smaller than root node then it will insert in left subtree
	{
		node->Lchild=insert(node->Lchild, value);
	}
	else //if value will be greater than root node then it will insert in right subtree
	{
		node->Rchild=insert(node->Rchild,value);
	}
	return node;
}

void search(bstNode* node, int value)
{
	if(node==NULL) //if there is no node then it cannot be found
	{
		cout<< "Node not found! " << endl;
		return;
	}
	
	if(node->data==value) //if the node and searching value matches
	{
		cout<< value << " found !" << endl; //value found
	}
	else if (value<node->data) //if value will be smaller then it will search in left subtree
	{
		search(node->Lchild,value);
	}
	else //if value will be greater then it will search in right subtree
	{
		search(node->Rchild,value);
	}
}

bstNode* findMin(bstNode* node) { //function to find a minimum value in a subtree
    while (node && node->Lchild != NULL) {
        node = node->Lchild;
    }
    return node;
} 

bstNode* deletenode( bstNode* node , int value)
{
	if(node==NULL) return node ;
 	
 if(value < node->data )
{ 
    node->Lchild = deletenode(node->Lchild, value); // ? fix
}
	 else if (value > node->data)
	 {
	 	node->Rchild= deletenode(node->Rchild, value);
	 }
	 else  //now use three cases of no ,one and two child
	 {
	 	if(node->Lchild==NULL && node->Rchild==NULL) //if no child exist simply delete the node and return
	 	{
	 		delete node;
	 		return NULL;
		 }
		 
		 else if(node->Lchild==NULL) //if left child doesnt exist it means right child exist so call deletenode function on right
		 {
		 	bstNode* temp = node->Rchild; //hold the address of right child
		 	delete node;
		 	return temp;
		 }
		 
		 else if(node->Rchild==NULL) //if right child doesnt exist it means left will exist
		 {
		 	bstNode* temp= node->Lchild; //hold the address of left child
		 	delete node;
		 	return temp;
		 }
		 
		 else //if both child exists
		 {
		 	bstNode* temp = findMin(node->Rchild);
		 	node->data=temp->data;
		 	node->Rchild= deletenode(node->Rchild, temp->data );
		 }
	 }
	 return node;
}

void Preorder(bstNode* node) //in preorder we follow NLR 1)first print node 2) then go to left 2)then go to right
{
	if(node!=NULL)
	{
		cout << node->data << " ";
		Preorder(node->Lchild);
		Preorder(node->Rchild);
	}
}

void Inorder(bstNode* node) //in inorder we follow LNR 1)first go to left 2) then print node 2)then go to right
{
	if(node!=NULL)
	{
		Inorder(node->Lchild);
		cout << node->data << " ";
		Inorder(node->Rchild);
	}
}

void Postorder(bstNode* node) //in postorder we follow LRN 1)first go to left 2) then go to right 2)then print node
{
	if(node!=NULL)
	{
		Postorder(node->Lchild);
		Postorder(node->Rchild);
		cout << node->data << " ";
	}
}

// Function to print BST in a structured way
void printTree(bstNode* root, int space = 0, int gap = 6) {
    if (root == NULL) return;
    
    space += gap; // Increase spacing for right child
    printTree(root->Rchild, space);
    
    cout << string(space, ' ') << root->data << endl; // Print current node with indentation
    
    printTree(root->Lchild, space); // Process left child
}

void Menu() {
    cout << "\nTree Menu:\n"
         << "1) Insert\n"
         << "2) Search\n"
         << "3) Delete\n"
         << "4) PreOrder Traversal\n"
         << "5) InOrder Traversal\n"
         << "6) PostOrder Traversal\n"
         << "7) Print Tree Structure\n"
         << "8) Exit the program\n";
}

int main()
{
	bstNode* root = NULL; //declaring root
	cout<< "*************WELCOME TO TREES DATA STRUCTURE PROGRAM*************";
	int option;
	do
	{
		Menu();
		cout<< "Choose the action you want to perform (1-6):\t";
		cin>> option;
	switch(option){
		case 1: //to insert values in tree
		    int size, value;
		    cout<< "Enter the size of the tree:\t" << endl;
		    cin>> size;
		    for( int i=0; i<size;i++)
		    {
		    cout<< "Enter the value to insert:\t";
		    cin>> value;
		  	root=insert(root,value);
		  }
		  break;
		 
		case 2:
			int key;
			cout<< "Enter the value to search:\t";
			cin>> key;
			search(root,key); //to search a value
			break;
			
		case 3: //delete a node
		int todel;
	    cout<< "Enter the value to delete:\t";
	    cin>> todel;
		root = deletenode(root, todel);
		break;
		
		case 4:
			cout<< "PreOrder Traversal called!" << endl;;
			 Preorder(root);
			break;
		case 5:
				cout<< "InOrder Traversal called!" <<endl;
				Inorder(root);
			break;
		case 6:
				cout<< "PostOrder Traversal called!" << endl;
				Postorder(root);
			break;
			
		case 7: // Print Tree Structure
                cout << "Tree Structure:\n";
                printTree(root);
                break;
                
        case 8:
                cout << "Exiting program." << endl;
                break;
        default:
                cout << "Invalid option! Choose again." << endl;
            }
	} while(option!=8);
		return 0;
}
