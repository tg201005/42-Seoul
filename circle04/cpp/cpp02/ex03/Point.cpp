#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(){
    this->x = 0;
    this->y = 0;
}

Point::Point(const Point &point){
    this->x = point.getX();
    this->y = point.getY();
}

Point::Point(const float x, const float y){
    this->x = x;
    this->y = y;
}

Point::~Point(){
}

Point&  Point::operator=(const Point &point){
    this->x = point.getX();
    this->y = point.getY();
    return (*this);
}

std::ostream&   operator<<(std::ostream &out, const Point &point){
    out << "Point(" << point.getX() << ", " << point.getY() << ")";
    return (out);
}

Fixed   Point::getX() const{
    return (this->x);
}

Fixed   Point::getY() const{
    return (this->y);
}

