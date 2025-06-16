// postfix evaluation code 
#include<iostream>
#include<cstdlib>
#include<cctype>
using namespace std;

#define CAPACITY 100
int stack[CAPACITY];
int top = -1; //initialise top with -1 to show it in empty now 

bool isfull() //to check if the stack is full
{
	return top==CAPACITY-1;
}

bool isempty() //to check is stack is empty
{
	return top==-1;
}

int pop()
{
	if(isempty())
	{
		cout<< "Stack underflow! Stack is empty , cannot pop!" << endl;
		return -1;
	}
	
	return stack[top--]; //return top element and decreases it 

}

void push(int val)
{
	if(isfull())
	{
		cout<< "Stack overflow! Cannot push !" << endl;
		return;
	}
	
	stack[++top]=val; //push the value and update top
}
int main()
{
	cout<< "*********POSTFIX EVALUTAION**********" << endl;
	string exp;
	cout << "Enter the mathematical expression:\t" << endl;
	getline(cin,exp);
	
	for(int i=0; i<exp.length(); i++) //in postfix start from left to right 0->n 
	 {
    if(isdigit(exp[i])) 
	{
        push(exp[i] - '0');  // or push(exp[i] - 48) means if 2 is 50 so 50-48=2 
    } 
	else
	 {
        int op1, op2, result;
        switch(exp[i]) //checks for operators
		 {
            case '+':
                op1 = pop();
                op2 = pop();
                result = op2 + op1;
                push(result);
                break;
            case '-':
                op1 = pop();
                op2 = pop();
                result = op2 - op1;
                push(result);
                break;
            case '*':
                op1 = pop();
                op2 = pop();
                result = op2 * op1;
                push(result);
                break;
            case '/':
                op1 = pop();
                op2 = pop();
                result = op2 / op1;
                push(result);
                break;
            case '%':
                op1 = pop();
                op2 = pop();
                result = op2 % op1;
                push(result);
                break;
            default:
                cout << "Invalid operator: " << exp[i] << endl;
        }
    }
}


		{
			cout<< "THE RESULT IS :\t " << pop() << endl;
		}		
	return 0;
}
