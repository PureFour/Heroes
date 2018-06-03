#include "../include/Enemy.h"

Enemy::Enemy(std::string n, unsigned int ad, unsigned int def, unsigned int hp, unsigned int exp) :Hero(n)
{
    this->_EXP = exp;
    this->_HP = hp;
    this->_AD = ad;
    this->_DEF = def;
}

std::vector<Enemy*> Enemy::easy = {new Enemy("Dog", 5, 1, 10, 20), new Enemy("Swarm of wasp", 10, 2, 15, 30), new Enemy("Bat", 15, 5, 20, 40)};
std::vector<Enemy*> Enemy::medium = {new Enemy("Orc", 25, 10, 20, 50), new Enemy("Great Knight", 30, 12, 25, 60), new Enemy("Paladin", 35, 14, 40, 80)};
std::vector<Enemy*> Enemy::hard = {new Enemy("Black Elf", 40, 15, 20, 80), new Enemy("Big Lizard", 30, 20, 80, 100), new Enemy("King of monkeys", 50, 24, 100, 150)};
std::vector<Enemy*> Enemy::boss = {new Enemy("Freakin Dog!", 100, 50, 200, 200), new Enemy("BIG Black Wolf!", 150, 55, 300, 400), new Enemy("RED Bat!", 200, 100, 500, 500)};

Enemy::~Enemy() {}

void Enemy::attack(Hero &hero)
{
    unsigned int damage = 0, defence = 0, attack = 0;
    unsigned int HP = hero.getHP();
    defence = ((rand() % (hero.getDEF() - hero.getDEF() / 2)) + hero.getDEF() / 2);
    attack = ((rand() % (getAD() - getAD() / 2)) + getAD() / 2);
    std::cout << std::string(23, ' ') << getName() << " is attacking you!\n\n";
    std::cout << std::string(50, ' ') << "My DEF = " << defence << std::endl;
    if(attack > defence)
    {
        damage = attack - defence;
        if(Crit(getLuck()))
        {
            damage *= 2;
            std::cout << std::string(50, ' ') << "Critical HIT! : " << damage << std::endl;
        }
        else std::cout << std::string(50, ' ') << "Enemy DMG = " << damage << std::endl;
        if(damage < HP) hero.setHP(HP - damage);
        else hero.setHP(0);
    }
    else
    {
        damage = 0;
        std::cout << std::string(50, ' ') << getName() << " missed!\n";
    }
}

Enemy* Enemy::spawn(std::string difficulty_lvl)
{
    auto r = ((rand() % 3) + 0);
    std::cout << "r = " << r << std::endl;
    if(difficulty_lvl == "easy") return easy[r];
    if(difficulty_lvl == "medium") return medium[r];
    if(difficulty_lvl == "hard") return hard[r];
    if(difficulty_lvl == "BOSS") return boss[r];
}

void Enemy::equip() {}
const void Enemy::showItems() const {}