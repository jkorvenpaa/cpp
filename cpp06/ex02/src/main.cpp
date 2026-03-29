#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void){

	std::uniform_int_distribution<> dist(0, 2);
	std::random_device rd;
	std::mt19937 gen(rd());
	int x = dist(gen);
	if (x == 0)
		return new A;
	else if (x == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "type A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "type B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "type C" << std::endl;
}

void identify(Base& p){
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type A" << std::endl;
	}
	catch(std::bad_cast &e){

	}
	try{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type B" << std::endl;
	}
	catch(std::bad_cast &e){

	}
	try{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type C" << std::endl;
	}
	catch(std::bad_cast &e){

	}
}

int main(void){
	Base *p = generate();
	identify(p);
	identify(*p);
	delete p;

	std::cout << std::endl;
	
	Base *q = generate();
	identify(q);
	identify(*q);
	delete q;

	return (0);
}