#include <iostream>

int main()
{
  std::cout << "Hello world!" << std::endl;
  std::cin.clear();
  std::cin.ignore(32767, '\n');
  std::cin.get();
  return 0;
}
