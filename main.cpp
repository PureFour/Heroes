#include "include/Game.h" //including: iomanip iostream, utility, string  libriaries...
#include "include/Warrior.h"
#include "include/Mage.h"
#include "include/Archer.h"
#include "include/Enemy.h"

int main()
{
    srand(static_cast<unsigned int>(time(nullptr))); //For randomizing!
    //Initialize main objects
    Game game;
    Hero *pointer = nullptr;
    Warrior John("John");
    Enemy Dog("Dog");
    John.attack(Dog);
    Dog.status();
    std::string Name;
    //
    game.startMessage(Name);
    pointer = pointer->Initialize(Name, game.HeroChoice());
    while(game.getRunning()) //Main Loop...
    {
        game.mainMenu(pointer);
    }
    return 0;
}