
#include "Point.hpp"


int main( void ) {

    Point const a(0, 0);
    Point const b(1.2, 0);
    Point const c(0.6, 2.5);

    Point check_point(1, 0);
if (bsp(a, b, c, check_point))
    std::cout << "TRUE: point inside triangle\n";
else
    std::cout << "FALSE\n";
return 0;
}

/*<< = “multiply by 2 for each shift”

>> = “divide by 2 for each shift”*/