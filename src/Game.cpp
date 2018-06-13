#include "../include/Game.h"

Game::Game() {}

Game::~Game() {}

bool &Game::getRunning() { return this->_Running;}
bool& Game::getAlive() { return this->_Alive; }

void Game::setRunning() { _Running = !getRunning() && true; }

const void Game::Save(Hero *hero) const
{
    std::fstream file;
    file.open("../saved_games/save.txt", std::fstream::out | std::fstream::trunc);
    file << hero->getName() << std::endl;
    file << hero->getLVL() << std::endl;
    file << hero->getEXP() << std::endl;
    file << hero->getEXP2NEXTLVL() << std::endl;
    file << hero->getGold() << std::endl;
    file << hero->getHP() << std::endl;
    file << hero->getMANA() << std::endl;
    file << hero->getAD() << std::endl;
    file << hero->getAP() << std::endl;
    file << hero->getDEF() << std::endl;
    file << hero->getStr() << std::endl;
    file << hero->getVit() << std::endl;
    file << hero->getDex() << std::endl;
    file << hero->getInt() << std::endl;
    file << hero->getLuck() << std::endl;

    file.close();
    std::cout << "GAME SAVED!\n";
}
const void Game::Load(Hero *hero)
{
    std::string name;
    unsigned int stat;
    std::fstream file;
    file.open("../saved_games/save.txt", std::fstream::in);
    std::cout << "Do you wanna load game?" << std::endl;
    std::cout << "(1) YES!\n(0) NO...\n";
    switch(myInput(2))
    {
        case 0:
            return;
        case 1:
            file >> name; hero->setName(name);
            file >> stat; hero->setLVL(stat);
            file >> stat; hero->setEXP(stat);
            file >> stat; hero->setEXP2NEXTLV(stat);
            file >> stat; hero->setGold(stat);
            file >> stat; hero->setHP(stat);
            file >> stat; hero->setMANA(stat);
            file >> stat; hero->setAD(stat);
            file >> stat; hero->setAP(stat);
            file >> stat; hero->setDEF(stat);
            file >> stat; hero->setStr(stat);
            file >> stat; hero->setVit(stat);
            file >> stat; hero->setDex(stat);
            file >> stat; hero->setInt(stat);
            file >> stat; hero->setLuck(stat);
            if(!getRunning()) setRunning();
            _Alive = true;
            break;
        default:
            break;
    }
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
    std::cout << "(5) Upgrade stuff"<< std::endl;
    std::cout << "(6) LvlUp! "<< ((p->getEXP() > p->getEXP2NEXTLVL()) ? "(You can add skill points!)":"") << std::endl;
    std::cout << "(7) Save Game"<< std::endl;
    std::cout << "(8) Load Game"<< std::endl;
    std::cout << "(0) Exit Game"<< std::endl;
    std::cout << std::string(WIDTH, '=') << std::endl;
    std::cout << "My Choice:_\b";
    std::string opc;
    switch(myInput(9))
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
            e = e->spawn(EnemyMenu());
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
            UpgradeItemMenu(p);
            break;
        case 6:
            ClearScreen();
            p->LevelUp();
            break;
        case 7:
            Save(p);
            break;
        case 8:
            Load(p);
            break;
        default:
            break;
    }
}

unsigned int Game::HeroChoice()
{
    std::cout << std::string(WIDTH, '-') << std::endl;
    std::cout << "Choose Hero Class!" << std::endl;
    std::cout << "(0) Warrior" << std::endl;
    std::cout << "(1) Mage" << std::endl;
    std::cout << "(2) Archer" << std::endl;
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
        std::cout << "(3) EQUIP/USE ITEM" << std::endl;
        std::cout << "(0) QUIT" << std::endl;
        switch(myInput(4))
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
            default:
                break;
        }
    }
}

