#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>
#include <exception>

enum type
{
	CHAR,
	INT,
	DOUBLE,
	FLOAT,
	ERROR
};

bool isSpecial(const std::string &input);
bool isChar(const std::string &input);
bool isInt(const std::string &input);
bool isFloat(const std::string &input);
bool isDouble(const std::string &input);
type parse(const std::string &input);
double toDouble(const std::string &input, type _type);

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
		~ScalarConverter();
	public:
		static void convert(const std::string &str);
		class InvalidInputException : public std::exception
		{
			virtual const char *what() const throw();
		};
};