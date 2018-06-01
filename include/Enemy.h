#include "Hero.h"

#ifndef HEROES_ENEMY_H
#define HEROES_ENEMY_H

class Enemy :public Hero
{
    static std::vector<Enemy *> easy;
    static std::vector<Enemy *> medium;
    static std::vector<Enemy *> hard;
    static std::vector<Enemy *> boss;
public:
    Enemy(std::string n, unsigned int, unsigned int, unsigned int, unsigned int);
    ~Enemy();
    void attack(Hero &) override;
    void equip(Item&) override;
    const void showItems() const override;
    Enemy* spawn(std::string); //dif lvls : easy/medium/hard/BOSS
};

#endif //HEROES_ENEMY_H