#include <iostream>

int doubleNumber(int orig)
{
    return 2 * orig;
}

int main()
{
    std::cout << "Enter a number: ";
    int x;
    std::cin >> x;
    std::cout << "Two times " << x << " is " << doubleNumber(x) << std::endl;
    return 0;
}
