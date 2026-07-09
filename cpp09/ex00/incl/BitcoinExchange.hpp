#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <regex>
#include <cmath>

class BitcoinExhange{
	private:
		std::map<std::string, double> _data;
	public:
		BitcoinExhange();
		~BitcoinExhange();
		BitcoinExhange(const BitcoinExhange &other);
		BitcoinExhange& operator=(const BitcoinExhange &other);
		void	loadExchangeRates();
		void	processInputFile(const std::string &arg);
		void	convertBitcoinValue(std::string date, double val);
		void	validDate(std::string date);
		void	validRate(double rate);
};