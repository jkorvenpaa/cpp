#pragma once
#include "Fixed.hpp"

class Point
{
private:
    Fixed const _x;
    Fixed const _y;
public:
    Point(/* args */);
    ~Point();
    Point::Point(float x, float y);
    Point::Point(const Point& copy);
    Point& Point::operator=(const Point& copy);
};
bool bsp(Point const a, Point const b, Point const c, Point const point);

