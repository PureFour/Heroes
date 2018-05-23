#include <iostream>
#include <vector>
#ifndef HEROES_ITEM_H
#define HEROES_ITEM_H

class Item
{
    std::string name;
    std::string type;
    unsigned int buyValue;
    unsigned int sellValue;
    unsigned int index;
public:
    Item(std::string name = "Unknown", std::string type = "Unknown", unsigned int buyValue = 0, unsigned int sellValue = 0);
    virtual ~Item();
    //GetFunctions
    const std::string &getName() const;
    const std::string &getType() const;
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
