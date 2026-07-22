#include "PmergeMe.hpp"

PmergeMe&	PmergeMe::operator=(const PmergeMe &other){
	if (this!= &other){
		_vec = other._vec;
		_deq = other._deq;
		_elements = other._elements;
	}
	return *this;
}

void	PmergeMe::printVector(){
	std::cout << "vector: ";
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printDeque(){
	std::cout << "deque: ";
	for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::processTime(const std::clock_t start, const std::clock_t end)//cpu time
{
	double us = (end - start) * 1000000.0 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _elements << " elements with std::[..] : " << us << " us\n";
}

void PmergeMe::parseInput(int ac, char** av){

	for (int i = 1; i < ac ; i++){
		size_t pos;
		std::string str = av[i];
		int num = std::stoi(str, &pos);
		if (pos != str.size())
			throw std::runtime_error("invalid argument\n");
		_vec.push_back(num);
		_deq.push_back(num);
	}
	_elements = _vec.size();
	printVector();
	printDeque();
	sortPairsVector();
}

std::vector<size_t>	PmergeMe::createJacobstahl(const size_t amount){

	std::vector<size_t> jacob;
	int a = 0;
	int b = 1;
	//jacob.push_back(a);
	for (size_t i = 2; i <= amount; i++){
		int num = b + 2 * a;
		jacob.push_back(num);
		a = b;
		b = num;
	}
	std::cout << "jacob ";
	for (std::vector<size_t>::iterator it = jacob.begin(); it != jacob.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;


// Your indexes are:
// 0 1 2 3 4 5 6 7 8 9
// Take Jacobsthal endpoints:
// 1, 3, 5, 11
// Stop when the endpoint is bigger than the amount of elements.

// Groups by end points:
// [0]
// [1,2]
// [3,4]
// [5,6,7,8,9]
// reverse groups and concatenate
// 0, 2, 1, 4, 3, 9, 8, 7, 6, 5
// = insertion index order

	std::vector<size_t> order;
	size_t i = 0;
	for(std::vector<size_t>::iterator it = jacob.begin(); it != jacob.end(); it++){
		std::vector<size_t> group;
		while (i < *it){
			group.push_back(i);
			i++;
		}
		std::reverse(group.begin(), group.end());
		order.insert(order.end(), group.begin(), group.end());
	}

	std::cout << "order ";
	for (std::vector<size_t>::iterator it = order.begin(); it != order.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return order;
}

void PmergeMe::sortPairsVector(){
	//std::clock_t startV = std::clock();
	//add only one element rule!!
	std::vector<std::pair <int, int> >pairs;
	int remainder = -1;
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it+=2){
		if (it + 1  == _vec.end())
			remainder = *it;
		else if (*it > *(it + 1)){
			pairs.emplace_back(*it, *(it+1));
		}
		else{
			pairs.emplace_back(*(it+1), *it);
		}
	}
	std::sort(pairs.begin(), pairs.end());
	std::vector<int> main;
	std::vector<int> pending;
	for (const std::pair<int, int> &p :pairs){
    	main.push_back(p.first);
		pending.push_back(p.second);
	}
	std::vector<size_t> order = createJacobstahl(pending.size());
}

