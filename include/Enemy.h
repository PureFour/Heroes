#include "Hero.h"

#ifndef HEROES_ENEMY_H
#define HEROES_ENEMY_H

class Enemy :public Hero
{
    std::vector<Enemy *> easy;
    std::vector<Enemy *> medium;
    std::vector<Enemy *> hard;
    std::vector<Enemy *> boss;
public:
    explicit Enemy(std::string n);
    ~Enemy();
    void attack(Hero &) override;
    Enemy* spawn(std::string); //dif lvls : easy/medium/hard/BOSS
};

#endif //HEROES_ENEMY_H
