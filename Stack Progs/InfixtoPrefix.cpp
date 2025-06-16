// infix to prefix code
/* here step1: reverse the inputted string and also cjange opening bracket to close and vice versa ( -> ) and ) - > (
    step 2: convert the reversed string into postfix (using stacks original logic)*
	step 3 : finally reverse postfix expression so get resultant prefix */
#include<iostream>
#include<cctype>
using namespace std;

#define CAPACITY 100
char stack [CAPACITY];
int top = -1;

bool isfull()
{
	return top==CAPACITY-1;
}

bool isempty()
{
	return top==-1;
}

char pop()
{
	if(isempty())
	{
		cout<< "Stack underflow! Can't pop!" << endl;
		return '\0'; //here returning \0 because of char if it returns -1 it will give garbage value because of int 
	}
	return stack[top--];
}

void push(char val)
{
	if(isfull())
	{
		cout<< "Stack Overflow! Can't push!" << endl;
		return;
	}
  stack[++top]=val;
}

char peek() {
	if(!isempty())
	{
		return stack[top];
	}
	else return '\0';
}

int precedence(char op)
{
	if (op== '^') return 3;
	else if (op=='*' || op=='/') return 2;
	else if (op=='+' || op=='-') return 1;
	else return 0;
}

string reverseAndSwap(string exp) //to revrse and swap the opening and closing bracket for first step of prefix 
	 {
    string revExp = "";
    for (int i = exp.length() - 1; i >= 0; i--) {
        if (exp[i] == '(')
            revExp += ')';
        else if (exp[i] == ')')
            revExp += '(';
        else
            revExp += exp[i];
    }
    return revExp;
}

int main()
{
	cout << "*INFIX TO PREFIX CONVERTOR" << endl;
	cout<< "Enter the Infix expression:\t";
	string exp;
	getline(cin,exp); //first take the input
	
	//then reverse the input
	string revexp = reverseAndSwap(exp); 
    cout << " Step 1 : Reversed and swapped expression: " << revexp << endl;

    string postfix = "";
    for(int i=0 ; i <revexp.length() ; i++)
    {
    	char ch=revexp[i];
    	
    	if(isalnum(ch)) //if a alphabet or character is found then add it to postfix expression
    	{
    		postfix+=ch;
		}
		else if (ch=='(') //if right bracket then push into stack  
		{
			push(ch);
		}
		else if(ch==')') //if left bracket is found ; same here
		{
		while(!isempty() && peek() != '(' ) //keep popping until right bracket is found 
		{
			postfix+=pop(); //keep popping and adding to postfix expression 
		}
		pop(); //finally pop right bracket ( as well 
		}
		else
		{ // <= nhi aye gha
			while(!isempty() && peek() != '(' && precedence(ch) < precedence(peek())) //then check tthe precedence of current and top of stack operator if less or equal
			{
				postfix+=pop(); //pop if less and add it to postfix exp
			}
			push(ch); //and then push 
		}
			
}
	while (!isempty()) {
		postfix += pop();
	}
	
	cout << "Step 2: Postfix Expression: " << postfix << endl;
	
	//fnally reversing postfix expression into prefix 
    string prefix = "";
    for(int i = postfix.length() - 1; i >= 0; i--) {
        prefix += postfix[i];
    }

    cout << "Step 3: Prefix Expression: " << prefix << endl;

	return 0;

}

