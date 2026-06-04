#include "Span.hpp"

int main()
{
	try{
		Span sp = Span(20);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		Span sp2(sp);
		std::vector v = {100,1000,1};
		sp2.insertNumbers(v);
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception &e){
		std::cerr << e.what() << "\n";

	}
return 0;
}