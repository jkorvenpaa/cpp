
#include "PhoneBook.hpp"

int	main(){
    std::string input;
    PhoneBook book;

    std::cout << "PhoneBook opened: type ADD, SEARCH or EXIT" << std::endl; 
    while (1){
        
        if (!std::getline(std::cin , input))
            break; 
        if (input == "EXIT"){
            std::cout << "Closing PhoneBook" << std::endl; 
            break;
        }
        else if (input == "ADD"){
            book.get_index();
            book.add_contact();
        }
        else if (input == "SEARCH"){
            book.get_index();
            book.search_contact();
        }  
    }
    return 0; 
}
