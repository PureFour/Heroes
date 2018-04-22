#include <iomanip>
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>

#ifndef HEROES_GAME_H
#define HEROES_GAME_H


class Game
{
    unsigned int _Option;
    bool _Running = true;  //FOR WHILE MAIN LOOP
public:
    Game();
    virtual ~Game();
    //GetFunctions
    bool &getRunning();
    unsigned int &getOption();
    //
    void startMessage() const;
    void mainMenu();

};


#endif //HEROES_GAME_H
