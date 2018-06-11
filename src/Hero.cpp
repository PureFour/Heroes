#include "../include/Hero.h"
#include "../include/Warrior.h"
#include "../include/Mage.h"
#include "../include/Archer.h"

Hero::Hero(std::string n) :name(std::move(n)) { setSize(5); }
Hero::~Hero() = default;

const unsigned int& Hero::getX() const { return this->_X; }
const unsigned int& Hero::getY() const { return this->_Y; }
const unsigned int& Hero::getGold() const { return this->_GOLD; }

const std::string &Hero::getName() const{ return this->name; }
const unsigned int &Hero::getHP() const { return this->_HP; }
const unsigned int &Hero::getMaxHP() const { return this->_maxHP; }
const unsigned int &Hero::getMANA() const { return this->_MANA; }
const unsigned int &Hero::getMaxMANA() const { return this->_maxMANA; }
const unsigned int &Hero::getAD() const { return this->_AD; }
const unsigned int &Hero::getAP() const { return this->_AP; }
const unsigned int &Hero::getDEF() const { return this->_DEF; }
const unsigned int &Hero::getLVL() const { return this->_LVL; }
const unsigned int &Hero::getEXP() const { return this->_EXP; }
const unsigned int &Hero::getEXP2NEXTLVL() const { return this->_EXP2NEXTLVL; }

const unsigned int &Hero::getStr() const { return this->_Strenght; }
const unsigned int &Hero::getVit() const { return this->_Vitality; }
const unsigned int &Hero::getDex() const { return this->_Dexterity; }
const unsigned int &Hero::getInt() const { return this->_Intelligence; }
const unsigned int &Hero::getLuck() const { return this->_Luck; }
const std::array<Item*, 4>& Hero::getArmor() const { return this->_armor; }
const Item* Hero::getWeapon() const { return this->_weapon; }
const unsigned int& Hero::getArrows() const { return this->_Arrows; }

void Hero::setName(std::string n) { name = n; }
void Hero::setHP(unsigned int hp) { _HP = hp; }
void Hero::setMaxHP(unsigned int max) { _maxHP = max; }
void Hero::setMANA(unsigned int mana) { _MANA = mana; }
void Hero::setMaxMANA(unsigned int max) { _maxMANA = max; }
void Hero::setLVL(unsigned int lv) { _LVL = lv; }
void Hero::setEXP(unsigned int exp) { _EXP = exp; }
void Hero::setEXP2NEXTLV(unsigned int exp2) { _EXP2NEXTLVL = exp2; }
void Hero::setGold(unsigned int gold) { _GOLD = gold; }
void Hero::setAD(unsigned int ad) { _AD = ad; }
void Hero::setAP(unsigned int ap) { _AP = ap; }
void Hero::setDEF(unsigned int def) { _DEF = def; }
void Hero::setStr(unsigned int str) { _Strenght = str; }
void Hero::setVit(unsigned int vit) { _Vitality = vit; }
void Hero::setDex(unsigned int dex) { _Dexterity = dex; }
void Hero::setInt(unsigned int _int) { _Intelligence = _int; }
void Hero::setLuck(unsigned int luck) { _Luck = luck; }
void Hero::setArrows(unsigned int arrows) { _Arrows = arrows; }
Hero *Hero::Initialize(std::string n, unsigned int choice)
{
    switch(choice)
    {
        case 0:
            return new Warrior(n);
        case 1:
            return new Mage(n);
        case 2:
            return new Archer(n);
        default:
            break;
    }
}

