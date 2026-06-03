#include "easyfind.hpp"

int	main(void){
	std::vector<int> v1{1, 2, 3, 4};
	try{
		std::vector<int>::iterator it = easyfind(v1, 3);
		std::cout << *it << std::endl;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << '\n';
	}

	std::array<int, 4> v2{1, 2, 3, 4};
	try{
		std::array<int, 4>::iterator it = easyfind(v2, 3);
		std::cout << *it << std::endl;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << '\n';
	}

	std::deque<int> v3{1, 2, 3, 4};
	try{
		std::deque<int>::iterator it = easyfind(v3, 3);
		std::cout << *it << std::endl;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	return 0;
}