#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point){

}

/* a, b, c: The vertices of our beloved triangle.
• point: The point to check.
• Returns: True if the point is inside the triangle. False otherwise.
Thus, if the point is a vertex or on an edge, it will return False.
Implement and turn in your own tests to ensure that your class behaves as expected*/

/*bool inside = (
    ((bx - cx)*(py - cy) + (by - cy)*(cx - px)) * ((bx - cx)*(ay - cy) + (by - cy)*(cx - ax)) >= 0 &&
    ((cx - ax)*(py - cy) + (cy - ay)*(cx - px)) * ((cx - ax)*(by - cy) + (cy - by)*(cx - bx)) >= 0 &&
    ((ax - bx)*(py - by) + (ay - by)*(bx - px)) * ((ax - bx)*(cy - by) + (ay - cy)*(bx - cx)) >= 0
);
*/