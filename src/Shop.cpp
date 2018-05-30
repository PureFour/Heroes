#include "../include/Shop.h"

Shop::Shop() {};
Shop::~Shop() = default;

void Shop::Initialize()
{
    Inventory shop;
    Armor armor;
    std::cout << "Shop has been initialized!" << std::endl;
    shop.showInv();
}