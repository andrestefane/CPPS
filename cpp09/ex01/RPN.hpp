#pragma once
#include <stack>
#include <string>
#include <iostream>
#include <limits.h>
#include <sstream>
#include <stdexcept>

class RPN
{
	private:
		std::stack<int> _stack;
		void applyOperator(char p);
	public:
		RPN();
		RPN(const RPN& other);
		RPN &operator=(const RPN &other);
		~RPN();
		int evaluate(const std::string &expression);
		
};