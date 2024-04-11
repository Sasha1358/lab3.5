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
    std::cout << "������ ����� ������� �����: ";
    std::cin >> octal1;

    std::cout << "������ ����� ������� �����: ";
    std::cin >> octal2;

    // Outputting the entered values
    std::cout << "����� ������� �����: " << octal1 << std::endl;
    std::cout << "����� ������� �����: " << octal2 << std::endl;

    // Performing arithmetic operations
    Octal sum = octal1 + octal2;
    Octal difference = octal1 - octal2;
    Octal product = octal1 * octal2;
    Octal quotient = octal1 / octal2;

    // Outputting the results of arithmetic operations
    std::cout << "����: " << sum << std::endl;
    std::cout << "г�����: " << difference << std::endl;
    std::cout << "�������: " << static_cast<std::string>(product) << std::endl; // ������������� ���������� �� std::string ��� ������
    std::cout << "������: " << quotient << std::endl;

    // Comparing numbers
    if (octal1 == octal2) {
        std::cout << "����� ������� ����� ������� ������� ��������� �����." << std::endl;
    }
    else {
        std::cout << "����� ������� ����� �� ������� ������� ��������� �����." << std::endl;
    }

    if (octal1 < octal2) {
        std::cout << "����� ������� ����� ����� ������� ��������� �����." << std::endl;
    }
    else if (octal1 > octal2) {
        std::cout << "����� ������� ����� ����� ������� ��������� �����." << std::endl;
    }

    return 0;
}
