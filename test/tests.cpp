#include "heros.h"
#include <gtest/gtest.h>
#include <vector>

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
TEST(Warrior, Constructor)
{
    std::vector<Hero *> Heroes;
    Heroes.push_back(new Warrior);
    Heroes.push_back(new Mage);
    Heroes.push_back(new Archer);
    for(auto p: Heroes) p->status();
}