#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span{
	private:
		std::vector<int> _span;
		unsigned int _N;
	public:
		Span();
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		Span(unsigned int N);
		void insertNumbers(std::vector<int> numbers);
		void addNumber(int num);
		unsigned int shortestSpan();
		unsigned int longestSpan();
};