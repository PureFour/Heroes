#include "Hero.h"
#include "../include/Enemy.h"
#include "Shop.h"
#ifndef HEROES_GAME_H
#define HEROES_GAME_H


class Game
{
private:
    friend class Hero;
    friend class Enemy;
    bool _Running = true;  //FOR MAIN WHILE LOOP
    void Fight(Hero&, Enemy&);
public:
    Game();
    virtual ~Game();
    //GetFunctions
    bool &getRunning();
    //Set Functions
    void setRunning();
    //
    void startMessage(std::string&) const;
    unsigned int HeroChoice();
    void mainMenu(Hero *, Shop *, Enemy *);
    void InventoryMenu(Hero *);

};


#endif //HEROES_GAME_H
