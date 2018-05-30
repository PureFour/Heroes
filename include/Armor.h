#include "Item.h"

#ifndef HEROES_ARMOR_H
#define HEROES_ARMOR_H

class Armor : public Item
{
    static std::vector<Item*> helmets;
    static std::vector<Item*> breastplates;
    static std::vector<Item*> shields;
    static std::vector<Item*> boots;
public:
    Armor(std::string name = "Unknown", std::string type = "Armor", unsigned int buyValue = 0, unsigned int sellValue = 0);
    ~Armor();
    Item* getItems() const;
};

#endif //HEROES_ARMOR_H
