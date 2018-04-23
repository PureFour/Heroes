#include "Hero.h"

#ifndef HEROES_ENEMY_H
#define HEROES_ENEMY_H

class Enemy :public Hero
{
public:
    explicit Enemy(std::string n);
    ~Enemy();
    void attack(Hero &) override;
};

#endif //HEROES_ENEMY_H
