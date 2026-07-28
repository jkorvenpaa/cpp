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
			throw std::runtime_error("invalid argument");
        if (num < 0)
            throw std::runtime_error("invalid argument");
		_vec.push_back(num);
		_deq.push_back(num);
	}
	_elements = _vec.size();
	printVector();
	printDeque();
	
}
void    PmergeMe::startVector(){
    const std::clock_t start = std::clock();
    _vec = sortVector(_vec);
    std::clock_t end = std::clock();
    const processTime(start, end);
}
std::vector<size_t>	PmergeMe::createJacobsthal(const size_t amount){

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
bool    PmergeMe::hasRemainder(const std::vector<int> &vec){
    return !vec.size() % 2 == 0;
}

void PmergeMe::sortVector(const std::vector<int> &vec){
	
	if (vec.size() <= 1)
        return vec;
	std::vector<std::pair <int, int>>pairs;
    std::vector<int> winners;
    int remainder = hasRemainder(vec) ? vec.back() : 0;
    for (size_t i = 0; i + 1 < vec.size(); i += 2){
        if (vec[i] > vec[i + 1])
            pairs.emplace_back(vec[i], vec[i + 1]);
        else
            pairs.emplace_back(vec[i + 1], vec[i]);

        winners.push_back(pairs.back().first);
    }
    winners = sortVector(winners);

	std::vector <std::pair<int, int>>sorted;
    for (size_t i = 0 , i < winners.size(); i++){

    }
	// std::vector<int> main;
	// std::vector<int> pending;
	// for (const std::pair<int, int> &p :pairs){
    // 	main.push_back(p.first);
	// 	pending.push_back(p.second);
	// }
	std::vector<size_t> order = createJacobstahl(pending.size());
}

