#pragma once
#include <string>
#include <queue>
using namespace std;
class Model
{
public:
	std::queue<std::string> InfixToPostfix(std::string);
	double EvaluatePostfix(std::queue<std::string>);
};

