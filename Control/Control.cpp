// Control.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <Model.cpp>
#include "View.h"

int main()
{
    View v;
    Model m;
    while (true) {
        std::string input = v.getInput();
        double output;
        try {
            std::queue<std::string> postfix = m.InfixToPostfix(input);
            output = m.EvaluatePostfix(postfix);
            v.displayAnswer(output);
        }
        catch (...) {
            std::unordered_map<char, std::string> http_reserved_chars = {
                {';', "%3B"},
                {'/', "%2F"},
                {'?', "%3F"},
                {':', "%3A"},
                {'@', "%40"},
                {'&', "%26"},
                {'=', "%3D"},
                {'+', "%2B"},
                {'$', "%24"},
                {',', "%2C"},
                {'!', "%21"},
                {'*', "%2A"},
                {'\'', "%27"},
                {'(', "%28"},
                {')', "%29"},
            };
            std::string query;
            for (int i = 0; i < input.length(); i++) {
                query += http_reserved_chars.find(input[i]) != http_reserved_chars.end() ? http_reserved_chars[input[i]] : std::string(1, input[i]);
            }
            std::string str = "curl -X POST \"https://api.wolframalpha.com/v1/result\" -d \"appid=8Y744E-VKQPLPQ2P4&i=" + query + "\"";
            const char* cstr = str.c_str();

            cout << "****This expression contains unsupported operations, Wolfram Alpha API will be used instead.****" << endl;
            cout << input + " = ";
            system(cstr);
            cout << "\n\n" << endl;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
