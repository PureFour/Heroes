#include "../include/Hero.h"
#include "../include/Archer.h"
#include "../include/Warrior.h"
#include "../include/Mage.h"
#include <gtest/gtest.h>

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(Mage, Default_Constructor)
{
    Mage Harry;
    EXPECT_EQ(Harry.getAD(), 2);
}
