#include "Game.h"
#ifndef HEROES_ITEM_H
#define HEROES_ITEM_H

class Item
{
    std::string name;
    unsigned int buyValue;
    unsigned int sellValue;
    unsigned int index;
public:
    Item();
    virtual ~Item();
    //GetFunctions
    const std::string &getName() const;
    const unsigned int &getBuyValue() const;
    const unsigned int &getSellValue() const;
    const unsigned int &getIndex() const;
    //
    //SetFunctions
    void setIndex(unsigned int);
    //
    void showItem();
};

#endif //HEROES_ITEM_H
