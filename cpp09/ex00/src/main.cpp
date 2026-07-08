#include "BitcoinExchange.hpp"

int main (int ac, char **av){
	if (ac != 2){
		std::cerr << "Error: could not open file.\n";
		return 1;
	}
	BitcoinExhange be;
	be.loadExchangeRates();
	be.processInputFile(av[1]);
	return 0;
}