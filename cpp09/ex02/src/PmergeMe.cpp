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
void    PmergeMe::processVector(){
    const std::clock_t start = std::clock();
    sortVector(_vec);
	printVector();
    const std::clock_t end = std::clock();
    processTime(start, end);
}
std::vector<size_t>	PmergeMe::createJacobsthal(const size_t amount){

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
	std::vector<size_t> jacob;
	std::vector<size_t> order;
	if (amount == 0)
		return order;
	int a = 0;
	int b = 1;
	order.push_back(a);
	for (size_t i = 2; i <= amount; i++){
		size_t num = b + 2 * a;
		jacob.push_back(num);
		a = b;
		b = num;
	}
	
	size_t i = 1;
	for(std::vector<size_t>::iterator it = jacob.begin(); it != jacob.end(); it++){
		std::vector<size_t> group;
		while (i <= *it && i < amount){
			group.push_back(i);
			i++;
		}
		std::reverse(group.begin(), group.end());
		order.insert(order.end(), group.begin(), group.end());
	}
	while (i < amount)
        order.push_back(i++);
	for (std::vector<size_t>::iterator it = order.begin(); it != order.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return order;
}

std::vector<int>&  PmergeMe::binaryInsert(size_t index, std::vector<int> &main, std::vector <std::pair<int, int>> sorted){

	int bound = sorted[index].first;
	int pending = sorted[index].second;


	for (size_t i = 0; i < main.size(); i++)
	{
		if (main[i] == bound)
		{
			index = i;
			break;
		}
	}
	size_t i = 0;
	while (i < index && pending > main[i])
		i++;

	main.insert(main.begin() + i, pending);

	return main;


	// for (size_t i = 0; i < main.size(); i++){
	// 	if (bound == main[i]){
	// 		main.insert(main.begin() + i, pending);
	// 		break;
	// 	}
	// 	std::cout << "bound: " << bound << " main[i]: " << main[i] << " pending: " << pending <<std::endl; 
	// 	if (pending <= main[i]){
	// 		main.insert(main.begin() + i, pending);
	// 		break;
	// 	}
	// }
	// return main;
}


void PmergeMe::sortVector(std::vector<int> &vec){
	
	if (vec.size() <= 1)
        return ;
	std::vector<std::pair <int, int>>pairs;
    std::vector<int> winners;
	bool hasRemainder = vec.size() % 2 != 0;
    int remainder;
	remainder = hasRemainder ? vec.back() : 0;
    for (size_t i = 0; i + 1 < vec.size(); i += 2){
        if (vec[i] > vec[i + 1])
            pairs.emplace_back(vec[i], vec[i + 1]);
        else
            pairs.emplace_back(vec[i + 1], vec[i]);
		
    }
	for (size_t i = 0; i < pairs.size(); i++)
	{
		winners.push_back(pairs[i].first);
	}
	
    sortVector(winners);

	std::vector <std::pair<int, int>>sorted;
    for (size_t i = 0 ; i < winners.size(); i++){
		for (size_t j = 0; j < pairs.size(); j++)
			if (winners[i] == pairs[j].first){
				sorted.push_back(pairs[j]);
				pairs.erase(pairs.begin()+ j);
				break;
			}				
	}
	
	std::vector<int> main;
	std::vector<int> pending;
	for (size_t i = 0; i < winners.size(); i++){
    	main.push_back(sorted[i].first);
		pending.push_back(sorted[i].second);
	}

	std::vector<size_t> order = createJacobsthal(pending.size());
	std::cout << "order: ";
	for (std::vector<size_t>::iterator it = order.begin(); it != order.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < order.size(); i++){
		main = binaryInsert(order[i], main, sorted);
	}
	if (hasRemainder){
		size_t i = 0;
		while (i < main.size() && main[i] < remainder)
			i++;
		main.insert(main.begin() + i, remainder);
	}
	vec = main;
}

