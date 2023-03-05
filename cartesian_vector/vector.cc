//
// Created by axcens on 28/02/23.
//

#include "vector.hh"

#include <ostream>

Vector& Vector::operator*=(int scalar)
{
    this->x *= scalar;
    this->y *= scalar;
    return *this;
}

Vector& Vector::operator+=(const Vector& rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& vect)
{
    return os << "{" << vect.x << "," << vect.y << "}";
}

Vector operator+(const Vector& lhs, const Vector& rhs)
{
    return Vector(lhs.x + rhs.x, lhs.y + rhs.y);
}

Vector operator-(const Vector& lhs, const Vector& rhs)
{
    return Vector(lhs.x - rhs.x, lhs.y - rhs.y);
}

Vector operator*(const Vector& lhs, int scalar)
{
    return Vector(lhs.x * scalar, lhs.y * scalar);
}

Vector operator*(int scalar, const Vector& rhs)
{
    return Vector(rhs.x * scalar, rhs.y * scalar);
}

int operator*(const Vector& lhs, const Vector& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y;
}