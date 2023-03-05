#include <iostream>

#include "swap.hh"

int main()
{
    char a = 'a';
    char b = 'b';

    std::cout << a << " and " << b << std::endl;
    my_swap(a, b);
    std::cout << a << " and " << b << std::endl;

    int c = 42;
    int d = 21;

    std::cout << c << " and " << d << std::endl;
    my_swap(c, d);
    std::cout << c << " and " << d << std::endl;

    std::string s1 = "you";
    std::string s2 = "me";

    std::cout << s1 << " and " << s2 << std::endl;
    my_swap(s1, s2);
    std::cout << s1 << " and " << s2 << std::endl;
}
