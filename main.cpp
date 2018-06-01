#include "include/Game.h" //including: iomanip iostream, utility, string  libriaries...
#include "include/Shop.h"
#include "include/Warrior.h"
int main()
{
    srand(static_cast<unsigned int>(time(nullptr))); //For randomizing!
    //Initialize main objects
    Game game;
    Hero *pointer = nullptr;
    Shop *shop_p = nullptr;
    Enemy *enemy_p = nullptr;
    //
    std::string Name;
    game.startMessage(Name);
    pointer = pointer->Initialize(Name, game.HeroChoice());
    while(game.getRunning()) //Main Loop...
    {
        game.mainMenu(pointer, shop_p, enemy_p);
    }
    return 0;
}