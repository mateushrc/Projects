#include <iostream>

int main() {
    int number;
    std::cout << "Digite um numero: ";
    std::cin >> number;
    std::cout << "Voce Digitou: " << number;
    std::cin.ignore();
    std::cin.get(); 
}