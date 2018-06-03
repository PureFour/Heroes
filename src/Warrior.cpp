#include "../include/Hero.h"
#include "../include/Warrior.h"

Warrior::Warrior(std::string n) : Hero(n)
{
    this->_X = 0;
    this->_Y = 0;

    this->_GOLD = 100;
    this->_LVL = 1;
    this->_EXP = 20;
    this->_EXP2NEXTLVL = static_cast<unsigned int>( ( (50/3) * ( pow(this->_LVL, 3.0) ) - (6.0 * pow(this->_LVL, 3.0) ) + (17.0 * this->_LVL) - 11.0) ); //LVL^UP FORMULA

    this->_HP = 150;
    this->_MANA = 0;
    this->_AD = 12;
    this->_AP = 0;
    this->_DEF = 10;

    this->_Strenght = 6; // 1 = 2 AD
    this->_Vitality = 6; // 1 = 25 HP
    this->_Dexterity = 4; // 1 = 3 DEF
    this->_Intelligence = 0; // 1 = 25 MANA
    this->_Luck = 5; // 1 = 10% CritChance

   // this->_inventory = {};
    //setSize(1); // size of inventory...
    this->_armor = {nullptr, nullptr, nullptr, nullptr};
    this->_weapon = nullptr;
    std::cout << "Warrior constructor works here...\n";
}

Warrior::~Warrior() { std::cout << "Warrior destructor works here...\n"; }

void Warrior::attack(Hero &enemy)
{
    unsigned int damage = 0, defence = 0, attack = 0;
    unsigned int HP = enemy.getHP();
    defence = ((rand() % (enemy.getDEF() - enemy.getDEF() / 2)) + enemy.getDEF() / 2);
    attack = ((rand() % (getAD() - getAD() / 2)) + getAD() / 2);
    std::cout  << this->name << " (Warrior)" << " is performing attack!\n";
    std::cout  << enemy.getName() << " DEF = " << defence << std::endl;
    if(attack > defence)
    {
        damage = attack - defence;
        if(Crit(getLuck()))
        {
            damage *= 2;
            std::cout << "Critical HIT! : " << damage << std::endl;
        }
        else printf("Your DMG= %i\n", damage);
        if(damage < HP) enemy.setHP(HP - damage);
        else enemy.setHP(0);
    }
    else
    {
        damage = 0;
        std::cout << "You missed!\n";
    }
}

void Warrior::equip() //TODO cos nie dziala ...
{
    if(getSize() == 0)
    {
        std::cout << "Inventory is Empty!" << std::endl;
        return;
    }

    std::cout << "Enter item index: ";
    unsigned int index;
    std::cin >> index;

    if(getItem(index)->getType() == "melee")
    {
        std::cout << "I equipping weapon!(+5 AD)" << std::endl;
        if(_weapon == nullptr)
        {
            _weapon = getItem(index);
            removeItem(getItem(index));
        }
        else swapItems(_weapon, getItem(index));
        _AD = (getAD() + 5);
    }
    if(getItem(index)->getType() == "ranged")
    {
        std::cout << "I'm warrior I can't equip bows!" << std::endl;
        return;
    }
    if(getItem(index)->getType() == "magic")
    {
        std::cout << "I'm warrior I can't equip wands!" << std::endl;
        return;
    }
    if(getItem(index)->getType() == "helmet")
    {
        std::cout << "I equipping helmet!(+5 DEF)" << std::endl;
        if(_armor[0] == nullptr)
        {
            _armor[0] = getItem(index);
            removeItem(getItem(index));
        }
        else swapItems(_armor[0], getItem(index));
        _DEF = (getDEF() + 5);
    }
    if(getItem(index)->getType() == "armor")
    {
        std::cout << "I equipping armor!(+15 VIT)" << std::endl;
        if(_armor[1] == nullptr)
        {
            _armor[1] = getItem(index);
            removeItem(getItem(index));
        }
        else swapItems(_armor[1], getItem(index));
        _Vitality = (getVit() + 15);
    }
    if(getItem(index)->getType() == "boots")
    {
        std::cout << "I equipping boots!(+5 DEX)" << std::endl;
        if(_armor[2] == nullptr)
        {
            _armor[2] = getItem(index);
            removeItem(getItem(index));
        }
        else swapItems(_armor[2], getItem(index));
        _Dexterity = (getDex() + 5);
    }
    if(getItem(index)->getType() == "shield")
    {
        std::cout << "I equipping shield!(+10 DEF)" << std::endl;
        if(_armor[3] == nullptr)
        {
            _armor[3] = getItem(index);
            removeItem(getItem(index));
        }
        else swapItems(_armor[3], getItem(index));
        _DEF = (getDEF() + 10);
    }
}

const void Warrior::showItems() const
{
    std::cout << "WARRIOR EQUIPMENT...\n";
    std::cout << "\nWARRIOR ARMOR\n";
    for(auto i : _armor) i->showItem();
    std::cout << "WARRIOR WEAPON\n";
    _weapon->showItem();
}
