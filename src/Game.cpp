#include "../include/Game.h"

Game::Game() {}

Game::~Game() {}

bool &Game::getRunning() { return this->_Running;}
unsigned int &Game::getOption() { return this->_Option;}

void Game::startMessage(std::string &n) const
{
    std::cout << std::string(77, '=');
    std::cout << "\n\n" <<std::string(30, ' ') << "HEROES - THE GAME\n\n";
    std::cout << std::string(77, '=') << std::endl;
    std::cout << "\n\n\n\nThis is the story about..." << "__________\b\b\b\b\b\b\b\b\b\b";
    std::cin >> n;
    ClearScreen();
}

void Game::mainMenu(Hero *p)
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
    std::cout << "My Choice:_\b";
    std::cin >> getOption(); //TODO Zrobic zabezpieczenie na niepoprawny input!
    ClearScreen();
    // Kod na zabezpieczenie!
    switch(getOption())
    {
        case 0:
            this->_Running = false;
            break;
        case 1:
            p->status();
            break;
        default:
            break;
    }

}

unsigned int Game::HeroChoice()
{
    std::cout << std::string(77, '-') << std::endl;
    std::cout << "Choose Hero Class!" << std::endl;
    std::cout << "(1) Warrior" << std::endl;
    std::cout << "(2) Mage" << std::endl;
    std::cout << "(3) Archer" << std::endl;
    std::cout << std::string(77, '-') << std::endl;
    std::cout << "My Choice:_\b";
    std::cin >> getOption(); // TODO zabezpieczyc tu rowniez!
    ClearScreen();
    return getOption();
}

