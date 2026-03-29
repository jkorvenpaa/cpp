#pragma once
#include <iostream>

template<typename T, typename F>
void iter(T *array, const int len, F function){
	for (int i = 0; i <len; i++){
		function(array[i]);
	}
	std::cout << std::endl;
}

template<typename T> void print(const T& c){
	std::cout << c << " ";
}

template<typename T> void increment(T& n){
	n++;
}
