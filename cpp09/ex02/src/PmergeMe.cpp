#include "PmergeMe.hpp"

PmergeMe&	PmergeMe::operator=(const PmergeMe &other){
	if (this!= &other){
		_vec = other._vec;
		_deq = other._deq;
		_elements = other._elements;
	}
	return *this;
}

void	PmergeMe::printVector(const std::string text){
	std::cout << text;
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printDeque(const std::string text){
	std::cout << text;
	for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::processTime(const std::clock_t start, const std::clock_t end, const std::string type)//cpu time
{
	double us = (end - start) * 1000000.0 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _elements << " elements with std::" << type << " : " << us << " us\n";
}

void PmergeMe::parseInput(int ac, char** av){
	for (int i = 1; i < ac ; i++){
		size_t pos;
		std::string str = av[i];
		int num = std::stoi(str, &pos);
		if (pos != str.size())
			throw std::runtime_error("Error");
        if (num < 0)
            throw std::runtime_error("Error");
		_vec.push_back(num);
		_deq.push_back(num);
	}
	_elements = _vec.size();
}

void    PmergeMe::processVector(){
	printVector("Before: ");
    const std::clock_t start = std::clock();
    sortVector(_vec);
    const std::clock_t end = std::clock();
	printVector("After: ");
    processTime(start, end, "vector");
}

void    PmergeMe::processDeque(){
	//printDeque("Before: ");
    const std::clock_t start = std::clock();
    sortDeque(_deq);
    const std::clock_t end = std::clock();
	//printDeque("After: ");
    processTime(start, end, "deque");
}
std::deque<size_t>	PmergeMe::createJacobsthalDeque(const size_t pendingCount){
// returns insertion order (indexes)
	std::deque<size_t> jacob;
	std::deque<size_t> order;

	if (pendingCount == 0)
		return order;
	order.push_back(0);
	
	size_t a = 0;
	size_t b = 1;
	size_t prev = 1;

	// while endpoint < amount of indexes you need: take Jacobsthal sequence(next = current + 2 * previous):
	while (1){
		size_t num = b + 2 * a;
		if (num > pendingCount)
        	break;
		jacob.push_back(num);
		a = b;
		b = num;
	}
	// = Jacobsthal numbers define the group endpoints: Process each groups backwards
	for(size_t i = 0; i < jacob.size(); i++){
		for (size_t endpoint = jacob[i]; endpoint > prev; endpoint--){
			order.push_back(endpoint -1);
		}
		prev = jacob[i];
	}
	// Process any remaining elements after the last group
	for (size_t remaining = pendingCount; remaining > prev; remaining--)
    	order.push_back(remaining - 1);
	return order;
}
std::vector<size_t>	PmergeMe::createJacobsthal(const size_t pendingCount){
// returns insertion order (indexes)
	std::vector<size_t> jacob;
	std::vector<size_t> order;
	
	if (pendingCount == 0)
		return order;
	order.push_back(0);
	
	size_t a = 0;
	size_t b = 1;
	size_t prev = 1;

	// while endpoint < amount of indexes you need: take Jacobsthal sequence(next = current + 2 * previous):
	while (1){
		size_t num = b + 2 * a;
		if (num > pendingCount)
        	break;
		jacob.push_back(num);
		a = b;
		b = num;
	}
	// = Jacobsthal numbers define the group endpoints: Process each groups backwards
	for(size_t i = 0; i < jacob.size(); i++){
		for (size_t endpoint = jacob[i]; endpoint > prev; endpoint--){
			order.push_back(endpoint -1);
		}
		prev = jacob[i];
	}
	// Process any remaining elements after the last group
	for (size_t remaining = pendingCount; remaining > prev; remaining--)
    	order.push_back(remaining - 1);
	return order;
}
void  PmergeMe::binaryInsertDeque(std::deque<int> &main, int bound, int pending){
	size_t right = main.size();
	size_t left = 0;

	//binarySearch bound(cur.winner) from mainchain
	while (left < right){
        size_t mid = left + (right - left) / 2;

        if (main[mid] < bound)
            left = mid + 1;
        else
            right = mid;
    }
    // Binary search for the loser up to its winner = bound
	right = left;
	left = 0;
	while(left < right){
		size_t mid = left + (right - left) / 2;
		if (main[mid] < pending)
			left = mid + 1;
		else
			right = mid;
	}
	main.insert(main.begin() + left, pending);
}

void  PmergeMe::binaryInsert(std::vector<int> &main, int bound, int pending){
	size_t right = main.size();
	size_t left = 0;

	//binarySearch bound(cur.winner) from mainchain
	while (left < right){
        size_t mid = left + (right - left) / 2;

        if (main[mid] < bound)
            left = mid + 1;
        else
            right = mid;
    }
    // Binary search for the loser up to its winner = bound
	right = left;
	left = 0;
	while(left < right){
		size_t mid = left + (right - left) / 2;
		if (main[mid] < pending)
			left = mid + 1;
		else
			right = mid;
	}
	main.insert(main.begin() + left, pending);
}
void PmergeMe::sortDeque(std::deque<int> &vec){
	if (vec.size() <= 1)
        return ; //recursion stops

	//save remainder
	bool hasRemainder = vec.size() % 2 != 0;
    int remainder;
	remainder = hasRemainder ? vec.back() : 0;

	//form pairs, larger as first element
	std::deque<std::pair <int, int>>pairs;
    std::deque<int> winners;
    for (size_t i = 0; i + 1 < vec.size(); i += 2){
        if (vec[i] > vec[i + 1])
            pairs.emplace_back(vec[i], vec[i + 1]);
        else
            pairs.emplace_back(vec[i + 1], vec[i]);
		
    }
	//copy only first elements to winners, for recursive call
	for (size_t i = 0; i < pairs.size(); i++)
	{
		winners.push_back(pairs[i].first);
	}
    sortDeque(winners); //recursion

	//sort pairs(by first elements) 
	std::deque <std::pair<int, int>>sorted;
    for (size_t i = 0 ; i < winners.size(); i++){
		for (size_t j = 0; j < pairs.size(); j++)
			if (winners[i] == pairs[j].first){
				sorted.push_back(pairs[j]);
				pairs.erase(pairs.begin()+ j);
				break;
			}				
	}
	//start mainchain
	std::deque<int> main;
	for (size_t i = 0; i < sorted.size(); i++)
    	main.push_back(sorted[i].first);

	// Insert losers (in jacob order) using binary search
	std::deque<size_t> order = createJacobsthalDeque(sorted.size());
	for (size_t i = 0; i < order.size(); i++){
		size_t index = order[i];
		binaryInsertDeque(main, sorted[index].first, sorted[index].second);
	}
	//insert remainder
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
        return ; //recursion stops

	//save remainder
	bool hasRemainder = vec.size() % 2 != 0;
    int remainder;
	remainder = hasRemainder ? vec.back() : 0;

	//form pairs, larger as first element
	std::vector<std::pair <int, int>>pairs;
    std::vector<int> winners;
    for (size_t i = 0; i + 1 < vec.size(); i += 2){
        if (vec[i] > vec[i + 1])
            pairs.emplace_back(vec[i], vec[i + 1]);
        else
            pairs.emplace_back(vec[i + 1], vec[i]);
		
    }
	//copy only first elements to winners, for recursive call
	for (size_t i = 0; i < pairs.size(); i++)
	{
		winners.push_back(pairs[i].first);
	}
    sortVector(winners); //recursion

	//sort pairs(by first elements) 
	std::vector <std::pair<int, int>>sorted;
    for (size_t i = 0 ; i < winners.size(); i++){
		for (size_t j = 0; j < pairs.size(); j++)
			if (winners[i] == pairs[j].first){
				sorted.push_back(pairs[j]);
				pairs.erase(pairs.begin()+ j);
				break;
			}				
	}
	//start mainchain
	std::vector<int> main;
	for (size_t i = 0; i < sorted.size(); i++)
    	main.push_back(sorted[i].first);

	// Insert losers (in jacob order) using binary search
	std::vector<size_t> order = createJacobsthal(sorted.size());
	for (size_t i = 0; i < order.size(); i++){
		size_t index = order[i];
		binaryInsert(main, sorted[index].first, sorted[index].second);
	}
	//insert remainder
	if (hasRemainder){
		size_t i = 0;
		while (i < main.size() && main[i] <= remainder)
			i++;
		main.insert(main.begin() + i, remainder);
	}
	vec = main;
}

