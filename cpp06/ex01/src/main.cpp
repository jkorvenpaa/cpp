#include "Serialization.hpp"

int	main(void){
	/*Use serialize() on the address of the Data object and pass its return value to
deserialize(). Then, ensure the return value of deserialize() compares equal to the
original pointer.*/

	Data data;

	data.name = "Pokemon";
	data.value = 1;
	
	std::cout << &data << std::endl;
	std::cout << data.name << std::endl;
	std::cout << data.value << std::endl;

	uintptr_t s = Serialization::serialize(&data);
	Data *ptr = Serialization::deserialize(s);
	
	std::cout << ptr << std::endl;
	std::cout << ptr->name << std::endl;
	std::cout << ptr->value << std::endl;
	return 0;
}