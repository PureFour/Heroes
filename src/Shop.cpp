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
    items.push_back(new Item("sword", "melee", 12, 1));
    items.push_back(new Item("dagger", "melee", 30, 2));
    items.push_back(new Item("spear", "melee", 80, 3));
    items.push_back(new Item("axe", "melee", 100, 4));
    items.push_back(new Item("hammer", "melee", 150, 5));
    //bows
    items.push_back(new Item("long-bow", "ranged", 12, 1));
    items.push_back(new Item("hunters-bow", "ranged", 36, 2));
    items.push_back(new Item("magic-bow", "ranged", 190, 3));
    //wands
    items.push_back(new Item("fire-wand", "magic", 10, 1));
    items.push_back(new Item("water-wand", "magic", 40, 2));
    items.push_back(new Item("wind-wand", "magic", 150, 3));
    items.push_back(new Item("earth-wand", "magic", 200, 4));
    //helmets
    items.push_back(new Item("leather-cap", "helmet", 8, 1));
    items.push_back(new Item("steel-helmet", "helmet", 22, 2));
    items.push_back(new Item("wiking-helmet", "helmet", 56, 3));
    items.push_back(new Item("knight-helmet", "helmet", 112, 4));
    //armor
    items.push_back(new Item("leather-jacket", "armor", 20, 1));
    items.push_back(new Item("copper-breastplate", "armor", 50, 2));
    items.push_back(new Item("dragon-steel breastplate", "armor", 130, 3));
    items.push_back(new Item("golden-breastplate", "armor", 350, 4));
    //boots
    items.push_back(new Item("leather-boots", "boots", 25, 1));
    items.push_back(new Item("green-light-boots", "boots", 40, 2));
    items.push_back(new Item("heavy-boots", "boots", 100, 3));
    items.push_back(new Item("golden-boots", "boots", 150, 4));
    //shields
    items.push_back(new Item("wooden-shield", "shield", 30, 1));
    items.push_back(new Item("round-shield", "shield", 80, 2));
    items.push_back(new Item("steel-shield", "shield", 174, 3));
    items.push_back(new Item("golden-shield", "shield", 250, 4));
    //potions
    items.push_back(new Item("Red-potion", "potion", 10));
    items.push_back(new Item("Blue-potion", "potion", 20));
    //arrows
    items.push_back(new Item("Wooden-Arrow", "arrow", 2));
    items.push_back(new Item("Steel-Arrow", "arrow", 5));
    //////////
    for(auto p : items) addItem(p);
    std::cout << "Shop has been initialized!" << std::endl;
}

const void Shop::showInv() const
{
    std::cout << "(0)Melee weapons\n";
    std::cout << "(1)Ranged weapons\n";
    std::cout << "(2)Magic weapons\n";
    std::cout << "(3)Helmets\n";
    std::cout << "(4)Armor\n";
    std::cout << "(5)Boots\n";
    std::cout << "(6)Shields\n";
    std::cout << "(7)Potions\n";
    std::cout << "(8)Arrows\n";
    switch(myInput(9))
    {
        case 0:
            std::cout << "Melee weapons\n";
            for(auto i : _inventory)
            {
                if(i->getType() == "melee") i->showItem();
            }
            break;
        case 1:
            std::cout << "Ranged weapons\n";
            for(auto i : _inventory)
            {
                if(i->getType() == "ranged") i->showItem();
            }
            break;
        case 2:
            std::cout << "Magic weapons\n";
            for(auto i : _inventory)
            {
                if(i->getType() == "magic") i->showItem();
            }
            break;
        case 3:
            std::cout << "Helmets\n";
            for(auto i : _inventory)
            {
                if(i->getType() == "helmet") i->showItem();
            }
            break;
        case 4:
            std::cout << "Armor\n";
            for(auto i : _inventory)
            {
                if(i->getType() == "armor") i->showItem();
            }
            break;
        case 5:
            std::cout << "Boots\n";
            for(auto i : _inventory)
            {
                if(i->getType() == "boots") i->showItem();
            }
            break;
        case 6:
            std::cout << "Shields\n";
            for(auto i : _inventory)
            {
                if(i->getType() == "shield") i->showItem();
            }
            break;
        case 7:
            std::cout << "Potions\n";
            for(auto i : _inventory)
            {
                if(i->getType() == "potion") i->showItem();
            }
            break;
        case 8:
            std::cout << "Arrows\n";
            for(auto i : _inventory)
            {
                if(i->getType() == "arrow") i->showItem();
            }
            break;
        default:
            break;

    }
}

const void Shop::Menu(Hero *hero) //TODO naprawic sklep i eq!
{
    bool running = true;
    while(running)
    {
        std::cout << std::string(WIDTH, '=') << "\n\n";
        std::cout << std::string(30, ' ') << "Welcome in my shop!\n" << std::endl;
        std::cout << std::string(WIDTH, '=') << std::endl;
        std::cout << "What do you want?" << " YOUR GOLD: " << hero->getGold() << std::endl;
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

void Shop::Buy(Hero *hero) {
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
            if(hero->getGold() >= getItem(index)->getBuyValue())
            {
                if(getItem(index)->getType() == "arrow")
                {
                    std::cout << "How much?(max 100)\n";
                    int amount = myInput(100);
                    hero->setArrows(hero->getArrows() + amount);
                    hero->setGold(hero->getGold() - amount * (getItem(index)->getBuyValue()));
                }
                else
                {
                    hero->setGold(hero->getGold() - getItem(index)->getBuyValue());
                    hero->addItem(getItem(index));
                }
                std::cout << "You bought an item!\n" << "Remaining Gold: " << hero->getGold() << std::endl;
            }
            else std::cout << "You don't have enough money!" << std::endl;
        case 0:
            break;
        default:
            break;
    }
}
void Shop::Sell(Hero *hero)
{
    std::cout << "Hero Backpack\n";
    if(hero->getSize() == 0) {
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
            addItem(getItem(index));
            std::cout << "You sold an item!\n" << "Your Gold: " << hero->getGold() << std::endl;
        case 0:
            break;
        default:
            break;
    }
}