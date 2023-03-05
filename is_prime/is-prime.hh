#pragma once

template <unsigned v>
constexpr bool is_prime()
{
    if (v <= 1)
    {
        return false;
    }
    for (unsigned i = 2; i * i <= v; i++)
    {
        if (v % i == 0)
            return false;
    }
    return true;
}
