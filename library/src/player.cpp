#include "logging.h"
#include "player.h"

Player::Player(double startMoney) : money(startMoney)
{
}

void Player::earn(double amt)
{
    money += amt;
    highScore = std::max(money, highScore);
}

bool Player::pay(double amt)
{
    bool afford = amt <= money;
    if (afford)
    {
        money -= amt;
    }
    return afford;
}

double const &Player::has() const
{
    return money;
}

void Player::infoMoney() const
{
    io::print(" ", "You have", money, "money! 💰\n");
}

void Player::play()
{
    plays += 1;
}

double const &Player::getHighScore() const
{
    return highScore;
}

unsigned int Player::getPlays() const
{
    return plays;
}
