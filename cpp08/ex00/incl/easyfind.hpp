#pragma once
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>

template<typename T>
typename T::iterator easyfind(T &type, int val){
typename T::iterator it = std::find(type.begin(), type.end(), val);
if (it == type.end())
	throw std::out_of_range("value not found");
else
	return it;
}