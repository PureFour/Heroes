#include "../include/Game.h"
#include "../include/Warrior.h"

Game::Game() {}

Game::~Game() {}

bool &Game::getRunning() { return this->_Running;}

void Game::setRunning()
{
    _Running = !getRunning() && true;
}

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

void Game::mainMenu(Hero *p, Shop *s, Enemy *e)
{
    std::cout << std::string(WIDTH, '*') << std::endl;
    std::cout << "\n" <<std::string(32, ' ') <<"-MAIN MENU-\n"<< std::endl;
    std::cout << std::string(WIDTH, '*') << std::endl;
    std::cout << "(1) Hero Stats"<< std::endl;
    std::cout << "(2) Travel"<< std::endl;
    std::cout << "(3) Shop"<< std::endl;
    std::cout << "(4) Inventory"<< std::endl;
    std::cout << "(5) LvlUp! "<< ((p->getEXP() > p->getEXP2NEXTLVL()) ? "(You can add skill points!)":"") << std::endl;
    std::cout << "(0) Exit Game"<< std::endl;
    std::cout << std::string(WIDTH, '=') << std::endl;
    std::cout << "My Choice:_\b";
    std::string opc;
    switch(myInput(6))
    {
        case 0:
            this->_Running = false;
            break;
        case 1:
            ClearScreen();
            p->status();
            break;
        case 2:
            ClearScreen();
            std::cout << "Which lvl?\n" << "easy|medium|hard|BOSS" << std::endl;
            std::cin >> opc;
            e = e->spawn(opc);
            Fight(*p, *e);
            break;
        case 3:
            ClearScreen();
            s->Menu(p);
            break;
        case 4:
            ClearScreen();
            InventoryMenu(p);
            break;
        case 5:
            ClearScreen();
            p->LevelUp();
            break;
        default:
            break;
    }
}

unsigned int Game::HeroChoice()
{
    std::cout << std::string(WIDTH, '-') << std::endl;
    std::cout << "Choose Hero Class!" << std::endl;
    std::cout << "(1) Warrior" << std::endl;
    std::cout << "(2) Mage" << std::endl;
    std::cout << "(3) Archer" << std::endl;
    std::cout << std::string(WIDTH, '-') << std::endl;
    std::cout << "My Choice:_\b";
    return myInput(3); //function from functions.h
}

void Game::InventoryMenu(Hero *p)
{
    bool running = true;
    while(running)
    {
        std::cout << "Choose Option!" << std::endl;
        std::cout << "(1) SHOW EQUIPMENT" << std::endl;
        std::cout << "(2) SHOW INVENTORY" << std::endl;
        std::cout << "(3) EQUIP ITEM" << std::endl;
        std::cout << "(4) REMOVE ITEM" << std::endl;
        std::cout << "(0) QUIT" << std::endl;
        switch(myInput(5))
        {
            case 0:
                running = false;
                break;
            case 1:
                p->showItems();
                break;
            case 2:
                p->showInv();
                break;
            case 3:
                p->equip();
                break;
            case 4:

                break;
            default:
                break;
        }
    }
}

void Game::Fight(Hero &hero, Enemy &enemy)
{
    std::cout << "FIGHT!\n\n" << std::endl;
    unsigned int HP = enemy.getHP();
    int i = 1;
    while(hero.getHP() > 0 && enemy.getHP() > 0)
    {
        std::cout << std::string(12, ' ') << "ROUND " << i  << '!' << std::endl;
        std::cout << std::string(WIDTH, '=') << std::endl;
        std::cout << "Hero HP= " << hero.getHP() << " |||| ";
        std::cout << "Enemy HP = " << enemy.getHP() << std::endl;
        std::cout << std::string(WIDTH, '=') << std::endl;
        enemy.attack(hero);
        sleep(2);
        std::cout << std::string(WIDTH, '+') << std::endl;
        hero.attack(enemy);
        i++;
        std::cout << std::endl;
    }
    if(enemy.getHP() == 0)
    {
        std::cout << "Enemy defeated!" << std::endl;
        unsigned int reward = ((rand() % 100) + 20);
        hero.setEXP(hero.getEXP() + enemy.getEXP());
        hero.setGold(hero.getGold() + reward);
        std::cout << "Gold earned: " << reward << '!' << std::endl;
        std::cout << "Exp earned: " << enemy.getEXP() << '!' << std::endl;
    }
    if(hero.getHP() == 0)
    {
        std::cout << "You have been defeated!" << std::endl;
        std::cout << "\n" <<std::string(32, ' ') <<"-GAME OVER-\n"<< std::endl;
        setRunning();
    }
    enemy.setHP(HP); //resetting enemy hp...
}