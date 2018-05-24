#include "../include/Functions.h"

void ClearScreen()
{
    std::cout<< std::string(100, '\n');
}

unsigned int myInput(int options)
{
    unsigned int input;
    std::cin >> input;
    while(!std::cin.good() || input > options - 1 )
    {
        std::cout << "Try again!" << std::endl;
        std::cin.clear();
        std::cin.ignore('1', '\n');
        std::cout << "My Choice:_\b";
        std::cin >> input;
    }
    return input;
}