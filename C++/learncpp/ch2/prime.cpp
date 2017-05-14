#include <iostream>

bool isPrime(int x)
{
    if (x == 2)
        return true;
    else if (x == 3)
        return true;
    else if (x == 5)
        return true;
    else if (x == 7)
        return true;
    else
        return false;
}

int main()
{
    std::cout << "Enter a single digit integer: ";

    int x;
    std::cin >> x;

    if (isPrime(x))
        std::cout << "The digit is prime." << std::endl;
    else
        std::cout << "The digit is not prime." << std::endl;
    return 0;
}
