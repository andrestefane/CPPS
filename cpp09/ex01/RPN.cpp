#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN &other) : _stack(other._stack)
{

}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

RPN::~RPN()
{
	
}

void RPN::applyOperator(char op)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error");

    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();

    if (op == '/' && b == 0)
        throw std::runtime_error("Error: division by zero");
    if (op == '+')
    {
        if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b))
            throw std::runtime_error("Error: overflow");
        _stack.push(a + b);
    }
    else if (op == '-')
    {
        if ((b < 0 && a > INT_MAX + b) || (b > 0 && a < INT_MIN + b))
            throw std::runtime_error("Error: overflow");
        _stack.push(a - b);
    }
    else if (op == '*')
    {
        if (a != 0 && b > INT_MAX / a)
            throw std::runtime_error("Error: overflow");
        _stack.push(a * b);
    }
    else if (op == '/')
        _stack.push(a / b);
}
int RPN::evaluate(const std::string &expression)
{
	std::stringstream string(expression);
	std::string token;

	while (string >> token)
	{
		if (token.size() == 1 && isdigit(token[0]))
			_stack.push(token[0] - '0');
		else if (token == "+" || token == "-"
				|| token == "*" || token == "/")
			applyOperator(token[0]);
		else
			throw std::runtime_error("Error");
	}
	if (_stack.size() != 1)
			throw std::runtime_error("Error");
	return (_stack.top());
}

