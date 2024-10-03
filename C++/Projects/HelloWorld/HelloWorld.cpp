#include <iostream>

int main() {
  int prints = 0;
  
  while (prints < 10)
  {
    prints++;
    std::cout << "Hello, World!" << std::endl;
  }

  std::cin.ignore();
  std::cin.get(); 
}