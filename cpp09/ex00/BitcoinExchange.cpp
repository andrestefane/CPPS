#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string& dbFile)
{
	loadDatabase(dbFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_database = other._database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(const std::string& dbFile)
{
	std::ifstream file(dbFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error opening file");

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		std::stringstream ss(line);
		std::string date;
		std::string rateStr;

		if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
			continue;
		double rate = 0.0;
		std::stringstream rateStream(rateStr);
		rateStream >> rate;
		if (rateStream.fail())
			continue;
		_database[date] = static_cast<float>(rate);
	}
	if (_database.empty())
		throw std::runtime_error("database is empty.");
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return (false);
	}
	int year  = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day   = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);

	int daysMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		daysMonth[1] = 29;
	if (day > daysMonth[month - 1])
		return (false);
	return (true);
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, double& outValue) const
{
	std::string trimmed = valueStr;
	size_t start = trimmed.find_first_not_of(" \t");
	size_t end   = trimmed.find_last_not_of(" \t");
	if (start == std::string::npos)
		return (false);
	trimmed = trimmed.substr(start, end - start + 1);

	std::stringstream ss(trimmed);
	ss >> outValue;
	if (ss.fail() || !ss.eof())
		return (false);
	return (true);
}

float BitcoinExchange::getRate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
	if (it != _database.end() && it->first == date)
		return (it->second);
	if (it == _database.begin())
		throw std::runtime_error("no exchange rate available for date: " + date);
	--it;
	return (it->second);
}

void BitcoinExchange::processInput(const std::string& inputFile) const
{
	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error opening file");

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		size_t sep = line.find(" | ");
		if (sep == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date     = line.substr(0, sep);
		std::string valueStr = line.substr(sep + 3);

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		double value = 0.0;
		if (!isValidValue(valueStr, value))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		try
		{
			float rate   = getRate(date);
			double result = value * static_cast<double>(rate);
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}