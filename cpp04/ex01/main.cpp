#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


int main()
{
Animal a;
Animal b(a);
Animal c;
c = a;

Animal* A = new Animal();   // default constructor
Animal* B = new Animal(*A); // copy constructor
Animal* C = new Animal();
*C = *A;// copy assignment operator
delete A;
delete B;
delete C;

std::cout << "end of copy tests\n\n";

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
