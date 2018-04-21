cmake_minimum_required(VERSION 3.9)
project(Heroes)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        Heroes main.cpp
        src/Hero.cpp include/Hero.h
        src/Warrior.cpp include/Warrior.h
        src/Archer.cpp include/Archer.h
        src/Mage.cpp include/Mage.h)
add_executable(
        Test tests/test.cpp
        src/Hero.cpp include/Hero.h
        src/Warrior.cpp include/Warrior.h
        src/Archer.cpp include/Archer.h
        src/Mage.cpp include/Mage.h)
