//AVL TREE CODE 
#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* Lchild;
	Node* Rchild;
	int height; //height will be used as a balance factor
};

int getHeight(Node* n)
{
	if(n==NULL)
	return 0;
	
	return n->height;
}
Node* CreateNode(int value)
{
	Node* temp = new Node();
	temp->data=value;
	temp->Lchild=NULL;
	temp->Rchild= NULL;
	temp->height=1; //initially making it one because leaf node height will become one after placing anywhere
	return temp;
		
}

int getBalanceFactor(Node* n) //
{
	if(n==NULL)
	{
		return 0;
	}
	
	return getHeight(n->Lchild) - getHeight(n->Rchild);
	
}


Node* RightRotate ( Node* y ) 
{
	Node* x = y->Lchild; //acc to initial diagaram
	Node* T2 =  x->Rchild;
	
	//now x k right ko y kardo aur y k left ko t2 kardo
	x->Rchild = y;
	y->Lchild =  T2;
	
	//now after re wiring the nodes update the height as well
	y->height = max(getHeight(y->Rchild), getHeight(y->Lchild)) + 1;
	x->height = max(getHeight(x->Rchild), getHeight(x->Lchild)) + 1;
	
	return x; //returning x because it is now the root node
}

Node* LeftRotate ( Node* x )  
{
	Node* y = x->Rchild; //acc to initial diagaram
	Node* T2 =  y->Lchild;
	
	//now x k right ko y kardo aur y k left ko t2 kardo
	y->Lchild = x;
	x->Rchild =  T2;
	
	//now after re wiring the nodes update the height as well
	y->height = max(getHeight(y->Rchild), getHeight(y->Lchild)) + 1;
	x->height = max(getHeight(x->Rchild), getHeight(x->Lchild)) + 1;
	
	return y; //returning x because it is now the root node
}

Node* Insert ( Node* node, int value) //our insert function in the tree
{
	if(node==NULL) //normal bst insertion 
	{
		return(CreateNode(value));
	}
	if(value<node->data) //if value will be smaller than root node then it will insert in left subtree
	{
		node->Lchild=Insert(node->Lchild, value);
	}
	else //if value will be greater than root node then it will insert in right subtree
	{
		node->Rchild=Insert(node->Rchild,value);
	}

	node->height = 1 + max(getHeight(node->Lchild), getHeight(node->Rchild)); // yeh uper se nahi neeche se height ko update krte huwe ayega like from leaf node thats why it runs here
	int bf = getBalanceFactor(node); //new node ka balance factor will be stored in bf and if this gets imbalanced then we have 4 cases 
	
	//case 1: Left Left case
	if(bf>1 && value < node->Lchild->data)
	{
		return RightRotate(node);
	}
	//case 2: Right Right case
	if(bf<-1 && value > node->Rchild->data)
	{
		return LeftRotate(node);
	}
	//case 3: Left Right case
	if(bf>1 && value > node->Lchild->data )
	{
		node->Lchild=LeftRotate(node->Lchild);
		return RightRotate(node);
	}
	//case 4: Right Left case
	if(bf<-1 && value < node->Rchild->data )
	{
		node->Rchild=RightRotate(node->Rchild);
		return LeftRotate(node);
	}
	 return node;
}
 //finding min value in left subtree to be used in delete node function
Node* getMinValueNode(Node* node) {
    Node* current = node;
    while (current->Lchild != NULL)
        current = current->Lchild;
    return current;
}

Node* deleteNode(Node* node, int value) 
{
	if(node==NULL) return node ;
 
	if(value < node->data )
	{ 
		node->Lchild = deleteNode(node->Lchild, value); 
	}
	else if (value > node->data)
	{
		node->Rchild= deleteNode(node->Rchild, value);
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
			Node* temp = node->Rchild; //hold the address of right child
			delete node;
			return temp;
		}
		else if(node->Rchild==NULL) //if right child doesnt exist it means left will exist
		{
			Node* temp= node->Lchild; //hold the address of left child
			delete node;
			return temp;
		}
		else //if both child exists
		{
			Node* temp = getMinValueNode(node->Rchild);
			node->data=temp->data;
			node->Rchild= deleteNode(node->Rchild, temp->data );
		}
	}

	node->height = 1 + max(getHeight(node->Lchild), getHeight(node->Rchild)); //Go back up the recursive chain. Update the height of each ancestor. 
	int bf = getBalanceFactor(node); //Calculate the Balance Factor (just like insertion)

	//case 1: Left Left case
	if(bf>1 && getBalanceFactor(node->Lchild) >= 0)
	{
		return RightRotate(node);
	}
	//case 2: Right Right case
	if(bf<-1 && getBalanceFactor(node->Rchild) <= 0)
	{
		return LeftRotate(node);
	}
	//case 3: Left Right case
	if(bf>1 && getBalanceFactor(node->Lchild) < 0 )
	{
		node->Lchild=LeftRotate(node->Lchild);
		return RightRotate(node);
	}
	//case 4: Right Left case
	if(bf<-1 && getBalanceFactor(node->Rchild) > 0 )
	{
		node->Rchild=RightRotate(node->Rchild);
		return LeftRotate(node);
	}
	return node;
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
    Node* root = NULL;
    int numValues;

    cout << "How many values do you want to insert into the AVL Tree? ";
    cin >> numValues;

    cout << "Enter " << numValues << " values:\n";
    for (int i = 0; i < numValues; i++) {
        int val;
        cin >> val;
        cout << "Inserting: " << val << endl;
        root = Insert(root, val);  // your original insert function
    }

    cout << "\nAVL Tree after insertions:\n";
    printTree(root);  // your existing function

    char choice;
    do {
        int delValue;
        cout << "\nEnter a value to delete from AVL Tree: ";
        cin >> delValue;
        root = deleteNode(root, delValue);

        cout << "\nAVL Tree after deleting " << delValue << ":\n";
        printTree(root);

        cout << "\nDo you want to delete another value? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}



