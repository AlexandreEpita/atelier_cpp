#pragma once

template <typename T1, typename T2 = T1>
concept impl_basic_op = requires(T1 x, T2 y)
{
    +x;
    -x;
    x + y;
    x - y;
    x* y;
    x / y;
};

template <typename T1, typename T2 = T1>
concept impl_modulo = requires(T1 x, T2 y)
{
    x % y;
};

template <typename T1, typename T2 = T1>
concept impl_bitwise_op = requires(T1 x, T2 y)
{
    ~x;
    x& y;
    x | y;
    x ^ y;
    x << y;
    x >> y;
};

template <typename T1, typename T2 = T1>
concept impl_arith_op =
    impl_basic_op<T1, T2> && impl_modulo<T1, T2> && impl_bitwise_op<T1, T2>;