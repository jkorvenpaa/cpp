#include "Span.hpp"

int main()
{
	try{
		int num = 10000;
		Span sp = Span(num + 1);
		sp.addNumber(-10);
		Span sp2(sp);
		for (int i = 0; i < num; i++){
			sp.addNumber(i);
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
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


// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }