#include "../include/Shop.h"

Shop::Shop()
{
    setSize(40);
}
Shop::~Shop() = default;

void Shop::Initialize()
{
    std::vector<Item*> items;
    //melee weapons
    items.push_back(new Item("sword", "melee", 12));
    items.push_back(new Item("dagger", "melee", 30));
    items.push_back(new Item("spear", "melee", 80));
    items.push_back(new Item("axe", "melee", 100));
    items.push_back(new Item("hammer", "melee", 150));
    //bows
    items.push_back(new Item("long-bow", "ranged", 12)); //mozna zmienic typ!
    items.push_back(new Item("hunters-bow", "ranged", 36));
    items.push_back(new Item("magic-bow", "ranged", 190));
    //rods
    items.push_back(new Item("fire-wand", "magic", 10));
    items.push_back(new Item("water-wand", "magic", 40));
    items.push_back(new Item("wind-wand", "magic", 150));
    items.push_back(new Item("earth-wand", "magic", 200));
    //helmets
    items.push_back(new Item("leather-cap", "helmet", 8));
    items.push_back(new Item("steel-helmet", "helmet", 22));
    items.push_back(new Item("wiking-helmet", "helmet", 56));
    items.push_back(new Item("knight-helmet", "helmet", 112));
    //armor
    items.push_back(new Item("leather-jacket", "armor", 20));
    items.push_back(new Item("copper-breastplate", "armor", 50));
    items.push_back(new Item("dragon-steel breastplate", "armor", 130));
    items.push_back(new Item("golden-breastplate", "armor", 250));
    //boots

    //shields

    //////////
    for(auto p : items) addItem(p);
    std::cout << "Shop has been initialized!" << std::endl;
}

const void Shop::Menu() const
{
    std::cout << std::string(32, '=') << std::endl;
    std::cout << "\n      Welcome in my shop!\n" << std::endl;
    std::cout << std::string(32, '=') << std::endl;
    std::cout << "What do you want?" << std::endl;
    showInv();


}