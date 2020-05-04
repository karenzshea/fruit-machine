#ifndef FRUIT_MACHINE_INTRO_H
#define FRUIT_MACHINE_INTRO_H

#include <array>
#include <string>

struct Introduction
{
    Introduction(double _cost) : cost(_cost)
    {
        text = {
            "✨✨✨✨✨✨✨✨✨✨✨",
            "🎩🐸👉 welcome 🎰",
            "Hit [enter] to play!",
            "Type `end` to exit:)",
            std::to_string(cost) + " per spin 🐸",
            "✨✨✨✨✨✨✨✨✨✨✨",
        };
    };

    double cost;
    std::array<std::string, 6> text;
};

#endif
