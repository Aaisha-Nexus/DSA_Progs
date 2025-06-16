//Infix to Postfix using stacks 
#include<iostream>
#include<cctype>
using namespace std;

#define CAPACITY 100
char stack[CAPACITY];
int top = -1;

bool isfull() {
	return top == CAPACITY - 1;
}

bool isempty() {
	return top == -1;
}

char pop() {
	if (isempty()) {
		cout << "Stack underflow!" << endl;
		return -1;
	}
	return stack[top--];
}

void push(char val) { //char value because it can be a alphabet or number 
	if (isfull()) {
		cout << "Stack overflow!" << endl;
		return;
	}
	stack[++top] = val;
}

char peek() {
	if (!isempty())
		return stack[top];
	else
		return '\0';
}

int precedence(char op) { //returning values based on precedence to check later 
	if (op == '^')
		return 3;
	else if (op == '*' || op == '/')
		return 2;
	else if (op == '+' || op == '-')
		return 1;
	else
		return 0;
}

int main() {
	cout << "*********INFIX TO POSTFIX CONVERSION**********" << endl;
	string exp;
	cout << "Enter infix expression: ";
	getline(cin, exp);

	string postfix = "";

	for (int i = 0; i < exp.length(); i++) {
		char ch = exp[i];

		if (isalnum(ch)) { // if operand, directly add to postfix (isalnum) is pre defined and it checks for characters and numbers 
			postfix += ch;
		}
		else if (ch == '(') { //if '(' is encountered then push it to stack
			push(ch);
		}
		else if (ch == ')') { //if ')' is found then start popping until u find right bracket and add it to postfix expression
			while (!isempty() && peek() != '(') { //peek is used to see if '(' is at the top of stack or not 
				postfix += pop();
			}
			pop(); // pop the '('
		}
		else { // operator
			while (!isempty() && precedence(ch) <= precedence(peek())) { //if the current operator is less than or equal to opertor on top of stack then first pop it and then push 
				postfix += pop(); //pop it and add it to expression
			}
			push(ch); //push the current operator
		}
	}

	// pop remaining operators
	while (!isempty()) {
		postfix += pop();
	}

	cout << "The POSTFIX expression is: " << postfix << endl;

	return 0;
}

