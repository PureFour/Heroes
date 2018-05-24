#include "../include/Armor.h"

Armor::Armor(std::string n, std::string t, unsigned int b, unsigned int s) :Item(n, t, b, s)
{

}

Armor::~Armor() = default;

std::vector<Item*> Armor::helmets = {new Item("Cap", "Helmet", 5, 10), new Item("Helmet", "Helmet", 15, 10)};
