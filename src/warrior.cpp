#include <iostream>
#include "heros.h"
void Warrior::attack()
{

}
void Warrior::status()
{
    std::cout << "HP: " << _HP << std::endl;
    std::cout << "MANA: " << _MANA << std::endl;
    std::cout << "AD: " << _AD << std::endl;
    std::cout << "DEF: " << _DEF << std::endl;
}