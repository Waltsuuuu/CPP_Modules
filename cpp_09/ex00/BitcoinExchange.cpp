#include "BitcoinExchange.hpp"

#include <fstream>
#include <stdexcept>

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
			
		try {
			size_t pos;
			double rate = std::stod(rateStr, &pos);

			// Make sure the entire string was a valid number
			if (pos != rateStr.length())
				throw std::runtime_error("Error: invalid data.");

			// Store date and exchange rate in map
			_rates[date] = rate;
		}
		catch (const std::exception& e) {
			throw std::runtime_error("Error: invalid data.");
		}
	}
}