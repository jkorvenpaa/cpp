#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


int main()
{
// Animal a;
// Animal b(a);
// Animal c;
// c = a;

// Cat* A = new Cat();   // default constructor
// Cat* B = new Cat(*A); // copy constructor
// //*B = *A;
// std::cout << A->brain("food") << std::endl;
// std::cout << B->brain("hunggggryyyy") << std::endl;
// delete A;
// delete B;

//std::cout << "end of copy tests\n\n";

int N = 10;
Animal **queue = new Animal*[N];
// first half = dogs
for (int i = 0; i < N/2; i++){
	queue[i] = new Dog;
}
// second half = cats
for (int i = N/2; i < N; i++){
	queue[i] = new Cat;
}
//make sound
for (int i = 0; i < N; i++){
	queue[i]->makeSound();
}
// delete animals
for (int i = 0; i < N; i++){
	delete queue[i];
}
delete []queue;

return 0;
}