void Hero::status()
{
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Lvl: " << getLVL() << std::endl;
    std::cout << "Exp: " << getEXP() << std::endl;
    std::cout << "Exp to next Lvl: " << getEXP2NEXTLVL() << std::endl;
    std::cout << "GOLD: " << getGold() << std::endl;
    std::cout << std::string(WIDTH, '-') << std::endl;
    std::cout << "HP: " << getHP() << "/" << getMaxHP() << std::endl;
    std::cout << "MANA: " << getMANA() << "/" << getMaxMANA() << std::endl;
    std::cout << "AD: " << getAD() << std::endl;
    std::cout << "AP: " << getAP() << std::endl;
    std::cout << "DEF: " << getDEF() << std::endl;
    std::cout << std::string(WIDTH, '-') << std::endl;
    std::cout << "Strenght: " << getStr() << std::endl;
    std::cout << "Vitality: " << getVit() << std::endl;
    std::cout << "Dexterity: " << getDex() << std::endl;
    std::cout << "Intelligence: " << getInt() << std::endl;
    std::cout << "Luck: " << getLuck() << std::endl;
    std::cout << std::string(WIDTH, '-') << std::endl;
}

void Hero::LevelUp()
{
    int points = 0;
    if (this->_EXP < this->_EXP2NEXTLVL)
        std::cout << "You don't have enought experience!" << std::endl;
    else
    {
        while (this->_EXP > this->_EXP2NEXTLVL) {
            this->_LVL += 1;
            this->_EXP -= this->_EXP2NEXTLVL;
            this->_EXP2NEXTLVL = static_cast<unsigned int>(((50 / 3) * (pow(this->_LVL, 3.0)) - (6.0 * pow(this->_LVL, 3.0)) + (17.0 * this->_LVL) -
                                                            11.0)); //LVL^UP FORMULA
            points += 1;
        }
        std::cout << "LVL UP!\nYOUR LV IS " << getLVL() << " NOW!" << std::endl;
    }

    addPoints(points);
}
bool Hero::Crit(unsigned int luck)
{
    return rand() % 100 < 10 * luck;
}

void Hero::addPoints(int points)
{
    while(points)
    {
        std::cout << "You can add "<< points << "points to stats!" << std::endl;
        std::cout << "(1)Strenght: " << getStr() << std::setw(20) << "[1 = 2 AD]" << std::endl;
        std::cout << "(2)Vitality: " << getVit() << std::setw(21) << "[1 = 25 HP]" << std::endl;
        std::cout << "(3)Dexterity: " << getDex() << std::setw(20) << "[1 = 3 DEF]" << std::endl;
        std::cout << "(4)Intelligence: " << getInt() << std::setw(19) << "[1 = 25 MANA]" << std::endl;
        std::cout << std::string(WIDTH, '-') << std::endl;
        switch(myInput(5))
        {
            case 1:
                _Strenght += 1;
                _AD += 2;
                break;
            case 2:
                _Vitality += 1;
                _maxHP += 25;
                break;
            case 3:
                _Dexterity += 1;
                _DEF += 3;
            case 4:
                _Intelligence += 1;
                _maxMANA += 25;
                break;
            default:
                break;
        }
        points -= 1;
    }
}

void Hero::updateStats(Item *a, Item *b)
{
    if(a->gethp() > b->gethp()) setMaxHP(getMaxHP() + (a->gethp() - b->gethp()));
    else setMaxHP(getMaxHP() - (b->gethp() - a->gethp()));

    if(a->getmana() > b->getmana()) setMaxMANA(getMaxMANA() + (a->getmana() - b->getmana()));
    else setMaxMANA(getMaxMANA() - (b->getmana() - a->getmana()));

    if(a->getad() > b->getad()) setAD(getAD() + (a->getad() - b->getad()));
    else setAD(getAD() - (b->getad() - a->getad()));

    if(a->getap() > b->getap()) setAP(getAP() + (a->getap() - b->getap()));
    else setAP(getAP() - (b->getap() - a->getap()));

    if(a->getluck() > b->getluck()) setLuck(getLuck() + (a->getluck() - b->getluck()));
    else setLuck(getLuck() - (b->getluck() - a->getluck()));

    if(a->getdef() > b->getdef()) setDEF(getDEF() + (a->getdef() - b->getdef()));
    else setDEF(getDEF() - (b->getdef() - a->getdef()));
}







