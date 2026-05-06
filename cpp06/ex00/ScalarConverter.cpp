#include "ScalarConverter.hpp"

const std::string specials[6] =
{
	"nan", "-inf", "+inf", "nanf", "-inff", "+inff"
};

ScalarConverter::ScalarConverter(void)
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{

}

type parse(const std::string &input)
{
    if (isSpecial(input))
        return (FLOAT);
    if (isChar(input))
        return (CHAR);
    if (isInt(input))
        return (INT);
    if (isFloat(input))
        return (FLOAT);
    if (isDouble(input))
        return (DOUBLE);
    return (ERROR);
}

bool isSpecial(const std::string &input)
{
	int i = 0;
	while (i < 6)
	{
		if (input == specials[i])
			return (true);
		i++;
	}
	return (false);
}

bool isChar(const std::string &input)
{
	return(input.length() == 1 && !isdigit(input[0]));
}

bool isInt(const std::string &input)
{
	int i = 0;
	if (input[0] == '+' || input[0] == '-')
		i++;
	while (i < (int)input.length())
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	return (true);
}

bool isDouble(const std::string &input)
{
	int i = 0;
	int counter = 0;
	if (input == "-inf" || input == "+inf" || input == "nan")
		return (true);
	if (input[0] == '+' || input[0] == '-')
		i++;
	while (i < (int)input.length())
	{
		if (!isdigit(input[i]) && input[i] != '.')
			return (false);
		if (input[i] == '.')
			counter++;
		if (counter > 1)
			return(false);
		i++;
	}
	if (counter != 1)
		return (false);
	return (true);
}

bool isFloat(const std::string &input)
{
	int i = 0;
	int counter = 0;
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (true);
	if (input[input.length() - 1] != 'f' || (input.length() == 2 && !isdigit(input[0])))
		return (false);
	if (input[0] == '+' || input[0] == '-')
		i++;
	while (i < (int)input.length() - 1)
	{
		if (!isdigit(input[i]) && input[i] != '.')
			return (false);
		if (input[i] == '.')
			counter++;
		if (counter > 1)
			return (false);
		i++;
	}
	return (true);
}

double toDouble(const std::string &input, type _type)
{
	if (_type == CHAR)
		return (static_cast<double>(input[0]));
	if (_type == INT)
		return (static_cast<double>(std::atoi(input.c_str())));
	if (_type == FLOAT)
		return (static_cast<double>(std::atof(input.c_str())));
	return(std::atof(input.c_str()));
}

static void printChar(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(double value)
{
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value) ||
		value < std::numeric_limits<int>::min() ||
		value > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(double value)
{
	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1)
					<< static_cast<float>(value) << "f" << std::endl;
}

static void printDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1)
					<< value << std::endl;
}

void	ScalarConverter::convert(const std::string &str)
{
	type _type = parse(str);
	if (_type == ERROR)
		throw ScalarConverter::InvalidInputException();
	double value = toDouble(str, _type);
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

char const	*ScalarConverter::InvalidInputException::what(void) const throw()
{
	return ("Invalid input :(");
}
