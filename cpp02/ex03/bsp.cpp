#include "Point.hpp"

Fixed cross(Point const a, Point const b, Point const point){
	Fixed cross =(Bx​−Ax​)(Py​−Ay​)−(By​−Ay​)(Px​−Ax​);
	return cross;
}

bool bsp(Point const a, Point const b, Point const c, Point const point){

	Fixed cross1 =(a, b, point);
	Fixed cross1 = (b, c, point);
	Fixed cross1 = (c, a, point);
	
}

/* a, b, c: The vertices of our beloved triangle.
• point: The point to check.
• Returns: True if the point is inside the triangle. False otherwise.
Thus, if the point is a vertex or on an edge, it will return False.
Implement and turn in your own tests to ensure that your class behaves as expected*/

/*If point P is inside triangle ABC:

It must be on the same side of AB as C

Same side of BC as A

Same side of CA as B*/