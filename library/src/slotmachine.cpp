#include "slotmachine.h"

void introduction(double cost)
{
    std::cout << std::setprecision(4);
    std::cout << "✨✨✨✨✨✨✨✨✨✨✨"
              << "\n"
              << "\n"
              << " 🎩🐸👉 welcome 🎰"
              << "\n"
              << " Hit [enter] to play!"
              << "\n"
              << " Type `end` to exit:)"
              << "\n"
              << " " << cost << " per spin 🐸"
              << "\n"
              << "\n"
              << "✨✨✨✨✨✨✨✨✨✨✨"
              << "\n";
}
