#include <iostream>
#include "constants.h"

double calculateHeight(int seconds, double initialHeight)
{
    return initialHeight - (constants::gravity * seconds * seconds) / 2;
}

void printHeight(int seconds, double height)
{
    std::cout << "At " << seconds << " seconds, the ball is ";
    if (height <= 0)
        std::cout << "on the ground.\n";
    else
        std::cout << "at height: " << height << " meters\n";
}

int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double height;
    std::cin >> height;

    printHeight(0, calculateHeight(0, height));
    printHeight(1, calculateHeight(1, height));
    printHeight(2, calculateHeight(2, height));
    printHeight(3, calculateHeight(3, height));
    printHeight(4, calculateHeight(4, height));
    printHeight(5, calculateHeight(5, height));
    return 0;
}
