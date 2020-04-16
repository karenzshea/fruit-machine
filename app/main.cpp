#include "payout.h"
#include "logging.h"
#include "slotmachine.h"

const double costToPlay{0.25};

int main()
{
    io::log Log;

    introduction(costToPlay);
    // ? load intro from text file
    // Log << introduction;

    Player player{costToPlay * 50};

    player.infoMoney(Log);

    ExponentialMin payoutCalc{};

    SlotMachine<std::vector<std::string>> slot_machine{
        {"🍓", "🍑", "🍈", "🍇", "🍌", "🍋", "🍒", "💣", "💰", "🔔", "💎"}, payoutCalc};

    std::cout << "\n";
    slot_machine.introduce();
    // Log << slot_machine.info() << "\n";

    bool play = true;
    while (play)
    {
        std::string input;
        std::getline(std::cin, input);

        if (input == "end")
        {
            play = false;
            break;
        }

        Play(player, slot_machine);

        play = play && player.has() >= costToPlay;

        // if (player.getPlays() % 10 == 0)
        //     Log << player.has();
    }

    std::cout << "   Game over! 💸"
              << "\n";
    player.announceMoney();
    std::cout << "   High score: " << player.getHighScore() << "\n";
    std::cout << "   Play streak: " << player.getPlays() << "\n";
    std::cout << "   Slot machine made: " << slot_machine.getPayload() << "\n";
    std::cout << std::endl;
}
