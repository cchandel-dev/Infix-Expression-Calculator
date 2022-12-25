#include "Model.h"
#include <stack>
#include <cctype>
#include <unordered_map>
#include <cmath>
//Use the Shunting Yard Algorithm to simplify this Infix expression to a Postfix format.
std::queue<std::string> Model::InfixToPostfix(std::string input) {
	//Create an empty stack for holding operators and a queue for holding the output.
	stack<std::string> holdOperators;
	queue<std::string> output;
	unordered_map<std::string, int> precedence = { {"+", 0}, {"-", 0}, {"*", 1}, {"x", 1}, {"/", 1}, {"\\", 1}, {"%", 1}, {"^",2} };
	std::string token;
	for (char ch : input) {
		if (isdigit(ch)) {
			token += ch;
		}
		else {
			if (token != "") {
				output.push(token);
				token = "";
			}
			//If the char is a left parenthesis, push it onto the stack.
			if (ch == '(')
				holdOperators.push(std::string(1, ch));
			/*If the token is a right parenthesis:
				>Pop the stack and add each operator to the queue until you reach a left parenthesis.
				>Discard the left and right parentheses.
			*/
			if (ch == ')') {
				while (holdOperators.top() != "(") {
					output.push(holdOperators.top());
					holdOperators.pop();
				}
				holdOperators.pop();//ignore ch and don't add it and get rid of left side parenthesis.
			}
			/*
			If the current character is an operator, push it onto the operator stack.
			However, before doing so, you must check if there are any operators on the operator stack with higher precedence.
			If there are, pop them off the stack and add them to the output queue before pushing the new operator onto the stack.
			*/
			if (ch == '+' || ch == '-' || ch == 'x' || ch == '*' || ch == '/' || ch == '\\' || ch == '%' || ch == '^') {
				while (holdOperators.size() != 0 && holdOperators.top() != "("&& precedence[holdOperators.top()]  > precedence[std::string(1, ch)]) {
						output.push(holdOperators.top());
						holdOperators.pop();
				}
				holdOperators.push(std::string(1, ch));
			}
		}

	}
	if (token != "")
		output.push(token);
	//At the end, pop any remaining operators off the operator stack and add them to the output queue.
	while (holdOperators.size()) {
		output.push(holdOperators.top());
		holdOperators.pop();
	}
	return output;
}

bool isNumber(const string& s)
{
	try
	{
		stod(s);
		return true;
	}
	catch (exception) {
		return false;
	}
}
double Model::EvaluatePostfix(std::queue<std::string> input) {
	//Create an empty stack
	std::stack<double> operands;
	/*
	Iterate through each token in the expression:
		If the token is an operand, push it onto the stack.
		If the token is an operator, pop the top two operands from the stack, 
		perform the operation using the operands, and push the result back onto the stack.
	*/
	while (input.size()) {
		if (isNumber(input.front()))
		{
			operands.push(stod(input.front()));
		}
		else {
			std::string operation = input.front();
			double operand2 = operands.top();
			operands.pop();
			double operand1 = operands.top();
			operands.pop();
			switch (operation.at(0)) {
				case '+': operands.push(operand1 + operand2); break;
				case '-': operands.push(operand1 - operand2); break;
				case '*': operands.push(operand1 * operand2); break;
				case 'x': operands.push(operand1 * operand2); break;
				case '/': operands.push(operand1 / operand2); break;
				case '%': operands.push(fmod(operand1, operand2)); break;
				case '\\': operands.push(double(int(operand1 / operand2))); break;
				case '^':  operands.push(pow(operand1, operand2)); break;
			}
		}
		input.pop();
	}
	//After all tokens have been processed, the result will be the top element of the stack.
	return operands.top();
}