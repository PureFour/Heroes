#include "../include/Hero.h"
#include "../include/Mage.h"

Mage::Mage(std::string n) : Hero(n)
{
    this->_X = 0;
    this->_Y = 0;

    this->_GOLD = 0;
    this->_LVL = 1;
    this->_EXP = 0;
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

void Mage::attack(Hero &enemy) //TODO poprawic!!!
{
    unsigned int damage = 0, defence = 0, attack = 0, magic_attack = 0;
    unsigned int HP = enemy.getHP();
    defence = ((rand() % (enemy.getDEF() - enemy.getDEF() / 2)) + enemy.getDEF() / 2);
    attack = ((rand() % (getAD() - getAD() / 2)) + getAD() / 2);
    magic_attack = ((rand() % (getAP() - getAP() / 2)) + getAP() / 2);
    std::cout << "(0)Normal attack!\n";
    std::cout << "(1)Magic attack![Your Mana: " << getMANA() << "]\n";
    switch(myInput(2))
    {
        case 0:
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
                std::cout << "You missed!\n";
            }
            break;
        case 1:
            std::cout << "Your skills: \n";
            std::cout << "\t(0)FireBall! (10 MANA)\n";
            std::cout << "\t(1)FrozenSpike! (30 MANA)\n";
            std::cout << "\t(2)DarkMatterLASER! (50 MANA)\n";
            switch(myInput(3))
            {
                case 0:
                    std::cout << "FIREBALL!\n";
                    if(getMANA() >= 10)
                    {
                        setMANA(getMANA() - 10);
                        magic_attack *= 2;
                    } else std::cout << "You don't have enought mana!\n";
                    break;
                case 1:
                    std::cout << "FrozenSpike!\n";
                    if(getMANA() >= 30)
                    {
                        setMANA(getMANA() - 30);
                        magic_attack *= 3;
                    } else std::cout << "You don't have enought mana!\n";
                    break;
                case 2:
                    std::cout << "DarkMatterLASER!\n";
                    if(getMANA() >= 50)
                    {
                        setMANA(getMANA() - 50);
                        magic_attack *= 5;
                    } else std::cout << "You don't have enought mana!\n";
                    break;
                default:
                    break;
            }
            if(magic_attack > defence)
            {
                damage = magic_attack - defence;
                printf("Your MAGIC DMG= %i\n", damage);
                if(damage < HP) enemy.setHP(HP - damage);
                else enemy.setHP(0);
            } else std::cout << "You missed!\n";
            break;
        default:
            break;
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
        if(_weapon == nullptr)
        {
            std::cout << "I equipping weapon!(+ " << getItem(index)->getap() << " AP || + "<< getItem(index)->getmana() << " MANA)" << std::endl;
            _weapon = getItem(index);
            _AP = (getAP() + getItem(index)->getap());
            _maxMANA = (getMaxMANA() + getItem(index)->getmana());
            removeItem(getItem(index));
        }
        else
        {
            std::cout << "Items swapped!\n";
            updateItems(getItem(index), _weapon);
            swapItems(getItem(index), _weapon);
        }
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
            std::cout << "Items swapped!\n";
            updateItems(getItem(index), _armor[0]);
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
            std::cout << "Items swapped!\n";
            updateItems(getItem(index), _armor[1]);
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
            std::cout << "Items swapped!\n";
            updateItems(getItem(index), _armor[2]);
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
            std::cout << "Items swapped!\n";
            updateItems(getItem(index), _armor[3]);
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
