#include <heros.hpp>
#include <gtest/gtest.h>

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(Warrior, Constructor)
{
    Warrior daniel;

    Warrior daniel2(5000, 10, 10);

    EXPECT_EQ(daniel.getHp(), 150);
    EXPECT_EQ(daniel.getAttackPoints(), 3);
    EXPECT_EQ(daniel.getDeffencePoints(), 3);

    EXPECT_EQ(daniel2.getHp(), 5000);
    EXPECT_EQ(daniel2.getAttackPoints(), 10);
    EXPECT_EQ(daniel2.getDeffencePoints(), 10);
}