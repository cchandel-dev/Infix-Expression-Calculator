#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <queue>
#include "Model.cpp"
#include "View.h"
#include <queue>
#include <stack>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(ModelInfixCoversion)
		{
			Model m;
			std::queue<std::string> rpn = m.InfixToPostfix("((1+2)*3)^2*(1+2)");
			std::string arr[] = { "1","2","+","3","*","2","^","1","2","+","*" };
			for (std::string token : arr) {
				Assert::AreEqual(rpn.front(), token);
				rpn.pop();
			}
		}
		TEST_METHOD(EvaluatePostfix)
		{
			Model m;
			std::queue<std::string> rpn;
			std::string arr[] = { "1","2","+","3","*","2","^","1","2","+","*" };
			for (std::string token : arr) {
				rpn.push(token);
			}
			double val = m.EvaluatePostfix(rpn);
			Assert::AreEqual(val, 243.0);
		}
	};
}
