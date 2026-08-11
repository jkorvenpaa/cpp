#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <ctime> 
#include <utility>
#include <algorithm>

class PmergeMe{
	private:
	std::vector<int>	_vec;
	std::deque<int>		_deq;
	size_t	_elements;

	public:
	PmergeMe(){};
	~PmergeMe(){};
	PmergeMe(const PmergeMe &other): _vec(other._vec), _deq(other._deq){};
	PmergeMe&	operator=(const PmergeMe &other);
	void	parseInput(int ac, char **av);
	void	printVector(const std::string text);
	void	printDeque(const std::string text);
	void	processTime(const std::clock_t start, const std::clock_t end, const std::string type);
	
	void	processVector();
	void    processDeque();
	void	sortVector(std::vector<int> &vec);
	void	sortDeque(std::deque<int> &vec);
	std::vector<size_t>	createJacobsthal(const size_t pendingCount);
	std::deque<size_t>	createJacobsthalDeque(const size_t pendingCount);
	void	binaryInsert(std::vector<int> &main, int bound, int pending);
	void	binaryInsertDeque(std::deque<int> &main, int bound, int pending);


};