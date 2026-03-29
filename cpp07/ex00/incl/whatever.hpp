#pragma once
#include <iostream>

template<typename t>
t min(t &a, t &b){
	return (a < b) ? a : b;
}

template<typename t>
t max(t &a, t &b){
return (a > b) ? a : b;
}

template<typename t>
void swap(t &a, t &b){
	t temp = a;
	a = b;
	b = temp;
}
