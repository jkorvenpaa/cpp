#include "Span.hpp"

Span::Span():_N(0){
}

Span::~Span(){
}

Span::Span(unsigned int N): _N(N){
}

Span::Span(const Span& other): _span(other._span), _N(other._N){
}

Span& Span::operator=(const Span& other){
	if (this != &other){
		_span = other._span;
		_N = other._N;
	}
	return *this;
}

void Span::insertNumbers(std::vector<int> numbers){
	if ((_span.size() + numbers.size()) > _N)
		throw std::out_of_range("not enough space");
	_span.insert(_span.end(), numbers.begin(), numbers.end());
}
void Span::addNumber(int num){
	if (_span.size() < _N)
		_span.push_back(num);
	else
		throw std::out_of_range("not enough space");
}
unsigned int Span::shortestSpan(){
	if (_span.empty() || _span.size()==1)
		throw std::out_of_range("not enough members");
	sort(_span.begin(), _span.end());
	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	for (std::vector<int>::iterator it = _span.begin(); it + 1!= _span.end(); it++){
		unsigned int dif = *(it + 1) - *it;
		if (dif < shortest)
			shortest = dif;
	}
	return shortest;
}
unsigned int Span::longestSpan(){
	if (_span.empty() || _span.size()==1)
		throw std::out_of_range("not enough members");
	sort(_span.begin(), _span.end());
	return *(_span.end() - 1)  - *_span.begin();
}