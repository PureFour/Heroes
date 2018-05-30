#include "../include/Armor.h"

Armor::Armor(std::string n, std::string t, unsigned int b, unsigned int s) :Item(n, t, b, s)
{

}

Armor::~Armor() = default;

std::vector<Item*> Armor::helmets = {new Item("Cap", "Helmet", 5, 10), new Item("Helmet", "Helmet", 15, 10)};
std::vector<Item*> Armor::breastplates = {new Item("Rusty Armor", "BreastPlate", 25, 14), new Item("Gold Armor", "BreastPlate", 114, 50)};
std::vector<Item*> Armor::shields = {new Item("Wooden shield", "Shield", 5, 10), new Item("Iron Shield", "Shield", 30, 14)};
std::vector<Item*> Armor::boots = {new Item("Leather Sandales", "Boots", 5, 10), new Item("Mega full op boots", "Boots", 1500, 1000)};

Item* Armor::getItems() const
{
    return helmets[0], helmets[1], breastplates[0], breastplates[1],
            shields[0], shields[1], boots[0], boots[1];
}