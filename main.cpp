#include "include/Game.h" //including: iomanip iostream, utility, string  libriaries...
#include "include/Hero.h"
#include "include/Warrior.h"
#include "include/Mage.h"
#include "include/Archer.h"

int main()
{
    Game game;
    srand(static_cast<unsigned int>(time(nullptr))); //For randomizing!
    game.startMessage();

    while(game.getRunning()) //Main Loop...
    {
        game.mainMenu();
    }
    return 0;
}