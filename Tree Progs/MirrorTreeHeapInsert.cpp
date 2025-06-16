#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct Node{
	float data;
	Node* Lchild;
	Node* Rchild;
	
		Node(float val) // Constructor to initialize
		{  
        data = val;
        Lchild = NULL;
		Rchild = NULL;
    	}
};



Node* insertHeapWise(Node* root ,float val )
{
	Node* temp = new Node(val); 
	
	if(root==NULL)
	{
		return temp; // First node becomes the root
	}

	 queue <Node*> q; //make a queue for level wise insertion 
	 
	 q.push(root); //add the root to the queue 
	 
	 while(!q.empty()) //keep adding till queue isn't empty
	 {
	 Node* front = q.front(); //Take the front node of the queue.
	 
	 q.pop(); 
	 
	 
        if (!front->Lchild) 
		{
            front->Lchild = temp;
            return root;
        } 
		else
		 {
            q.push(front->Lchild);
        }

        if (!front->Rchild)
		 {
            front->Rchild = temp;
            return root;
        } 
		else 
		{
            q.push(front->Rchild);
        }
    }
    return root;
}

// function to create the mirror image
Node* mirrorImage(Node* root)
{
	if(root==NULL)
	return NULL;
	
	Node* mirror =  new Node(root->data);
	mirror->Lchild = mirrorImage(root->Rchild); 
	mirror->Rchild = mirrorImage(root->Lchild);
	return mirror;
}

//function to check if its correct mirror or not 
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
	 //data needs to be same and in mirror left of 1 tree will be equal to right of other and vice versa 
	 else if(tree1->data == tree2->data && isMirrorImage(tree1->Lchild,tree2->Rchild) && isMirrorImage(tree1->Rchild, tree2->Lchild))
	 {
	 	return true;
	 }
	 else 
	 {
	 	return false;
	 }
}

void printTree(Node* root, int space = 0, int gap = 6)  //function to print the tree 
{
	if (root == NULL) return;
	space += gap;
	printTree(root->Rchild, space);
	cout << string(space, ' ') << root->data << endl;
	printTree(root->Lchild, space);
}


int main ()
{
	Node* root = NULL;
    int numValues;

    cout << "How many values do you want to insert into the Tree? ";
    cin >> numValues;

    cout << "Enter " << numValues << " values:\n";
    for (int i = 0; i < numValues; i++) {
        float val;
        cin >> val;
        root = insertHeapWise(root, val);  // your original insert function
    }

    cout << "\n Original Tree:\n";
    printTree(root);  
    
    Node* mirror = mirrorImage(root);
    cout << "\n Mirror Tree:\n";
    printTree(mirror);
    
    cout<< "Checking for mirror image:\t";
    if(isMirrorImage(root,mirror))
	{
		cout<< "Both Trees are mirror images" << endl;
		}    
		else
		{
			cout << "Trees are not mirror image" << endl;
		}
     return 0;

}
