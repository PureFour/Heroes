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
    Enemy enemy("DOG", 10);

    std::cout << std::string(77, '*') << std::endl;
    std::cout << "\n" <<std::string(32, ' ') <<"-MAIN MENU-\n"<< std::endl;
    std::cout << std::string(77, '*') << std::endl;
    std::cout << "(1) Hero Stats"<< std::endl;
    std::cout << "(2) Travel"<< std::endl;
    std::cout << "(3) Shop"<< std::endl;
    std::cout << "(4) Inventory"<< std::endl;
    std::cout << "(5) LvlUp!"<< std::endl;
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
            sleep(2);
            break;
        case 2:
            enemy.attack(*p);
            sleep(2);
            break;
        case 3:

            break;
        case 4:
            p->showInv();
            sleep(2);
            break;
        case 5:
            p->LevelUp();
            sleep(2);
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

void Game::InventoryMenu(Hero *p)
{
    std::cout << "Choose Option!" << std::endl;
    std::cout << "(1) Show Inventory" << std::endl;
    std::cout << "(2) Add Item" << std::endl;
    std::cout << "(3) Remove Item" << std::endl;
    std::cin >> getOption();
    switch(getOption())
    {
        case 1:
            p->showInv();
            break;
        case 2:

            break;
        case 3:

            break;
        default:
            break;
    }
}

