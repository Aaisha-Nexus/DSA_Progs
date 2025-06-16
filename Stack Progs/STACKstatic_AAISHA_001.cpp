#include<iostream> //STATIC STACK IMPLEMENTATION
#define CAPACITY 100 //declaring a maximum size for static array implemenation of stacks
using namespace std;



int stack[CAPACITY]; //globally declaring stack with maximum size
int top=-1; //initializing top with -1 to show its unintialized now (empty)
//function prototypes
void Push();
void Pop();
int Peek();
bool IsEmpty();
bool IsFull();
void DisplayStack();


//function implementation
void Push()
{
	
	if(IsFull())
	{
		cout<< "Stack Overflow! Cannot push more elements";
		return;
	}	
	int val;
	cout<< "Enter the value you want to push?:\t";
	cin>> val;
	stack[++top]= val; //pre increment first moves the top to new empty position and then takes the value top = top + 1;
																									      //stack[top] = value;
	cout<< val << "pushed into stack!" << endl; //increment position of top to +1
	DisplayStack();
}

void Pop() {
    if (IsEmpty()) {
        cout << "Stack Underflow! No elements to pop." << endl;
        return;
    }
    cout << "Popped element: " << stack[top--] << endl; //here we retrieve the last pushed value before moving top down.
    DisplayStack();
}

int Peek() {
    if (IsEmpty()) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return stack[top]; //return the last inserted element
}

bool IsEmpty()
{
    return top==-1;  //the stack is empty
}

bool IsFull()
{
	return top == CAPACITY-1; //actual capacity is 100 but in arrays the index are from 0-99 so capacity -1 means it checks for 99
}

void DisplayStack() {
    if (IsEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Current Stack: [ ";
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << "]" << endl;
}

void Menu() { //menu driven program
    cout << "\nStack Menu:\n"
         << "1) Push\n"
         << "2) Pop\n"
         << "3) Peek\n"
         << "4) Check if Empty\n"
         << "5) Check if Full\n"
         << "6) Display Stack\n"
         << "7) Exit the program\n";
}

int main ()
{
	cout<< "WELCOME TO STACK IMPLEMENTAION USING ARRAYS PROGRAM\t" << endl;
	int option;
	do
	{
		Menu();
		cout<< "Choose the action you want to perform (1-6):\t";
		cin>> option;
	switch(option){
		case 1:
		  	Push();
		  	break;
		 
		case 2:
			Pop();
			break;
		case 3:
			cout<< "Peek function called!" << Peek() << endl;
			break;
		case 4:
			if(IsEmpty())
			{
				cout<< "Stack is Empty!"<< endl;
			}
		    else { 
		        cout<< "Stack is NOT Empty!" << endl;
			}
			break;
		case 5:
				if(IsFull())
			{
				cout<< "Stack is Full!"<< endl;
			}
		    else { 
		        cout<< "Stack is NOT Full!" << endl;
			}
			break;
                
            case 6:
                DisplayStack();
                break;
                
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid option! Choose again." << endl;
            }
	} while(option!=7);
		return 0;
}
	

