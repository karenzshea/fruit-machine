#ifndef FRUIT_MACHINE_LOGGING_H
#define FRUIT_MACHINE_LOGGING_H

#include <iostream>
#include <string>

namespace io
{
    template<typename Prefix = "   ">
    struct log
    {
        template<typename T>
        void print(T&& contents)
        {
            std::cout << prefix
                      << std::forward<Contents>(contents)
                      << std::flush;
        }
        template<typename T, typename... Ts>
        void print(T&& first, Ts... rest)
        {
            print(first);
            return print(rest...);
        }

        Prefix prefix;
    };
}

#endif
