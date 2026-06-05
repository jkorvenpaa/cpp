#pragma once
#include <iostream>
#include <stack>

template <typename T> 
class MutantStack : public std::stack<T>{

	public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack& operator=(const MutantStack &other);

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();


};

#include "MutantStack.tpp"