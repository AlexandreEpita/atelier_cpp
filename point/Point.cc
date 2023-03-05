//
// Created by axcens on 27/02/23.
//

#include "Point.hh"

void Point::display() const
{
    std::cout << "x: " << this->x_ << "\n"
              << "y: " << this->y_ << "\n";
}

void Point::move(int x, int y)
{
    this->x_ += x;
    this->y_ += y;
}
