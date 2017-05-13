#include <iostream>

int main()
{
  std::cout << "Enter a number: ";
  int x;
  std::cin >> x;
  std::cout << "You entered " << x << std::endl;
  std::cin.clear();
  std::cin.ignore(32767, '\n');
  std::cin.get();
  return 0;
}
