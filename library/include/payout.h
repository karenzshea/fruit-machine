#ifndef SLOT_MACHINE_PAYOUT_H
#define SLOT_MACHINE_PAYOUT_H

#include <cmath>
#include <vector>

using PayoutPcts = std::vector<double>;

struct IPayoutMethod
{
    virtual PayoutPcts calculate(double _minPayout, double _maxPayout,
                                 size_t total) = 0;
};

struct ExponentialMin : public IPayoutMethod
{
    PayoutPcts calculate(double _minPayout, double _maxPayout,
                         size_t total) override;
};

bool validPayout(double amt);

#endif
