//
// Created by axcens on 02/03/23.
//

#include "lambdas.hh"

strategy_type cooperator()
{
    return [](auto, auto) { return true; };
}

strategy_type cheater()
{
    return [](auto, auto) { return false; };
}

strategy_type copycat()
{
    return [](auto a, auto b) {
        if (a == b)
            return true;
        b--;
        if (*b > 0)
            return true;
        return false;
    };
}

strategy_type grudger()
{
    return [](auto a, auto b) {
        for (auto it = a; it != b; ++it)
        {
            if (*it <= 0)
                return false;
        }
        return true;
    };
}

strategy_type detective()
{
    return [](auto a, auto b) {
        size_t count = 1;
        bool full_ope = true;
        for (auto it = a; it != b; ++it)
        {
            if (count == 4)
            {
                count++;
                break;
            }
            if (*it <= 0)
                full_ope = false;
            count++;
        }
        switch (count)
        {
        case 1:
            return true;
        case 2:
            return false;
        case 3:
            return true;
        case 4:
            return true;
        default:
            if (full_ope)
                return false;
            else
            {
                b--;
                if (*b > 0)
                    return true;
                return false;
            }
        }
    };
}

strategy_type copykitten()
{
    return [](auto a, auto b) {
        size_t round = 0;
        for (auto it = a; it != b; ++it)
        {
            round++;
        }

        if (round < 2)
            return true;
        b--;
        if (*b <= 0)
        {
            b--;
            if (*b <= 0)
                return false;
        }
        return true;
    };
}