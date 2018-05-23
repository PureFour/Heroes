#include "../include/Game.h"

Game::Game() {}

Game::~Game() {}

bool &Game::getRunning() { return this->_Running;}
unsigned int &Game::getOption() { return this->_Option;}

void Game::startMessage(std::string &n) const
{
    std::cout << std::string(77, '=');
    std::cout << "\n\n" <<std::string(30, ' ') << "HEROES - THE GAME\n\n";
    std::cout << std::string(77, '=') << "\n\n\n";

    const std::string message = "This is the story about";
    const int rows = 5;
    const std::string::size_type cols = message.size() + 5;
    for(int r = 0; r != rows; ++r)
    {
        std::string::size_type c = 0; //char type counter...
        while(c != cols)
        {
            if(c == 0) std::cout <<std::string(25, ' ');
            if(r == 2 && c == 2)
            {
                std::cout << message;
                c += message.size();
            }
            else
            {
                if(r == 0 || r == rows - 1 || c == 0 || c == cols -1) std::cout << '*';
                else std::cout << ' ';
                ++c;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "ENTER YOUR NAME: ";
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
    std::cin >> getOption();
    while(!std::cin.good() || getOption() > 5 )
    {
        std::cout << "Try again!" << std::endl;
        std::cin.clear();
        std::cin.ignore('1', '\n');
        std::cout << "My Choice:_\b";
        std::cin >> getOption();
    }
    ClearScreen();
    switch(getOption())
    {
        case 0:
            this->_Running = false;
            break;
        case 1:
            p->status();
            sleep(1);
            break;
        case 2:
            p->attack(enemy);
            sleep(1);
            break;
        case 3:

            break;
        case 4:
            InventoryMenu(p);
            sleep(1);
            break;
        case 5:
            p->LevelUp();
            sleep(1);
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
    bool running = true;
    while(running)
    {
        std::cout << "Choose Option!" << std::endl;
        std::cout << "(1) Show Inventory" << std::endl;
        std::cout << "(2) Add Item" << std::endl;
        std::cout << "(3) Remove Item" << std::endl;
        std::cout << "(0) Quit" << std::endl;
        std::cin >> getOption();
        while(!std::cin.good() || getOption() > 3 )
        {
            std::cout << "Try again!" << std::endl;
            std::cin.clear();
            std::cin.ignore('1', '\n');
            std::cout << "My Choice:_\b";
            std::cin >> getOption();
        }
        switch(getOption())
        {
            case 0:
                running = false;
                break;
            case 1:
                p->showInv();
                break;
            case 2:

                break;
            case 3:
                std::cin >> getOption();
                break;
            default:
                break;
        }
    }
}

