#include "include/Hero.h" //including: iostream, utility, string libriaries...
#include "include/Game.h" //including: iomanip library
#include "include/Warrior.h"
#include "include/Mage.h"
#include "include/Archer.h"

int main()
{
    std::cout << std::setfill('=') << std::setw(100);
    std::cout << std::setw(50) << "\n\nHEROES - THE GAME\n\n";

    //Main Loop...
    Game game;
    while(game.running)
    {
        game.mainMenu();
    }
    return 0;
}