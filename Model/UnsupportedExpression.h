#pragma once
#include <exception>
#include <string>

using namespace std;
class UnsupportedExpression : public std::exception
{
public:
    inline UnsupportedExpression()
        : m_message("This expression may not be supported by the default implementation of the Calculator.")
    {
    }

    inline virtual const char* what() const throw()
    {
        return m_message.c_str();
    }

private:
    std::string m_message;
};

