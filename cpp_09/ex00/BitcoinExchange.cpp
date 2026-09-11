#include "BitcoinExchange.hpp"

#include <fstream>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <chrono>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) 
		_rates = other._rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData(const std::string& filename) {
	std::ifstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: could not open data file.");

	std::string line;

	// Skip header line
	std::getline(file, line);

	// Read and extract data line by line
	// Example line: yyyy-mm-dd,rate
	// 2010-10-07,0.06
	while (std::getline(file, line)) {
		size_t commaPos = line.find(',');

		if (commaPos == std::string::npos)
			throw std::runtime_error("Error: invalid data.");

		std::string date = line.substr(0, commaPos);
		std::string rateStr = line.substr(commaPos + 1);

		if (date.empty() || rateStr.empty() )
			throw std::runtime_error("Error: invalid data.");

		if (!isValidDate(date))
			throw std::runtime_error("Error: invalid data.");
		
		size_t pos;
		double rate;
		try {
			rate = std::stod(rateStr, &pos);
		}
		catch (const std::exception& e) {
			throw std::runtime_error("Error: invalid data.");
		}
		
		// Make sure the entire string was a valid positive number
		if (pos != rateStr.length() || rate < 0)
			throw std::runtime_error("Error: invalid data.");
				
		// Store date and exchange rate in map
		_rates[date] = rate;
	}
}

void BitcoinExchange::processInput(const std::string& filename) {
	std::ifstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: could not open input file.");

	std::string line;

	// Skip header line: "date | value"
	std::getline(file, line);

	while (std::getline(file, line)) {
		std::istringstream iss(line);

		std::string	date;		// "2011-01-03"
		char		separator;	// "|"
		double		value;		// "3.5"

		// Extract date, separator, value. Whitespace skipped.
		if (!(iss >> date >> separator >> value) || separator != '|') {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		// Make sure no extra content after 'value'
		std::string extra;
		if (iss >> extra) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		// Validate date
		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		// Value must not exceed 1000
		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}

		// Value must not be negative
		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}

		try {
			double rate = getRate(date);

			std::cout << date << " => " << value << " = " << (value * rate) << std::endl; 
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	// Must be exactly YYYY-MM-DD
	if (date.length() != 10)
		return false;

	// '-' must be in the correct positions
	if (date[4] != '-' || date[7] != '-')
		return false;

	// All other characters must be digits
	for (size_t i = 0; i < date.length(); i++) {
		if (i == 4 || i == 7)
			continue;

		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	try {
		int year = std::stoi(date.substr(0, 4));
		unsigned int month = std::stoi(date.substr(5, 2));
		unsigned int day = std::stoi(date.substr(8, 2));

		std::chrono::year_month_day ymd{
			std::chrono::year{year},
			std::chrono::month{month},
			std::chrono::day{day}
		};

		return ymd.ok();
	}
	catch (const std::exception& e) {
		return false;
	}
}

double BitcoinExchange::getRate(const std::string& date) const {
	// Find first key  that is greater than or equal to 'date', 
	std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);

	// Exact date found
	if (it != _rates.end() && it->first == date)
		return it->second;

	// Request date is earlier than the first date in the database
	if (it == _rates.begin())
		throw std::runtime_error("Error: no exchange rate available.");

	// move to the closest earlier date
	--it;

	return it->second;
}