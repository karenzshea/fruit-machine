#ifndef FRUIT_MACHINE_LOGGING_H
#define FRUIT_MACHINE_LOGGING_H

#include <iostream>
#include <string>

namespace io
{

template <typename T, typename = void>
struct has_ostream_op : std::false_type
{
};

template <typename T>
struct has_ostream_op<T,
                      std::void_t<decltype(std::cout << std::declval<T &>())>>
    : std::true_type
{
};

template <typename T, typename = void>
struct is_iterable : std::false_type
{
};

template <typename T>
struct is_iterable<
    T, std::void_t<decltype(std::declval<T &>().begin()),
                   decltype(std::declval<T &>().end()),
                   decltype(std::cout << std::declval<
                                typename std::decay_t<T>::value_type>())>>
    : std::true_type
{
};

// ostream
template <typename T>
std::enable_if_t<has_ostream_op<T>{}> print(T &&t)
{
    std::cout << std::forward<T>(t) << std::flush;
}

// container
template <typename T>
typename std::enable_if_t<std::conjunction_v<
    std::negation<decltype(has_ostream_op<T>{})>, decltype(is_iterable<T>{})>>
print(T &&t, const char *delim = "")
{
    for (auto &&x : t)
    {
        std::cout << std::forward<decltype(x)>(x) << delim;
    }

    std::cout << std::endl;
}

// variadic
template <typename T, typename... Ts>
void print(const char *delim, T &&first, Ts... rest)
{
    std::cout << std::forward<T>(first) << delim << std::flush;
    return print(delim, rest...);
}

} // namespace io

#endif
