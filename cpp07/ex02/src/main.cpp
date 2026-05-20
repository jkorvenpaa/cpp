#include <iostream>
#include <Array.hpp>

#define MAX_VAL 5

int main(int, char**)
{
    std::cout << std::endl << "Array<std::string> TESTS: " << std::endl;
    Array<std::string> empty;
    std::cout << "empty string len: " << empty.size() << std::endl;
    Array<std::string> str(MAX_VAL);
    std::cout << "string len: " << str.size() << std::endl << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        str[i] = "test string " + std::to_string(i);
        std::cout << str[i] << std::endl;
    }

    std::cout << std::endl << "COPY AND ASSIGNMENT TESTS: " << std::endl;
    Array<std::string> assignment = str;
    Array<std::string> copy(assignment);
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (assignment[i] != str[i] || copy[i] != assignment[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
        else
            std::cout << "ok"  << std::endl;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        str[i] = "modified string" + std::to_string(i);
        std::cout << str[i] << std::endl;
        std::cout << assignment[i] << std::endl;
        std::cout << copy[i] << std::endl;
    }
    std::cout << std::endl << "INDEX OUT OF BOUNDS TESTS: " << std::endl;
    try
    {
        str[-1] = "test -1";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        str[MAX_VAL] = "test max";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\nCONST ARRAY TEST\n";
    try{
	const Array<int> constArray(5);
	for (unsigned int i = 0; i < constArray.size(); i++)
		std::cout << constArray[i] << '\n';
    std::cout << constArray[-1] << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // subject main
    std::cout << std::endl << "SUBJECT MAIN TESTS" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
/*• Construction with no parameter: Creates an empty array.
• Construction with an unsigned int n as a parameter: Creates an array of n elements
initialized by default.
Tip: Try to compile int * a = new int(); then display *a.
• Construction by copy and assignment operator. In both cases, modifying either the
original array or its copy after copying musn’t affect the other array.
• You MUST use the operator new[] to allocate memory. Preventive allocation (allocating memory in advance) is forbidden. Your program must never access nonallocated memory.
• Elements can be accessed through the subscript operator: [ ].
• When accessing an element with the [ ] operator, if its index is out of bounds, an
std::exception is thrown.
• A member function size() that returns the number of elements in the array. This
member function takes no parameters and must not modify the current instance.*/
