
#include "PhoneBook.hpp"

int	main(){
    std::string input;
    PhoneBook book;

    while (1){
        std::cin >> input;
        if (input == "EXIT")
            break;
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
