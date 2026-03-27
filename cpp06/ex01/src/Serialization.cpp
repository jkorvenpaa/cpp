#include "Serialization.hpp"

uintptr_t Serialization::serialize(Data* ptr){
	//It takes a pointer and converts it to the unsigned integer type uintptr_t.
	return reinterpret_cast<uintptr_t>(ptr);


}
Data* Serialization::deserialize(uintptr_t raw){
	//It takes an unsigned integer parameter and converts it to a pointer to Data.
	return reinterpret_cast<Data*>(raw);
}