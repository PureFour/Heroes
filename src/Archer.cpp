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
        if(_weapon == nullptr)
        {
            std::cout << "I equipping weapon!(+ " << getItem(index)->getad() << " AD || + "<< getItem(index)->getluck() << " LUCK)" << std::endl;
            _weapon = getItem(index);
            _AD += getItem(index)->getad();
            _Luck += getItem(index)->getluck();
            removeItem(getItem(index));
        }
        else
        {
            updateStats(getItem(index), _weapon);
            swapItems(getItem(index), _weapon);
        }
        return;
    }
    if(getItem(index)->getType() == "magic")
    {
        std::cout << "I'm ARCHER I can't equip magic weapons!" << std::endl;
        return;
    }
    if(getItem(index)->getType() == "helmet")
    {
        if(_armor[0] == nullptr)
        {
            std::cout << "I equipping helmet!(+ "<< getItem(index)->getdef() << " DEF)" << std::endl;
            _armor[0] = getItem(index);
            _DEF = (getDEF() + getItem(index)->getdef());
            removeItem(getItem(index));
        }
        else
        {
            updateStats(getItem(index), _armor[0]);
            swapItems(getItem(index), _armor[0]);
        }
        return;
    }
    if(getItem(index)->getType() == "armor")
    {
        if(_armor[1] == nullptr)
        {
            std::cout << "I equipping armor! (+ "<< getItem(index)->getdef() << " DEF || + "<< getItem(index)->gethp() << " HP)" << std::endl;
            _armor[1] = getItem(index);
            _DEF = (getDEF() + getItem(index)->getdef());
            _maxHP = (getMaxHP() + getItem(index)->gethp());
            removeItem(getItem(index));
        }
        else
        {
            updateStats(getItem(index), _armor[1]);
            swapItems(getItem(index), _armor[1]);
        }
        return;
    }
    if(getItem(index)->getType() == "boots")
    {
        if(_armor[2] == nullptr)
        {
            std::cout << "I equipping boots! (+ "<< getItem(index)->getdef() << " DEF || + "<< getItem(index)->gethp() << " HP)" << std::endl;
            _armor[2] = getItem(index);
            _DEF = (getDEF() + getItem(index)->getdef());
            _maxHP = (getMaxHP() + getItem(index)->gethp());
            removeItem(getItem(index));
        }
        else
        {
            updateStats(getItem(index), _armor[2]);
            swapItems(getItem(index), _armor[2]);
        }
        return;
    }
    if(getItem(index)->getType() == "shield")
    {
        if(_armor[3] == nullptr)
        {
            std::cout << "I equipping shield! (+ "<< getItem(index)->getdef() << " DEF || + "<< getItem(index)->gethp() << " HP)" << std::endl;
            _armor[3] = getItem(index);
            _DEF = (getDEF() + getItem(index)->getdef());
            _maxHP = (getMaxHP() + getItem(index)->gethp());
            removeItem(getItem(index));
        }
        else
        {
            updateStats(getItem(index), _armor[3]);
            swapItems(getItem(index), _armor[3]);
        }
        return;
    }
    if(getItem(index)->getType() == "potion")
    {
        std::cout << "\"Drinking potion...\"\n";
        if(getItem(index)->getName() == "Red-potion")
        {
            if(25 + getHP() > getMaxHP()) setHP(getMaxHP());
            else setHP(getHP() + 25);
        }
        else
        {
            if(25 + getMANA() > getMaxMANA()) setMANA(getMaxMANA());
            else setMANA(getMANA() + 25);
        }
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