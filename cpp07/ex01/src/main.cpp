#include "iter.hpp"


int	main(void){

	const int len = 3;
	char charArr[len] = {'h','i','!'};
	iter(charArr, len, print<char>);
	iter(charArr, len, increment<char>);
	iter(charArr, len, print<char>);
	std::cout << std::endl;

	int intArr[len] = {1, 2, 3};
	iter(intArr, len, print<int>);
	iter(intArr, len, increment<int>);
	iter(intArr, len, print<int>);
	std::cout << std::endl;

	double doubArr[len] = {0, 1.5, 3};
	iter(doubArr, len, print<double>);
	iter(doubArr, len, increment<double>);
	iter(doubArr, len, print<double>);
	std::cout << std::endl;

	return 0;
}