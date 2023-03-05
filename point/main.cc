//
// Created by axcens on 27/02/23.
//

int main()
{
    Point a;
    const Point c;
    // The following instructions are correct:
    a.display();
    c.display();
    // However, this one is rejected by the compiler:
    c.move(2, 1); // Incorrect: c is constant and move is not.
    // Note: This is also valid for an object passed as argument
}