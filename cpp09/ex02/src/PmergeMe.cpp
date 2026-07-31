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
std::vector<size_t>	PmergeMe::createJacobsthal(const size_t pendingCount){

// Take Jacobsthal sequence(next = current + 2 * previous): while endpoint < amount of indexes you need:
// Stop when the endpoint is bigger
// Group by end points
// reverse groups and concatenate
// = insertion index order
	std::vector<size_t> jacob;
	std::vector<size_t> order;

	if (pendingCount == 0)
		return order;
	order.push_back(0);

	size_t a = 0;
	size_t b = 1;
	size_t prevGroup = 1;

	for (size_t i = 2; i <= pendingCount; i++){
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

	for (size_t group = pendingCount; group > prevGroup; group--){
    	order.push_back(group- 1);
	}

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

// processVector()

//     start = clock

//     sortVector(original)

//         pair elements
//         collect winners

//         sortVector(winners)

//             pair winners
//             collect winners

//             sortVector(smaller winners)

//                 base case
//                 return

//             rebuild pairs
//             createJacobsthal
//             binaryInsert
//             insert remainder
//             return

//         rebuild pairs
//         createJacobsthal
//         binaryInsert
//         binaryInsert
//         binaryInsert
//         insert remainder

//     printVector()

//     end = clock

//     processTime()