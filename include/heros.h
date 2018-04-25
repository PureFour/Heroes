#include <iostream>

#ifndef GIERKA_HEROS_H
#define GIERKA_HEROS_H

class Hero  //BASE CLASS
{
public:
    Hero(int hp, int mana, int ad, int def)
            : _HP(hp), _MANA(mana), _AD(ad), _DEF(def){};

protected:
    int _HP;
    int _MANA;
    int _AD;
    int _DEF;

public:
    virtual void status() = 0;
    virtual void attack() = 0;
};

class Warrior : public Hero
{
public:
    Warrior(int hp = 150, int mana = 0, int ad = 12, int def = 10) :Hero(hp, mana, ad, def)
    {std::cout << "Warrior constructor works here...\n";};
    void attack() override;
    void status() override;
};

class Mage :public Hero
{
public:
    Mage(int hp = 100, int mana = 100, int ad = 2, int def = 5) :Hero(hp, mana, ad, def)
    {std::cout << "Mage constructor works here...\n";};
    void attack() override;
    void status() override;
};

class Archer :public Hero
{
public:
    Archer(int hp = 120, int mana = 0, int ad = 20, int def = 4) :Hero(hp, mana, ad, def)
    {std::cout << "Archer constructor works here...\n";};
    void attack() override;
    void status() override;
};
#endif //GIERKA_HEROS_H
