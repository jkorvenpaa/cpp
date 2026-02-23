#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
delete meta;
delete j;
delete i;

const WrongAnimal* wmeta = new WrongAnimal();
const WrongAnimal* wi = new WrongCat();
std::cout << wi->getType() << " " << std::endl;
wi->makeSound();
wmeta->makeSound();
delete wmeta;
delete wi;



// Animal a;
// Animal b(a);
// Animal c;
// c = a;

// Animal* A = new Animal();   // default constructor
// Animal* B = new Animal(*A); // copy constructor
// Animal* C = new Animal();
// *C = *A;// copy assignment operator
// delete A;
// delete B;
// delete C;

return 0;
}