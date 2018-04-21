#include "include/Hero.h" //including: iostream, utility, string libriaries...
#include "include/Warrior.h"
#include "include/Mage.h"
#include "include/Archer.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    Warrior John("John");
    Mage Harry("Harry");
    John.status();
    Harry.status();
    John.attack(Harry);
    Harry.status();
    return 0;
}