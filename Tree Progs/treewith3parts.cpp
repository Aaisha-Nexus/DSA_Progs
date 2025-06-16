/*TREE QUESTION1 WITH 3 PARTS 1) are trees equal(data on nodes shall be same) 2) is same structure( same no of children) but data can be diff 3) ismirrorimage?  */
#include<iostream>
#include<string>
using namespace std;

struct Node{
	string data;
	Node* Lchild;
	Node* Rchild;
};

bool areTreesEqual(Node* tree1, Node* tree2)
{
	if(tree1==NULL && tree2==NULL)
	{
		return true; //if both the trees are null they are equal
	}
	
	else if(tree1==NULL || tree2==NULL)
	{
		return false; // //if either of the trees are null they cant be equal
	 } 
	 
	 else if(tree1->data == tree2->data && areTreesEqual(tree1->Lchild,tree2->Lchild) && areTreesEqual(tree1->Rchild, tree2->Rchild))
	 {
	 	return true;
	 }
	 else 
	 {
	 	return false;
	 }
}

bool isStructureSame(Node* tree1, Node* tree2)
{
	if(tree1==NULL && tree2==NULL)
	{
		return true; //if both the trees are null they are equal
	}
	
	else if(tree1==NULL || tree2==NULL)
	{
		return false; // //if either of the trees are null they cant be equal
	 } 
	 
	 else if(isStructureSame(tree1->Lchild,tree2->Lchild) && isStructureSame(tree1->Rchild, tree2->Rchild))
	 {
	 	return true;
	 }
	 else 
	 {
	 	return false;
	 }
}

bool isMirrorImage(Node* tree1, Node* tree2)
{
	if(tree1==NULL && tree2==NULL)
	{
		return true; //if both the trees are null they are equal
	}
	
	else if(tree1==NULL || tree2==NULL)
	{
		return false; // //if either of the trees are null they cant be equal
	 } 
	 
	 else if(tree1->data == tree2->data && isMirrorImage(tree1->Lchild,tree2->Rchild) && isMirrorImage(tree1->Rchild, tree2->Lchild))
	 {
	 	return true;
	 }
	 else 
	 {
	 	return false;
	 }
}

//insert node
Node* createNode(string val) 
{

    Node* temp = new Node();
    temp->data = val;
    temp->Lchild = NULL;
    temp->Rchild = NULL;

    return temp;
}


void printTree(Node* root, int space = 0, int gap = 6)  //function to print the tree 
{
	if (root == NULL) return;
	space += gap;
	printTree(root->Rchild, space);
	cout << string(space, ' ') << root->data << endl;
	printTree(root->Lchild, space);
}

int main() {
	
    Node* tree1 = createNode("A");
	tree1->Lchild = createNode("B");
	tree1->Rchild = createNode("C");
	tree1->Lchild->Rchild= createNode("D");

	printTree(tree1);

	cout << "\n\n\n----- Tree 1 -----\n\n\n";

	Node* tree2 = createNode("A");
	tree2->Rchild = createNode("B");
	tree2->Lchild = createNode("C");
	tree2->Rchild->Lchild= createNode("D");

	printTree(tree2);
		cout << "\n\n\n----- Tree 2 -----\n\n\n";
		
    int option ;
    do{
    	cout << "\n1) Check if Trees are Equal\n"
         << "2) Check if Trees have same structure\n"
         << "3) Check if Trees are Mirror Image of each other\n"
         << "4) Exit the program" << endl;
	cout << "Enter your choice (1-3):\t";
	cin >> option;
    switch(option)
    {
    	case 1:
    	if(areTreesEqual(tree1,tree2))
		{
			cout << "Trees are Equal !" << endl;
		}   
		else
		{	
		cout << "Trees are not equal !" << endl;
	}
		break;
		
		case 2:
		if(isStructureSame(tree1,tree2))
		{
			cout << "Trees have same Structure !" << endl;
		}  
		else
		{	
		cout << "Trees do not have same Strcture !" << endl;
	}
		break; 
		
		case 3:
		if(isMirrorImage(tree1,tree2))
		{
			cout << "Trees have mirror image !" << endl;
		}    
		else
		{
			cout << "Trees do not have mirror image !" << endl; 
		}	
		break;  
		
		case 4:
		cout << "Exiting the program " << endl;
		break;
		
		default:
		cout << "Invalid option! please enter a valid option" << endl;
			
	}
} while(option!=4);

    return 0;
}

