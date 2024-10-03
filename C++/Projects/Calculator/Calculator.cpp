#include <iostream>

int number1;
int number2;
int result;

void divisao()
{
  std::cout << "\nDigite o primeiro numero: ";
  std::cin >> number1;
  std::cout << "\nDigite o segundo numero: ";
  std::cin >> number2;

  int result {number1 / number2};
  std::cout << "\nResultado: " << result;
}

void multiplicacao()
{
  std::cout << "\nDigite o primeiro numero: ";
  std::cin >> number1;
  std::cout << "\nDigite o segundo numero: ";
  std::cin >> number2;

  int result {number1 * number2};
  std::cout << "\nResultado: " << result;
}

void subtracao()
{
  std::cout << "\nDigite o primeiro numero: ";
  std::cin >> number1;
  std::cout << "\nDigite o segundo numero: ";
  std::cin >> number2;

  int result {number1 - number2};
  std::cout << "\nResultado: " << result;
}

void soma()
{
  std::cout << "\nDigite o primeiro numero: ";
  std::cin >> number1;
  std::cout << "\nDigite o segundo numero: ";
  std::cin >> number2;

  int result {number1 + number2};
  std::cout << "\nResultado: " << result;
}

void menu()
{
  std::cout << "Bem Vindo a Calculadora!\n";
  std::cout << "Escolha o que voce quer:\n";
  std::cout << "1-Soma\n";
  std::cout << "2-Subtracao\n";
  std::cout << "3-Multiplicacao\n";
  std::cout << "4-Divisao\n";
  std::cout << "0-Exit\n";
  std::cout << "Digite Aqui: ";
  std::cin >> result;

  switch (result)
  {
    case 1: soma(); break;
    case 2: subtracao(); break;
    case 3: multiplicacao(); break;
    case 4: divisao(); break;
    default: break;
  }
}

int main()
{
  menu();
}