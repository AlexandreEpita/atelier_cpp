//
// Created by axcens on 28/02/23.
//

#include "forward-multiplication.hh"

#include <functional>

lambda_type create_lambda()
{
    lambda_type lambdaType = [](int a) -> std::function<int(int)> {
        return [a](int b) -> int { return a * b; };
    };
    return lambdaType;
}