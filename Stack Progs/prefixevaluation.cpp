// prefix evaluation code 
#include<iostream>
#include<cstdlib>
#include<cctype>
using namespace std;

#define CAPACITY 100
int stack[CAPACITY];
int top = -1; //initialise top with -1 to show it in empty now 

bool isfull()
{
	return top==CAPACITY-1;
}

bool isempty()
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
	
	return stack[top--];

}

void push(int val)
{
	if(isfull())
	{
		cout<< "Stack overflow! Cannot push !" << endl;
		return;
	}
	
	stack[++top]=val;
}
int main()
{
	cout<< "*********PREFIX EVALUTAION**********" << endl;
	string exp;
	cout << "Enter the mathematical expression:\t" << endl;
	getline(cin,exp);
	
	for(int i=exp.length()-1; i>=0; i--) //in prefix it goes from right to left so n->0 so decrease and lenth()-1 bcz 
	 {
    if(isdigit(exp[i])) 
	{
        push(exp[i] - '0');  // or push(exp[i] - 48);
    } 
	else
	 {
        int op1, op2, result;
        switch(exp[i])
		 {
            case '+':
                op1 = pop();
                op2 = pop();
                result = op1 + op2;
                push(result);
                break;
            case '-':
                op1 = pop();
                op2 = pop();
                result = op1 - op2;
                push(result);
                break;
            case '*':
                op1 = pop();
                op2 = pop();
                result = op1 * op2;
                push(result);
                break;
            case '/':
                op1 = pop();
                op2 = pop();
                result = op1 / op2;
                push(result);
                break;
            case '%':
                op1 = pop();
                op2 = pop();
                result = op1 % op2;
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
