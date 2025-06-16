#include <iostream>
#include <iomanip>
using namespace std;

struct bstNode{
	int data;
	bstNode* Lchild;
	bstNode* Rchild;
};

//BST Insertion
bstNode* insert(bstNode* node, int value)
{
	if(node==NULL)
	{
		bstNode* temp = new bstNode(); //create a new node
		temp->data=value; //take thee value
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

//check if trees are equal
bool areTreesEqual(bstNode* root1, bstNode* root2)
{
	if(root1==NULL && root2==NULL) //base cases
	{
		return true; //if both the trees are null they are equal
	}
	
	else if(root1==NULL || root2==NULL) //base case 
	{
		return false; // //if either of the trees are null they cant be equal
	 } 
	 //if the data is equal on both trees and then recursively call on subtrees to check if they are euqal 
	 else if(root1->data == root2->data && areTreesEqual(root1->Lchild,root2->Lchild) && areTreesEqual(root1->Rchild, root2->Rchild))
	 {
	 	return true;
	 }
	 else 
	 {
	 	return false;
	 }
}

//check if trees have same structure 
bool isStructureSame(bstNode* root1, bstNode* root2)
{
	if(root1==NULL && root2==NULL)
	{
		return true; //if both the trees are null they are equal
	}
	
	else if(root1==NULL || root2==NULL)
	{
		return false; // //if either of the trees are null they cant be equal
	 } 
	 //recursively call this function with base cases on subtrees or child noes and check for structure (data can be different)
	 else if(isStructureSame(root1->Lchild,root2->Lchild) && isStructureSame(root1->Rchild, root2->Rchild))
	 {
	 	return true;
	 }
	 else 
	 {
	 	return false;
	 }
}

//reverse of INORDER TRAVERSAL(originally ascending) LNR so reverse it to RNL for descending sort
void descendingSort(bstNode* node) //in inorder we follow LNR 1)first go to left 2) then print node 2)then go to right
{
	if(node!=NULL)
	{
		descendingSort(node->Rchild);
		cout << node->data << " ";
		descendingSort(node->Lchild);
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
    cout << "\n1. Insert into Tree" << endl;
    cout << "2. Check if Trees are Equal and Same Structure" << endl;
    cout << "3. Print Descending Order" << endl;
    cout << "4. Exit" << endl;
}

int main()
 {
    bstNode* root1 = NULL; //initially both roots are null
    bstNode* root2 = NULL;
    int option;

    do {
        Menu(); //call menu display
        cout << "Choose option: ";
        cin >> option;

        switch (option) {
        case 1:
		 {
            int treeNum, size, value;
            cout << "Which tree to insert in? (1 or 2): ";
            cin >> treeNum;
            cout << "Enter number of values to insert: ";
            cin >> size;
            for (int i = 0; i < size; i++) {
                cout << "Enter value: ";
                cin >> value;
                if (treeNum == 1) //if tree1 then pass root1
                    root1 = insert(root1, value);
                else
                    root2 = insert(root2, value); //if tree2 then pass root2
            }
            break;
        }
        case 2: //checks if trees are equal and have same structure 
		 {
            if (areTreesEqual(root1, root2))
                cout << "Trees are Equal!" << endl;
            else
                cout << "Trees are NOT Equal!" << endl;

            if (isStructureSame(root1, root2))
                cout << "Trees have SAME Structure." << endl;
            else
                cout << "Trees have DIFFERENT Structure." << endl;
            break;
        }
        case 3: 
		{
            cout << "Tree 1 in Descending Order: ";
            descendingSort(root1);
            cout << endl;
            cout << "Tree 2 in Descending Order: ";
            descendingSort(root2);
            cout << endl;
            break;
        }
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid option." << endl;
        }
    } while (option != 4);

    return 0;
}

