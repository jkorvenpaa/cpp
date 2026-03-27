#pragma once
#include <iostream>
#include <cstdint>

struct Data
{
	std::string name;
	int	value;
};


class Serialization
{
private:
	
public:
	Serialization() = delete;
	~Serialization() = delete;
	Serialization(const Serialization &other) = delete;
	Serialization	&operator=(const Serialization &other) = delete;

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

