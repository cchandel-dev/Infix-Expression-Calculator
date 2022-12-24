#pragma once
#include <string>
using namespace std;
class Model
{
public:
	queue<std::string> InfixToPostfix(std::string);
	double EvaluatePostfix(queue<std::string>);
};

