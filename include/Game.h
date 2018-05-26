#include "Hero.h"
#include "../include/Enemy.h"
#include "Shop.h"
#ifndef HEROES_GAME_H
#define HEROES_GAME_H


class Game
{
    friend class Hero;
    friend class Enemy;
    unsigned int _Option;
    bool _Running = true;  //FOR WHILE MAIN LOOP

    void Fight(Hero&, Enemy&);
public:
    Game();
    virtual ~Game();
    //GetFunctions
    bool &getRunning();
    unsigned int &getOption();
    //

    //Set Functions
    void setRunning();
    //
    void startMessage(std::string&) const;
    unsigned int HeroChoice();
    void mainMenu(Hero *);
    void InventoryMenu(Hero *);

};


#endif //HEROES_GAME_H
