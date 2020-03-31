#include "slotmachine.h"

void introduction(double cost) {
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

std::vector<double> calculatePayoutPct(double _min, double _max, size_t total) {
    std::vector<double> payoutPcts;

    auto scaledMax = _max * 100.0;
    auto exponent = std::log(scaledMax) / std::log(total);

    for (size_t i = 1; i <= total; i++) {
        auto val = std::max(_min, std::pow(i, exponent) * 0.01);
        payoutPcts.push_back(val);
    }

    return payoutPcts;
}

bool validPayout(double amt) {
    return amt >= 0.0 && amt <= 1.0;
}
