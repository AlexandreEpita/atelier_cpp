#include "adapt-legacy-rectangle.hh"

#include <iostream>

AdaptLegacyRectangle::AdaptLegacyRectangle(LegacyRectangle& rect)
    : rect_(rect)
{}

AdaptLegacyRectangle::~AdaptLegacyRectangle()
{}

void AdaptLegacyRectangle::print() const
{
    std::cout << "x: " << rect_.x1_get() << " y: " << rect_.y1_get() << "\n"
              << "height: " << abs(rect_.y2_get() - rect_.y1_get()) << "\n"
              << "width: " << abs(rect_.x2_get() - rect_.x1_get()) << "\n";
}

unsigned AdaptLegacyRectangle::area() const
{
    return rect_.compute_area();
}
