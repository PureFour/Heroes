#include "Hero.h"
#include "../include/Enemy.h"
#include "Shop.h"
#include <fstream>
#ifndef HEROES_GAME_H
#define HEROES_GAME_H


class Game
{
private:
    friend class Hero;
    friend class Enemy;
    bool _Alive = true;
    bool _Running = true;  //FOR MAIN WHILE LOOP
    void Fight(Hero&, Enemy&);
public:
    Game();
    virtual ~Game();
    //GetFunctions
    bool &getRunning();
    bool &getAlive();
    //Set Functions
    void setRunning();
    //
    void startMessage(std::string&) const;
    unsigned int HeroChoice();
    void mainMenu(Hero *, Shop *, Enemy *);
    void InventoryMenu(Hero *);
    const void Save(Hero *) const;
    const void Load(Hero *);
};


#endif //HEROES_GAME_H
