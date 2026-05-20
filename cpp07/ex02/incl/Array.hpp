#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
private:
	T*	_array;
	unsigned int	_len;
public:
	Array();
	Array(unsigned int len);
	~Array();

	Array& operator=(const Array& other);
	Array(const Array& other);
	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;
	unsigned int size() const;
};

template <typename T> Array<T>::Array():_array(NULL), _len(0)
{
}
template <typename T> Array<T>::Array(unsigned int len):_array(NULL), _len(len)
{
	try{
	 _array = new T[_len](); 
	}
	catch (const std::exception& e){
		 std::cerr << e.what() << '\n';
	}
}

template <typename T> Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
Array<T>::Array(const Array& other){
	_len = other._len;
	_array = new T[_len];
	for (unsigned int i = 0; i <other._len; i++)
		_array[i] = other._array[i];

}
template <typename T> Array<T> & Array<T>::operator=(const Array& other){
	if (this != &other){
		delete [] _array;
		_len = other._len;
		_array = new T[_len];
		for (unsigned int i = 0; i <other._len; i++)
			_array[i] = other._array[i];
	}
	return *this;

}
template <typename T> const T& Array<T>::operator[](unsigned int index) const{
	if (index < _len)
	{
		return _array[index];
	}
	throw std::out_of_range("out of range const");

}

template <typename T> T& Array<T>::operator[](unsigned int index){
	if (index < _len)
	{
		return _array[index];
	}
	throw std::out_of_range("out of range");

}
template <typename T> unsigned int Array<T>:: size() const{

	return _len;
}
