#include "include/Game.h" //including: iomanip iostream, utility, string  libriaries...
#include "include/Shop.h"
#include "include/Warrior.h"
int main()
{
    srand(static_cast<unsigned int>(time(nullptr))); //For randomizing!
    //Initialize main objects
    Game game;
    Hero *pointer = nullptr;
    Enemy *enemy_p = nullptr;
    Shop shop;
    shop.Initialize();
    //
    std::string Name;
    game.startMessage(Name);
    pointer = pointer->Initialize(Name, game.HeroChoice());
    while(game.getRunning()) //Main Loop...
    {
        game.mainMenu(pointer, &shop, enemy_p);
        if (game.getAlive() == false) game.Load(pointer);
    }
    return 0;
}