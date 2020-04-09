#include "print.h"

namespace io
{

void introduction(double)
{
    io::emit("✨✨✨✨✨✨✨✨✨", "🎩🐸 welcome!  👉🎰", "Hit [enter] to play!", "Type `end` to exit🐸");
    //io::emit << " " << cost << " per spin 🐸";
}
/*
void introduction(double cost)
{
    std::cout << std::setprecision(4);
    std::cout << "\n"
              << "\n"
              << " 🎩🐸 welcome!  👉🎰"
              << "\n"
              << "\n"
              << " Hit [enter] to play!"
              << "\n"
              << " Type `end` to exit🐸"
              << "\n"
              << " " << cost << " per spin 🐸"
              << "\n"
              << "\n";
}
*/
}
