#pragma once
#include <string>
#include <iostream>
using namespace std;
class View
{
private:
	int requestsSinceInception;
	std::string expression;
public:
	inline void displayAnswer(double& output) { std::cout << expression + " = " + to_string(output) << std::endl; }
	inline std::string getInput() { std::cout << "Enter a math expression\n"; std::cin >> expression; requestsSinceInception++; return expression; }
};

