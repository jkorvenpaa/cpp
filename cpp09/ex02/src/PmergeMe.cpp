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

void	PmergeMe::processTime(const std::clock_t start, const std::clock_t end, const std::string type)//cpu time
{
	double us = (end - start) * 1000000.0 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _elements << " elements with std::[" << type << "] : " << us << " us\n";
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
    processTime(start, end, "vector");
}
void    PmergeMe::processDeque(){
    const std::clock_t start = std::clock();
    sortDeque(_deq);
	printDeque();
    const std::clock_t end = std::clock();
    processTime(start, end, "deque");
}
std::deque<size_t>	PmergeMe::createJacobsthalDeque(const size_t pendingCount){
// while endpoint < amount of indexes you need:
// Take Jacobsthal sequence(next = current + 2 * previous):
// Group by end points, reverse groups and concatenate
// = insertion index order
	std::deque<size_t> jacob;
	std::deque<size_t> order;

	if (pendingCount == 0)
		return order;
	order.push_back(0);
	
	size_t a = 0;
	size_t b = 1;
	size_t prevGroup = 1;

	while (1){
		size_t num = b + 2 * a;
		if (num > pendingCount)
        	break;
		jacob.push_back(num);
		a = b;
		b = num;
	}
	for(size_t i = 0; i < jacob.size(); i++){
		for (size_t group = jacob[i]; group > prevGroup; group--){
			order.push_back(group -1);
		}
		prevGroup = jacob[i];
	}
	for (size_t group = pendingCount; group > prevGroup; group--)
    	order.push_back(group - 1);
	return order;
}
std::vector<size_t>	PmergeMe::createJacobsthal(const size_t pendingCount){
// while endpoint < amount of indexes you need:
// Take Jacobsthal sequence(next = current + 2 * previous):
// Group by end points, reverse groups and concatenate
// = insertion index order
	std::vector<size_t> jacob;
	std::vector<size_t> order;

	if (pendingCount == 0)
		return order;
	order.push_back(0);

	size_t a = 0;
	size_t b = 1;
	size_t prevGroup = 1;

	while (1){
		size_t num = b + 2 * a;
		if (num > pendingCount)
        	break;
		jacob.push_back(num);
		a = b;
		b = num;
	}
	for(size_t i = 0; i < jacob.size(); i++){
		for (size_t group = jacob[i]; group > prevGroup; group--){
			order.push_back(group -1);
		}
		prevGroup = jacob[i];
	}
	for (size_t group = pendingCount; group > prevGroup; group--)
    	order.push_back(group - 1);
	return order;
}
std::deque<int>&  PmergeMe::binaryInsertDeque(std::deque<int> &main, int bound, int pending){
	//search mainchain within bound( = pair's winner)
	//binary search: move scope based on pending compared to middle value; 

	size_t rightIndex = 0;
	size_t leftIndex = 0;

	while (rightIndex < main.size() && main[rightIndex] != bound)
		rightIndex++;
	while(leftIndex < rightIndex){
		size_t mid = leftIndex + (rightIndex - leftIndex) / 2;
		if (main[mid] < pending)
			leftIndex = mid + 1;
		else
			rightIndex = mid;
	}
	main.insert(main.begin() + leftIndex, pending);
	return main;
}

std::vector<int>&  PmergeMe::binaryInsert(std::vector<int> &main, int bound, int pending){
	//search mainchain within bound( = pair's winner)
	//binary search: move scope based on pending compared to middle value; 

	size_t rightIndex = 0;
	size_t leftIndex = 0;

	while (rightIndex < main.size() && main[rightIndex] != bound)
		rightIndex++;
	while(leftIndex < rightIndex){
		size_t mid = leftIndex + (rightIndex - leftIndex) / 2;
		if (main[mid] < pending)
			leftIndex = mid + 1;
		else
			rightIndex = mid;
	}
	main.insert(main.begin() + leftIndex, pending);
	return main;
}
void PmergeMe::sortDeque(std::deque<int> &vec){
	if (vec.size() <= 1)
        return ;
	std::deque<std::pair <int, int>>pairs;
    std::deque<int> winners;
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
    sortDeque(winners);
	std::deque <std::pair<int, int>>sorted;
    for (size_t i = 0 ; i < winners.size(); i++){
		for (size_t j = 0; j < pairs.size(); j++)
			if (winners[i] == pairs[j].first){
				sorted.push_back(pairs[j]);
				pairs.erase(pairs.begin()+ j);
				break;
			}				
	}
	std::deque<int> main;
	for (size_t i = 0; i < winners.size(); i++)
    	main.push_back(sorted[i].first);
	std::deque<size_t> order = createJacobsthalDeque(sorted.size());
	std::cout << std::endl;
	for (size_t i = 0; i < order.size(); i++){
		size_t index = order[i];
		main = binaryInsertDeque(main, sorted[index].first, sorted[index].second);
	}
	if (hasRemainder){
		size_t i = 0;
		while (i < main.size() && main[i] <= remainder)
			i++;
		main.insert(main.begin() + i, remainder);
	}
	vec = main;
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
	for (size_t i = 0; i < winners.size(); i++)
    	main.push_back(sorted[i].first);
	std::vector<size_t> order = createJacobsthal(sorted.size());
	std::cout << std::endl;
	for (size_t i = 0; i < order.size(); i++){
		size_t index = order[i];
		main = binaryInsert(main, sorted[index].first, sorted[index].second);
	}
	if (hasRemainder){
		size_t i = 0;
		while (i < main.size() && main[i] <= remainder)
			i++;
		main.insert(main.begin() + i, remainder);
	}
	vec = main;
}

