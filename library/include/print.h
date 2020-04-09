#ifndef SLOT_MACHINE_PRINT_H
#define SLOT_MACHINE_PRINT_H

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

namespace io
{

struct EmitNoBreak {};

const EmitNoBreak emit_no_break{};

template <typename T>
void emit(T&& content)
{
    std::cout << "   "
              << std::forward<T>(content)
              << "\n"
              << std::flush;
}

template <typename T>
void emit(T&& content, EmitNoBreak)
{
    std::cout << "   "
              << std::forward<T>(content)
              << std::flush;
}

template <typename T, typename... Ts>
void emit(T&& first, Ts... rest)
{
    emit(first);
    return emit(rest...);
}

template <typename T>
void emitContainer(T const &container)
{
    std::cout << "   ";
    std::for_each(begin(container), end(container), [](auto const& c) { std::cout << c; });
    std::cout << std::endl;
}

void introduction(double cost);


}

#endif
