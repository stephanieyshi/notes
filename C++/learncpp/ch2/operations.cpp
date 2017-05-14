#include <iostream>

double getDouble()
{
    std::cout << "Enter a double value: ";
    double x;
    std::cin >> x;
    return x;
}

void calculate(double x, double y, char op)
{
    if (op == '+')
        std::cout << x << " + " << y << " is " << (x + y) << "\n";
    else if (op == '-')
        std::cout << x << " - " << y << " is " << (x - y) << "\n";
    else if (op == '*')
        std::cout << x << " * " << y << " is " << (x * y) << "\n";
    else if (op == '/')
        std::cout << x << " / " << y << " is " << (x / y) << "\n";
}

int main()
{
    double x = getDouble();
    double y = getDouble();

    std::cout << "Enter one of the following: +, -, *, or /: ";
    char op;
    std::cin >> op;

    calculate(x, y, op);
    return 0;
}
