#include "../include/Game.h"

Game::Game() {}

Game::~Game() {}

bool &Game::getRunning() { return this->_Running;}
unsigned int &Game::getOption() { return this->_Option;}

void Game::startMessage() const
{
    std::cout << std::string(77, '=');
    std::cout << "\n\n" <<std::string(30, ' ') << "HEROES - THE GAME\n\n";
    std::cout << std::string(77, '=') << std::endl;
}

void Game::mainMenu()
{
    std::cout << std::string(77, '*') << std::endl;
    std::cout << "\n" <<std::string(32, ' ') <<"-MAIN MENU-\n"<< std::endl;
    std::cout << std::string(77, '*') << std::endl;
    std::cout << "(1) Hero Stats"<< std::endl;
    std::cout << "(2) Travel"<< std::endl;
    std::cout << "(3) Shop"<< std::endl;
    std::cout << "(4) LvlUp!"<< std::endl;
    std::cout << "(0) Exit Game"<< std::endl;
    std::cout << std::string(77, '=') << std::endl;
    std::cout << "My Choice: ";
    std::cin >> getOption(); //TODO Zrobic zabezpieczenie na niepoprawny input!
    // Kod na zabezpieczenie!
    switch(getOption())
    {
        case 0:
            this->_Running = false;
            break;
        case 1:

            break;
    }

}