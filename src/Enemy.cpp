#include "../include/Enemy.h"

Enemy::Enemy(std::string n, unsigned int ad) :Hero(n)
{

    this->_LVL = 1;
    this->_EXP = 0;
    this->_EXP2NEXTLVL = 0;

    this->_HP = 20;
    this->_MANA = 0;
    this->_AD = ad;
    this->_AP = 0;
    this->_DEF = 1;

    this->_Strenght = 1;
    this->_Vitality = 1;
    this->_Dexterity = 1;
    this->_Intelligence = 0;
    this->_Luck = 0;
}

std::vector<Enemy*> Enemy::easy = {new Enemy("Dog", 10), new Enemy("Wasp", 15), new Enemy("Bat", 19)};
std::vector<Enemy*> Enemy::medium = {};
std::vector<Enemy*> Enemy::hard = {};
std::vector<Enemy*> Enemy::boss = {new Enemy("Freakin Dog", 100), new Enemy("BIG SHITTY Wasp", 150), new Enemy("BLACK DICK Bat", 190)};

Enemy* Enemy::spawn(std::string difficulty_lvl)
{
    auto r = ((rand() & 3) + 0);
    if(difficulty_lvl == "easy") return easy[r];
    if(difficulty_lvl == "medium") return medium[r];
    if(difficulty_lvl == "hard") return hard[r];
    if(difficulty_lvl == "BOSS") return boss[r];
}

Enemy::~Enemy() {}

void Enemy::attack(Hero &hero)
{
    unsigned int damage, defence;
    unsigned int HP = hero.getHP();
    defence = ((rand() % (hero.getDEF() - hero.getDEF() / 2)) + hero.getDEF() / 2);
    damage = ((rand() % (getAD() - getAD() / 2)) + getAD() / 2);
    sleep(1);
    std::cout << "Enemy DMG = " << damage << std::endl;
    std::cout << "Your defence = " << defence << std::endl;
    if(defence < damage)
    {
        HP -= (damage - defence);
        hero.setHP(HP);
    }
    if(damage > HP) hero.setHP(0);
    std::cout << getName() << " is Attacking you!\n";
    std::cout << "Received damage: " << ((damage > defence) ? (damage - defence) : 0) << std::endl;
}
