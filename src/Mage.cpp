#include "../include/Hero.h"
#include "../include/Mage.h"

Mage::Mage(std::string n) : Hero(n)
{
    this->_X = 0;
    this->_Y = 0;

    this->_GOLD = 100;
    this->_LVL = 1;
    this->_EXP = 20;
    this->_EXP2NEXTLVL = static_cast<unsigned int>((50/3) * (pow(_LVL, 3) - 6 * pow(_LVL, 3) + (17 * _LVL) - 11)); //LVL^UP FORMULA

    this->_HP = 60;
    this->_maxHP = _HP;

    this->_MANA = 100;
    this->_maxMANA = _MANA;
    this->_AD = 2;
    this->_AP = 5;
    this->_DEF = 3;

    this->_Strenght = 2;
    this->_Vitality = 3;
    this->_Dexterity = 3;
    this->_Intelligence = 6;
    this->_Luck = 0;

    setSize(5); // size of inventory...
    this->_armor = {nullptr, nullptr, nullptr, nullptr};
    this->_weapon = nullptr;
    std::cout << "Mage constructor works here...\n";
}

Mage::~Mage()
{
    std::cout << "Mage destructor works here...\n";
}

void Mage::attack(Hero &enemy)
{
    unsigned int damage = 0, defence = 0, attack = 0;
    unsigned int HP = enemy.getHP();
    defence = ((rand() % (enemy.getDEF() - enemy.getDEF() / 2)) + enemy.getDEF() / 2);
    attack = ((rand() % (getAD() - getAD() / 2)) + getAD() / 2);
    std::cout  << this->name << " (Mage)" << " is performing attack!\n";
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

void Mage::equip()
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
        std::cout << "I'm MAGE I can't equip melee weapons!" << std::endl;
        return;
    }
    if(getItem(index)->getType() == "ranged")
    {
        std::cout << "I'm MAGE I can't equip bows!" << std::endl;
        return;
    }
    if(getItem(index)->getType() == "magic")
    {
        std::cout << "I equipping weapon!(+5 AP)" << std::endl;
        if(_weapon == nullptr)
        {
            _weapon = getItem(index);
            removeItem(getItem(index));
        }
        else swapItems(_weapon, getItem(index));
        _AP = (getAP() + getItem(index)->getap());
        _maxMANA = (getMaxMANA() + getItem(index)->getmana());
        return;
    }
    if(getItem(index)->getType() == "helmet")
    {
        std::cout << "I equipping helmet!(+ "<< getItem(index)->getdef() << " DEF)" << std::endl;
        if(_armor[0] == nullptr)
        {
            _armor[0] = getItem(index);
            removeItem(getItem(index));
        }
        else swapItems(_armor[0], getItem(index));
        _DEF = (getDEF() + getItem(index)->getdef());
        return;
    }
    if(getItem(index)->getType() == "armor")
    {
        std::cout << "I equipping armor! (+ "<< getItem(index)->getdef() << " DEF || + "<< getItem(index)->gethp() << " HP)" << std::endl;
        if(_armor[1] == nullptr)
        {
            _armor[1] = getItem(index);
            removeItem(getItem(index));
        }
        else swapItems(_armor[1], getItem(index));
        _DEF = (getDEF() + getItem(index)->getdef());
        _maxHP = (getMaxHP() + getItem(index)->gethp());
        return;
    }
    if(getItem(index)->getType() == "boots")
    {
        std::cout << "I equipping boots! (+ "<< getItem(index)->getdef() << " DEF || + "<< getItem(index)->gethp() << " HP)" << std::endl;
        if(_armor[2] == nullptr)
        {
            _armor[2] = getItem(index);
            removeItem(getItem(index));
        }
        else swapItems(_armor[2], getItem(index));
        _DEF = (getDEF() + getItem(index)->getdef());
        _maxHP = (getMaxHP() + getItem(index)->gethp());
        return;
    }
    if(getItem(index)->getType() == "shield")
    {
        std::cout << "I equipping shield! (+ "<< getItem(index)->getdef() << " DEF || + "<< getItem(index)->gethp() << " HP)" << std::endl;
        if(_armor[3] == nullptr)
        {
            _armor[3] = getItem(index);
            removeItem(getItem(index));
        }
        else swapItems(_armor[3], getItem(index));
        _DEF = (getDEF() + getItem(index)->getdef());
        _maxHP = (getMaxHP() + getItem(index)->gethp());
        return;
    }
}

const void Mage::showItems() const
{
    std::cout << std::string(WIDTH, 'X') << std::endl;
    std::cout << std::string(30, ' ') << "MAGE EQUIPMENT\n";
    std::cout << std::string(WIDTH, 'X') << std::endl;
    std::cout << std::string(8, ' ') << "MAGE MAGIC WEAPON\n";
    _weapon->showItem();
    std::cout << std::string(WIDTH, 'x') << std::endl;
    std::cout << std::string(8, ' ') << "HELMET\n";
    _armor[0]->showItem();
    std::cout << std::string(WIDTH, 'x') << std::endl;
    std::cout << std::string(8, ' ') << "BREASTPLATE\n";
    _armor[1]->showItem();
    std::cout << std::string(WIDTH, 'x') << std::endl;
    std::cout << std::string(8, ' ') << "BOOTS\n";
    _armor[2]->showItem();
    std::cout << std::string(WIDTH, 'x') << std::endl;
    std::cout << std::string(8, ' ') << "SHIELD\n";
    _armor[3]->showItem();
    std::cout << std::string(WIDTH, 'x') << std::endl;
    std::cout << std::endl;
    std::cout << std::string(WIDTH, 'X') << std::endl;
}
