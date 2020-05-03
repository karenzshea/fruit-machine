#ifndef FRUIT_MACHINE_LOGGING_H
#define FRUIT_MACHINE_LOGGING_H

#include <iostream>
#include <string>

namespace io
{
template <typename T, typename = void>
struct cout_able : std::false_type
{
};

template <typename T>
struct cout_able<
    T, std::void_t<decltype(operator<<(std::cout, std::declval<T &>()))>>
    : std::true_type
{
};

template <typename T, typename = void>
struct iterable_cout_able : std::false_type
{
};

template <typename T>
struct iterable_cout_able<T, std::void_t<decltype(std::declval<T &>().begin()),
                                         decltype(std::declval<T &>().end())>>
    : std::true_type
{
};

// cout object
template <typename T>
typename std::enable_if_t<cout_able<T>{}> print(T &&t)
{
    std::cout << std::forward<T>(t);
}

// container
template <typename T>
typename std::enable_if_t<std::conjunction_v<
    std::negation<decltype(cout_able<T>{})>, decltype(iterable_cout_able<T>{})>>
print(T &&t, const char *delim = "")
{
    for (auto const &x : t)
        std::cout << x << delim;

    std::cout << std::endl;
}

// variadic
template <typename T, typename... Ts>
void print(const char *delim, T &&first, Ts... rest)
{
    print(first);
    print(delim);
    return print(delim, rest...);
}
} // namespace io

#endif
