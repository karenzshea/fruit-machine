#include "introduction.h"
#include "logging.h"
#include "payout.h"
#include "slotmachine.h"

const double costToPlay{0.25};

int main()
{
    Introduction intro{costToPlay};

    io::print(intro.text, "\n");

    Player player{costToPlay * 50};
    player.infoMoney();

    ExponentialMin payoutCalc{};

    SlotMachine<std::vector<std::string>> slot_machine{
        {"🍓", "🍑", "🍈", "🍇", "🍌", "🍋", "🍒", "💣", "💰", "🔔", "💎"}, payoutCalc};

    std::cout << "\n";
    slot_machine.info();

    bool play = true;
    while (play)
    {
        std::string input;
        std::getline(std::cin, input);

        if (input == "end")
            play = false;

        Play(player, slot_machine);

        play = play && player.has() >= costToPlay;
    }

    io::print("Game over! 💸\n");

    player.infoMoney();

    io::print(" ", "High score:", player.getHighScore(), "\n");
    io::print(" ", "Play streak:", player.getPlays(), "\n");
    io::print(" ", "Slot machine made:", slot_machine.getPayload(), "\n");
}
