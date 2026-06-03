#pragma once
#include <iostream>
#include <vector>

class Span{
	private:
		std::vector<int> _span;
		unsigned int _N;
	public:
	Span();
	~Span();
	Span(unsigned int N);
	void addNumber(int num);
	unsigned int shortestSpan();
	unsigned int longestSpan();
};