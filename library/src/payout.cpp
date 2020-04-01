#include "payout.h"

PayoutPcts ExponentialMin::calculate(double _minPayout, double _maxPayout,
                                     size_t total)
{
    PayoutPcts pcts;

    auto scaledMax = _maxPayout * 100.0;
    auto exponent = std::log(scaledMax) / std::log(total);

    for (size_t i = 1; i <= total; i++)
    {
        auto val = std::max(_minPayout, std::pow(i, exponent) * 0.01);
        pcts.push_back(val);
    }

    return pcts;
}

bool validPayout(double amt)
{
    return amt >= 0.0 && amt <= 1.0;
}