void Game::UpgradeItemMenu(Hero *h) const
{
    std::cout << std::string(WIDTH, 'I') << std::endl;
    std::cout << std::string(32, ' ') << "Welcome in my forge!" << std::endl;
    std::cout << std::string(WIDTH, 'I') << std::endl;
    h->showItems();
    std::cout << "What u want to upgrade?" << std::endl;
    std::cout << "(0)Weapon\n";
    std::cout << "(1)Helmet\n";
    std::cout << "(2)Breastplate\n";
    std::cout << "(3)Boots\n";
    std::cout << "(4)Shield\n";
    std::cout << "(5)QUIT\n";
    Item *i = nullptr;
    unsigned int cost = 0;
    unsigned int choice;
    switch(myInput(6))
    {
        case 0:
            i = h->getWeapon();
            cost = (i->getSellValue() * i->getlvl());
            std::cout << "Weapon upgrade cost: " << cost << " || Your gold : " << h->getGold() << std::endl;
            std::cout << "Do you wanna upgrade [" << i->getName() << "] +" << i->getlvl() + 1 << " ? (0-YES/1-NO)\n";
            choice = myInput(2);
            if(choice == 0)
            {
                if (h->getGold() >= cost)
                {
                    h->setGold(h->getGold() - cost);
                    h->setAD(h->getAD() + i->getlvl());
                    ++(*i);
                }
                else std::cout << "You don't have enough gold!\n";
            }
            break;
        case 1:
            i = h->getArmor()[0];
            cost = (i->getSellValue() * i->getlvl());
            std::cout << "Helmet upgrade cost: " << cost << " || Your gold : " << h->getGold() << std::endl;
            std::cout << "Do you wanna upgrade [" << i->getName() << "] +" << i->getlvl() + 1 << " ? (0-YES/1-NO)\n";
            choice = myInput(2);
            if(choice == 0)
            {
                if (h->getGold() >= cost)
                {
                    h->setGold(h->getGold() - cost);
                    h->setDEF(h->getDEF() + i->getlvl());
                    ++(*i);
                }
                else std::cout << "You don't have enough gold!\n";
            }
            break;
        case 2:
            i = h->getArmor()[1];
            cost = (i->getSellValue() * i->getlvl());
            std::cout << "Breastplate upgrade cost: " << cost << " || Your gold : " << h->getGold() << std::endl;
            std::cout << "Do you wanna upgrade [" << i->getName() << "] +" << i->getlvl() + 1 << " ? (0-YES/1-NO)\n";
            choice = myInput(2);
            if(choice == 0)
            {
                if (h->getGold() >= cost)
                {
                    h->setGold(h->getGold() - cost);
                    h->setDEF(h->getDEF() + i->getlvl());
                    h->setHP(h->getHP() + 10 * i->getlvl());
                    ++(*i);
                }
                else std::cout << "You don't have enough gold!\n";
            }
            break;
        case 3:
            i = h->getArmor()[2];
            cost = (i->getSellValue() * i->getlvl());
            std::cout << "Boots upgrade cost: " << cost << " || Your gold : " << h->getGold() << std::endl;
            std::cout << "Do you wanna upgrade [" << i->getName() << "] +" << i->getlvl() + 1 << " ? (0-YES/1-NO)\n";
            choice = myInput(2);
            if(choice == 0)
            {
                if (h->getGold() >= cost)
                {
                    h->setGold(h->getGold() - cost);
                    h->setDEF(h->getDEF() + i->getlvl());
                    h->setHP(h->getHP() + 5 * i->getlvl());
                    ++(*i);
                }
                else std::cout << "You don't have enough gold!\n";
            }
            break;
        case 4:
            i = h->getArmor()[3];
            cost = (i->getSellValue() * i->getlvl());
            std::cout << "Shield upgrade cost: " << cost << " || Your gold : " << h->getGold() << std::endl;
            std::cout << "Do you wanna upgrade [" << i->getName() << "] +" << i->getlvl() + 1 << " ? (0-YES/1-NO)\n";
            choice = myInput(2);
            if(choice == 0)
            {
                if (h->getGold() >= cost)
                {
                    h->setGold(h->getGold() - cost);
                    h->setDEF(h->getDEF() + i->getlvl());
                    h->setHP(h->getHP() + 5 * i->getlvl());
                    ++(*i);
                }
                else std::cout << "You don't have enough gold!\n";
            }
            break;
        case 5:
            return;
        default:
            break;
    }

}

