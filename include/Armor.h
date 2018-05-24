#include "Item.h"

#ifndef HEROES_ARMOR_H
#define HEROES_ARMOR_H

class Armor : public Item
{
    static std::vector<Item*> helmets;
    static std::vector<Item*> breastplates[2];
    static std::vector<Item*> shields[2];
    static std::vector<Item*> boots[2];
public:
    Armor(std::string name = "Unknown", std::string type = "Armor", unsigned int buyValue = 0, unsigned int sellValue = 0);
    ~Armor();
};

#endif //HEROES_ARMOR_H
