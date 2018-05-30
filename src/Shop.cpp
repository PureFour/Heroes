#include "../include/Shop.h"

Shop::Shop() {this->shop = {};};
Shop::~Shop() = default;

void Shop::Initialize()
{
    Item sword("sword", "melee weapon", 12, 5);
    Item shield("shield", "armor", 20, 10);
    Item cloak;
}