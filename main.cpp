#include "include/Game.h" //including: iomanip iostream, utility, string  libriaries...
#include "include/Warrior.h"
#include "include/Mage.h"
#include "include/Archer.h"
#include "include/Enemy.h"
#include "include/Inventory.h"

int main()
{
    srand(static_cast<unsigned int>(time(nullptr))); //For randomizing!
    Inventory inventory;
    Item item, item1, item2;
    inventory.addItem(&item);
    //Initialize main objects
    Game game;
    Hero *pointer = nullptr;
    //
    std::string Name;
    game.startMessage(Name);
    pointer = pointer->Initialize(Name, game.HeroChoice());
    while(game.getRunning()) //Main Loop...
    {
        game.mainMenu(pointer);
    }
    return 0;
}