#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <ctime> // cpu time std::clock_t start = std::clock;
//double us = (end - start) * 1000000.0 / CLOCKS_PER_SEC;

class PmergeMe{
	private:
	std::vector<int>	_vec;
	std::deque<int>		_deq;

	public:
	PmergeMe(){};
	~PmergeMe(){};
	PmergeMe(const PmergeMe &other): _vec(other._vec), _deq(other._deq){};
	PmergeMe&	operator=(const PmergeMe &other);
	void parseInput(int ac, char **av);
	void printVector();
	void printDeque();

};