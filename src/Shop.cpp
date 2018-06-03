#include "../include/Shop.h"

Shop::Shop()
{
    setSize(30);
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
    //wands
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
    items.push_back(new Item("golden-breastplate", "armor", 350));
    //boots
    items.push_back(new Item("leather-boots", "boots", 25));
    items.push_back(new Item("green-light-boots", "boots", 40));
    items.push_back(new Item("heavy-boots", "boots", 100));
    items.push_back(new Item("golden-boots", "boots", 150));
    //shields
    items.push_back(new Item("wooden-shield", "shield", 30));
    items.push_back(new Item("round-shield", "shield", 80));
    items.push_back(new Item("steel-shield", "shield", 174));
    items.push_back(new Item("golden-shield", "shield", 250));
    //////////
    for(auto p : items) addItem(p);
    std::cout << "Shop has been initialized!" << std::endl;
}

const void Shop::Menu(Hero *hero) const
{
    bool running = true;
    while(running)
    {
        std::cout << std::string(WIDTH, '=') << "\n\n";
        std::cout << std::string(30, ' ') << "Welcome in my shop!\n" << std::endl;
        std::cout << std::string(WIDTH, '=') << std::endl;
        std::cout << "What do you want?" << std::endl;
        std::cout << "(1) SHOW ITEMS" << std::endl;
        std::cout << "(2) BUY ITEM" << std::endl;
        std::cout << "(3) SELL ITEM" << std::endl;
        std::cout << "(0) QUIT" << std::endl;
        switch(myInput(4))
        {
            case 0:
                running = false;
                break;
            case 1:
                showInv();
                break;
            case 2:
                Buy(hero);
                break;
            case 3:
                Sell(hero);
                break;
            default:
                break;
        }
    }
}

void Shop::Buy(Hero *hero) const
{
    std::cout << "What do you want to buy? (Enter index number)" << std::endl;
    unsigned int index = myInput(getSize());
    std::cout << "Item " << getItem(index)->getName() << std::endl;
    std::cout << "Item prize: " << getItem(index)->getBuyValue()
    << " Your Gold: " << hero->getGold() << std::endl;
    std::cout << "BUY?\n" << "(1) YES!\n" << "(0) NO...\n";
    switch(myInput(2))
    {
        case 1:
            if(hero->full_inventory())
            {
                std::cout << "Inventory is Full!" << std::endl;
                return;
            }
            if (hero->getGold() > getItem(index)->getBuyValue())
            {
                hero->setGold(hero->getGold() - getItem(index)->getBuyValue());
                hero->addItem(getItem(index));
                std::cout << "You bought an item!\n" << "Remaining Gold: " << hero->getGold() << std::endl;
            }
            else std::cout << "You don't have enough money!" << std::endl;
        case 0:
            break;
        default:
            break;
    }
}
void Shop::Sell(Hero *hero) const
{
    std::cout << "Hero Backpack\n";
    if(hero->getSize() == 0)
    {
        std::cout << "Inventory is Empty!" << std::endl;
        return;
    }
    else hero->showInv();
    std::cout << "What do you want to sell? (Enter index number)" << std::endl;
    unsigned int index = myInput(hero->getSize());
    std::cout << "Item " << hero->getItem(index)->getName() << std::endl;
    std::cout << "Item value: " << hero->getItem(index)->getSellValue() << std::endl;
    std::cout << "SELL?\n" << "(1) YES!\n" << "(0) NO...\n";
    switch(myInput(2))
    {
        case 1:
            hero->setGold(hero->getGold() + hero->getItem(index)->getSellValue());
            hero->removeItem(getItem(index));
            std::cout << "You sold an item!\n" << "Your Gold: " << hero->getGold() << std::endl;
        case 0:
            break;
        default:
            break;
    }
}