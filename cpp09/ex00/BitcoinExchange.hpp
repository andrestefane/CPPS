#pragma once
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class BitcoinExchange
{
	std::map<std::string, float>_database;
		void loadDatabase(const std::string& dbFile);
		bool isValidDate(const std::string& data)const;
		bool isValidValue(const std::string& valueStr, double& outValue) const;
		float getRate(const std::string& date)const;
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& dbFile);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		void processInput(const std::string& inputFile)const;
};