#include "BitcoinExchange.hpp"

BitcoinExhange::BitcoinExhange(){}
BitcoinExhange::~BitcoinExhange(){}
BitcoinExhange::BitcoinExhange(const BitcoinExhange &other): _data(other._data){

}
BitcoinExhange& BitcoinExhange::operator=(const BitcoinExhange &other){
	if (this != &other){
		_data = other._data;
	}
	return *this;

}

void	BitcoinExhange::validDate(std::string date){
	if (date.empty())
		throw std::runtime_error ("Error: bad input => " + date);
}

void	BitcoinExhange::validRate(double rate){
	if (rate < 0)
		throw std::runtime_error ("Error: not a positive number.");
	if (rate > 2147483647)
		throw std::runtime_error ("Error: too large a number.");
}

void BitcoinExhange::loadExchangeRates(){
	std::ifstream data("data.csv");
	if (!data){
		std::cerr << "Error: could not open data.csv file\n";
		return ;
	}
	std::string line; 
	std::getline(data, line);
	while (std::getline(data, line)){
		std::string date;
		double rate;
		size_t pos = line.find(',');
		if (pos == std::string::npos){
			std::cerr << "missing comma on data.csv\n";
			data.close();
			return ;
		}
		try{
			date = line.substr(0, pos);
			validDate(date);
			rate = std::stod(line.substr(pos + 1));
			validRate(rate);
		}
		catch (std::exception &e){
			std::cerr << e.what() << "\n";
			data.close();
			return;
		}
		_data.insert({date, rate});
	}
	data.close();

	// //for testing only block:
	// 		auto it = _data.begin();
	// 		//std::advance(it, 200);
	// 		for (int i = 0; i < 6 && it != _data.end(); ++i, ++it)
	// 			std::cout << it->first << " " << it->second << '\n';

}

void BitcoinExhange::processInputFile(const std::string &arg){
	std::ifstream input(arg);
	if (!input){
		std::cerr << "Error: could not open file\n";
		return ;
	}
	std::string line;
	std::getline(input, line);
	while (std::getline(input, line)){
		size_t pos = line.find("|");
		if (pos == std::string::npos){
			std::cerr << "Error: bad input => " + line + "\n";
			continue;
		}
		try{
		std::string date = line.substr(0, pos - 1);
		double val = std::stod(line.substr(pos + 2));
		validDate(date);
		validRate(val);
		convertBitcoinValue(date, val);
		}
		catch (std::exception &e){
			std::cerr << e.what() << "\n";
		}
		//look up date from _data;
		//getValue()//multiply rate by input val

	}
	input.close();
}
void	BitcoinExhange::convertBitcoinValue(std::string date, double val){

	double rate;
	std::map<std::string, double>::iterator it = _data.upper_bound(date);
	if (it == _data.begin())
		throw std::runtime_error ("Error: bad input => " + date);
	it--;
	rate = it->second;
	std::cout << date << " => " << val << " = " << rate * val << std::endl;
}