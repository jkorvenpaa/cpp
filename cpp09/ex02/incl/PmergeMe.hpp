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
	void	printVector();
	void	printDeque();
	void	processTime(const std::clock_t start, const std::clock_t end);
	std::vector<size_t>	createJacobstahl(const size_t amount);
	void	sortPairsVector();

};