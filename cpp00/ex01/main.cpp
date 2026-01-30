
#include "PhoneBook.hpp"

int	main(){
    std::string input;
    PhoneBook book;

    while (1){
        std::cout << GOLD << "PhoneBook: type ADD, SEARCH or EXIT"
            << RESET << std::endl;
        if (!std::getline(std::cin , input))
            break ;
        if (input == "EXIT"){
            std::cout << GOLD << "Closing PhoneBook" << std::endl; 
            break ;
        }
        else if (input == "ADD"){
            book.get_index();
            book.add_contact();
        }
        else if (input == "SEARCH")
            book.search_contact();
    }
    return 0; 
}
