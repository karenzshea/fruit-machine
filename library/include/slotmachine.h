#ifndef SLOT_MACHINE_SLOT_MACHINE_H
#define SLOT_MACHINE_SLOT_MACHINE_H

#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>

#include "payout.h"
#include "player.h"

void introduction(double cost);

template <class Container>
void printContainer(Container const &container)
{
    for (auto const &c : container)
    {
        std::cout << c;
    }
    std::cout << "\n";
}

template <class Container>
class SlotMachine
{
public:
    typedef typename Container::value_type ContentType;

    SlotMachine(Container &&_symbols, IPayoutMethod &method, double _min = 0.25,
                double _max = 0.9)
        : symbols(std::move(_symbols)),
          rand(0, std::floor(symbols.size() / 2) - 1)
    {
        if (validPayout(_min))
            minPayout = _min;

        if (validPayout(_max))
            maxPayout = _max;

        payouts = method.calculate(minPayout, maxPayout, symbols.size());
    }

    void introduce()
    {
        std::cout << "   Win on this slot machine:\n";
        printContainer(symbols);
    }
    std::vector<ContentType> getBars()
    {
        std::vector<ContentType> result(bars);
        std::transform(begin(result), end(result), begin(result),
                       [&](auto) mutable { return getRandomSymbol(); });
        return result;
    }
    double spin(double payment)
    {
        payload += payment;

        auto result = getBars();

        printContainer(result);

        auto payout = processPayout(result);

        return payout;
    }

    double processPayout(std::vector<ContentType> const &result)
    {
        double payout = 0.0;

        auto same = std::all_of(begin(result), end(result), [&](auto const &v) {
            return result.front() == v;
        });

        if (same)
        {
            size_t pos = std::distance(
                begin(symbols),
                std::find(begin(symbols), end(symbols), result.front()));
            auto pct = payouts.at(pos);
            payout = payload * pct;
        }

        return payout;
    }

    ContentType getRandomSymbol()
    {
        auto gen = std::abs(std::round(rand(rng)));
        auto val = (int)gen % (int)symbols.size();

        assert(val <= static_cast<int>(symbols.size()) - 1);

        return symbols.at(val);
    }
    const double &getPayload() const
    {
        return payload;
    }
    const double &getCostToPlay() const
    {
        return costToPlay;
    }
    void setBars(unsigned int num)
    {
        bars = num;
    }
    void setCostToPlay(double amt)
    {
        costToPlay = amt;
    }

private:
    const Container symbols;
    double minPayout;
    double maxPayout;
    double payload = 5.0;
    unsigned int bars = 3;
    double costToPlay = 0.25;
    PayoutPcts payouts{};

    std::random_device r{};
    std::seed_seq seed{r()};
    std::mt19937 rng{seed};
    std::normal_distribution<> rand;
};

template <class T>
void Play(Player &player, SlotMachine<T> &slot_machine)
{
    auto cost = slot_machine.getCostToPlay();

    auto afford = player.pay(cost);

    if (!afford)
        return;

    player.play();

    auto payout = slot_machine.spin(cost);

    if (payout > 0.0)
    {
        std::cout << "   You won " << payout << "! ✨✨✨" << std::endl;
        player.earn(payout);
    }
}

#endif
