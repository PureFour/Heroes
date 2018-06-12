#include <iostream>
#include <vector>
#include <iomanip>
#ifndef HEROES_ITEM_H
#define HEROES_ITEM_H

class Item
{
    std::string name;
    std::string type;
    unsigned int buyValue;
    unsigned int sellValue;
    unsigned int index;
    //stats
    unsigned int _ad;
    unsigned int _ap;
    unsigned int _def;
    unsigned int _hp;
    unsigned int _mana;
    unsigned int _luck;
    unsigned int _lvl;
    //
public:
    explicit Item(std::string name = "Unknown", std::string type = "Unknown", unsigned int buyValue = 0, unsigned int stats = 0);
    virtual ~Item();
    //GetFunctions
    const std::string &getName() const;
    const std::string &getType() const;
    const unsigned int &getBuyValue() const;
    const unsigned int &getSellValue() const;
    const unsigned int &getIndex() const;

    const unsigned int &getad() const;
    const unsigned int &getap() const;
    const unsigned int &getdef() const;
    const unsigned int &gethp() const;
    const unsigned int &getmana() const;
    const unsigned int &getluck() const;
    const unsigned int &getlvl() const;
    //
    //SetFunctions
    void setIndex(unsigned int);
    //
    const void showItem()const ;
    Item* operator ++();
};

#endif //HEROES_ITEM_H
