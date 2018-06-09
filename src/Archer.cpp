#include "../include/Hero.h"
#include "../include/Archer.h"

Archer::Archer(std::string n) : Hero(n)
{
    this->_X = 0;
    this->_Y = 0;

    this->_GOLD = 100;
    this->_LVL = 1;
    this->_EXP = 20;
    this->_EXP2NEXTLVL = static_cast<unsigned int>((50/3) * (pow(_LVL, 3) - 6 * pow(_LVL, 3) + (17 * _LVL) - 11)); //LVL^UP FORMULA

    this->_maxHP = 50;
    this->_HP = _maxHP;

    this->_maxMANA = 0;
    this->_MANA = _maxMANA;
    this->_AD = 20;
    this->_AP = 0;
    this->_DEF = 6;

    this->_Strenght = 2;
    this->_Vitality = 3;
    this->_Dexterity = 3;
    this->_Intelligence = 6;
    this->_Luck = 4;

    setSize(5); // size of inventory...
    this->_armor = {nullptr, nullptr, nullptr, nullptr};
    this->_weapon = nullptr;
    this->_Arrows = 2;
    std::cout << "Archer constructor works here...\n";
}

Archer::~Archer()
{
    std::cout << "Archer destructor works here...\n";
}

void Archer::attack(Hero &enemy)
{
    unsigned int damage = 0, defence = 0, attack = 0;
    unsigned int HP = enemy.getHP();
    defence = ((rand() % (enemy.getDEF() - enemy.getDEF() / 2)) + enemy.getDEF() / 2);
    attack = ((rand() % (getAD() - getAD() / 2)) + getAD() / 2);
    std::cout  << this->name << " (Archer)" << " is performing attack!\n";
    std::cout  << enemy.getName() << " DEF = " << defence << std::endl;
    if(attack > defence && getArrows())
    {
        damage = attack - defence;
        setArrows(getArrows() - 1);
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
        if(attack < defence) std::cout << "You missed!\n";
        else std::cout << "You ran out of arrows!!!!\n";
    }
}

void Archer::equip()
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
        std::cout << "I'm ARCHER I can't equip melee weapons!" << std::endl;
        return;
    }
    if(getItem(index)->getType() == "ranged")
    {
        std::cout << "I equipping weapon!(+5 AD)" << std::endl;
        if(_weapon == nullptr)
        {
            _weapon = getItem(index);
            removeItem(getItem(index));
        }
        else swapItems(_weapon, getItem(index));
        _AD = (getAD() + getItem(index)->getad());
        _Luck = (getLuck() + getItem(index)->getluck());
        return;
    }
    if(getItem(index)->getType() == "magic")
    {
        std::cout << "I'm ARCHER I can't equip magic weapons!" << std::endl;
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

const void Archer::showItems() const
{
    std::cout << std::string(WIDTH, 'X') << std::endl;
    std::cout << std::string(30, ' ') << "ARCHER EQUIPMENT\n";
    std::cout << std::string(WIDTH, 'X') << std::endl;
    std::cout << std::string(8, ' ') << "ARCHER BOW" << " ||| Arrows: " << getArrows() << std::endl;
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