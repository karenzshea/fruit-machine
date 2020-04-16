#ifndef FRUIT_MACHINE_LOGGING_H
#define FRUIT_MACHINE_LOGGING_H

#include<iostream>

namespace io
{

struct log
{
    template<typename T>
    log operator<<(T&& content);
    bool started = false;
};

template<typename T>
log log::operator<<(T&& content) {
    if (!started)
    {
        started = true;
        std::cout << "   ";
    }

    std::cout << std::forward<T>(content)
              << " ";
    return *this;
}

}

#endif
