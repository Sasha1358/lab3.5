// main.cpp
#include <iostream>
#include "Octal.h"
#include<Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Creating Octal objects
    Octal octal1, octal2;

    // Entering values from the keyboard
    std::cout << "Введіть перше вісімкове число: ";
    std::cin >> octal1;

    std::cout << "Введіть друге вісімкове число: ";
    std::cin >> octal2;

    // Outputting the entered values
    std::cout << "Перше вісімкове число: " << octal1 << std::endl;
    std::cout << "Друге вісімкове число: " << octal2 << std::endl;

    // Performing arithmetic operations
    Octal sum = octal1 + octal2;
    Octal difference = octal1 - octal2;
    Octal product = octal1 * octal2;
    Octal quotient = octal1 / octal2;

    // Outputting the results of arithmetic operations
    std::cout << "Сума: " << sum << std::endl;
    std::cout << "Різниця: " << difference << std::endl;
    std::cout << "Добуток: " << static_cast<std::string>(product) << std::endl; // Використовуємо приведення до std::string для виводу
    std::cout << "Частка: " << quotient << std::endl;

    // Comparing numbers
    if (octal1 == octal2) {
        std::cout << "Перше вісімкове число дорівнює другому вісімковому числу." << std::endl;
    }
    else {
        std::cout << "Перше вісімкове число не дорівнює другому вісімковому числу." << std::endl;
    }

    if (octal1 < octal2) {
        std::cout << "Перше вісімкове число менше другого вісімкового числа." << std::endl;
    }
    else if (octal1 > octal2) {
        std::cout << "Перше вісімкове число більше другого вісімкового числа." << std::endl;
    }

    return 0;
}
