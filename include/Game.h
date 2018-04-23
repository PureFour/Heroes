#include "Hero.h"
#ifndef HEROES_GAME_H
#define HEROES_GAME_H


class Game
{
    friend class Hero;
    unsigned int _Option;
    bool _Running = true;  //FOR WHILE MAIN LOOP
public:
    Game();
    virtual ~Game();
    //GetFunctions
    bool &getRunning();
    unsigned int &getOption();
    //
    void startMessage(std::string&) const;
    unsigned int HeroChoice();
    void mainMenu(Hero *);

};


#endif //HEROES_GAME_H