void Game::Fight(Hero &hero, Enemy &enemy)
{
    unsigned int HP = enemy.getHP();
    std::cout << "FIGHT!\n\n" << std::endl;
    int i = 1;
    int j = 0;
    while(hero.getHP() > 0 && enemy.getHP() > 0)
    {
        std::cout << std::string(35, ' ') << "ROUND " << i  << '!' << std::endl;
        std::cout << std::string(WIDTH, '=') << std::endl;
        std::cout << std::string(23, ' ') << "Hero HP= " << hero.getHP() << " |||| ";
        std::cout << "Enemy HP = " << enemy.getHP() << std::endl;
        std::cout << std::string(WIDTH, '=') << std::endl;
        enemy.attack(hero);
        sleep(2);
        std::cout << std::string(WIDTH, '+') << std::endl;
        std::cout << "Your actions:\n" << "(0) Attack Enemy!\n" << "(1) Drink Potions!\n";
        if(hero.getHP() < 25) std::cout << "(2) RUN AWAY!\n"; j = 1;
        switch(myInput(2 + j))
        {
            case 0:
                hero.attack(enemy);
                sleep(2);
                break;
            case 1:
                std::cout << "Choose potion...\n";
                std::cout << "(0)Red Potion [+ 25 HP]\n (1)Blue Potion [+ 25 MANA]\n";
                switch(myInput(2))
                {
                    case 0:
                        if(hero.removeItem(hero.searchItem("Red-potion")) == 1)
                        {
                            std::cout << "\"Drinking Red potion...\"\n";
                            if(25 + hero.getHP() > hero.getMaxHP()) hero.setHP(hero.getMaxHP());
                            else hero.setHP(hero.getHP() + 25);
                        }
                        else std::cout << "You don't have Red potions!!!";
                        break;
                    case 1:
                        if(hero.removeItem(hero.searchItem("Blue-potion")) == 1)
                        {
                            std::cout << "\"Drinking Blue potion...\"\n";
                            if(25 + hero.getMANA() > hero.getMaxMANA()) hero.setMANA(hero.getMaxMANA());
                            hero.setMANA(hero.getMANA() + 25);
                        }
                        else std::cout << "You don't have Blue potions!!!";
                        break;
                    default:
                        break;
                }
            case 2:
                if(hero.getHP() < 25)
                {
                    std::cout << "You ran away!\n";
                    return;
                }
                continue;
            default:
                break;
        }
        i++;
        std::cout << std::endl;
        if(enemy.getHP() == 0)
        {
            std::cout << "Enemy defeated!" << std::endl;
            unsigned int reward = ((rand() % (enemy.getEXP()/2)) + 0);
            hero.setEXP(hero.getEXP() + enemy.getEXP());
            hero.setGold(hero.getGold() + reward);
            std::cout << "Gold earned: " << reward << '!' << std::endl;
            std::cout << "Exp earned: " << enemy.getEXP() << '!' << std::endl;
        }
        if(hero.getHP() == 0)
        {
            std::cout << "You have been defeated!" << std::endl;
            std::cout << "\n" <<std::string(32, ' ') <<"-GAME OVER-\n"<< std::endl;
            _Alive = false;
            setRunning();
        }
    }
    enemy.setHP(HP); //resetting enemy hp...
}

std::string Game::EnemyMenu() const
{
    std::cout << "Which lvl?\n";
    std::cout << "(0)Easy\n";
    std::cout << "(1)Medium\n";
    std::cout << "(2)Hard\n";
    std::cout << "(3)BOSS!\n";
    switch(myInput(4))
    {
        case 0:
            return (std::string)"easy";
        case 1:
            return (std::string)"medium";
        case 2:
            return (std::string)"hard";
        case 3:
            return (std::string)"BOSS";
        default:
            break;
    }
}