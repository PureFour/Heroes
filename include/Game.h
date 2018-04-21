#include <iomanip>
#include <iostream>
#ifndef HEROES_GAME_H
#define HEROES_GAME_H


class Game
{

public:
    Game();
    virtual ~Game();
    bool running = 0; //FOR WHILE MAIN LOOP
    void mainMenu() const;

};


#endif //HEROES_GAME_H
