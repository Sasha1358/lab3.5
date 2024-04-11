#include "Octal.h"
#include <algorithm>
#include <iostream>
#include <sstream>

Octal::Octal() : Array() {}
Octal::Octal(const unsigned char arr[], int size) : Array(arr, size) {}
Octal::~Octal() {}
Octal::Octal(const Octal& other) : Array(other) {}
Octal::Octal(int value) : Array() {
    if (value < 0) {
        std::cerr << "Error: Octal value cannot be negative." << std::endl;
        exit(EXIT_FAILURE);
    }
    if (value == 0) {
        size = 1;
        digits[0] = 0;
    }
    else {
        int i = 0;
        while (value != 0) {
            digits[i++] = value % 8;
            value /= 8;
        }
        size = i;
    }
}

Octal Octal::operator+(const Octal& other) const {
    int maxSize = std::max(size, other.size) + 1; // +1 для можливого переносу
    Octal result;
    result.size = maxSize;

    int carry = 0;
    for (int i = 0; i < maxSize; ++i) {
        int sum = digits[i] + (i < other.size ? other.digits[i] : 0) + carry;
        result.digits[i] = sum % 8;
        carry = sum / 8;
    }

    // Видалення надлишкових нулів
    while (maxSize > 0 && result.digits[maxSize - 1] == 0) {
        --maxSize;
    }
    result.size = maxSize;

    return result;
}
Octal Octal::operator-(const Octal& other) const {
    int maxSize = std::max(size, other.size);
    Octal result;
    result.size = maxSize;

    int borrow = 0;
    for (int i = 0; i < maxSize; ++i) {
        int diff = digits[i] - (i < other.size ? other.digits[i] : 0) - borrow;
        if (diff < 0) {
            diff += 8;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        result.digits[i] = diff;
    }

    return result;
}
Octal Octal::operator*(const Octal& other) const {
    int maxSize = size + other.size;
    Octal result;
    result.size = maxSize;

    // Ініціалізуємо всі цифри результату нулями
    for (int i = 0; i < maxSize; ++i) {
        result.digits[i] = 0;
    }

    // Перемноження інших розрядів
    for (int i = 0; i < size; ++i) {
        int carry = 0;
        for (int j = 0; j < other.size; ++j) {
            int product = result.digits[i + j] + digits[i] * other.digits[j] + carry;
            result.digits[i + j] = product % 8;
            carry = product / 8;
        }
        result.digits[i + other.size] = carry; // Збереження залишку в наступному розряді
    }

    return result;
}
Octal Octal::operator/(const Octal& other) const {
    // Перевірка на ділення на нуль
    if (other == Octal()) {
        std::cerr << "Division by zero error" << std::endl;
        exit(EXIT_FAILURE);
    }

    Octal quotient(size); // Квотієнт
    Octal dividend(*this); // Дивідент

    // Алгоритм довгого ділення
    for (int i = size - 1; i >= 0; --i) {
        int digit = 0;

        // Ділення поточного розряду дивідента на дільник, якщо можливо
        while (dividend >= other) {
            dividend = dividend - other;
            ++digit;
        }

        // Запис результату ділення у масив квотієнту
        quotient.digits[i] = digit;

        // Перенесення "залишку" на наступний розряд
        dividend = dividend * 8 + digits[i];
    }

    // Видалення надлишкових нулів
    while (quotient.size > 0 && quotient.digits[quotient.size - 1] == 0) {
        --quotient.size;
    }

    return quotient;
}

bool Octal::operator==(const Octal& other) const {
    // Comparing sizes
    if (size != other.size) {
        return false;
    }

    // Comparing each digit
    for (int i = 0; i < size; ++i) {
        if (digits[i] != other.digits[i]) {
            return false;
        }
    }

    return true;
}
bool Octal::operator!=(const Octal& other) const {
    // Using the already defined ==
    return !(*this == other);
}
bool Octal::operator<(const Octal& other) const {
    // Comparing sizes
    if (size < other.size) {
        return true;
    }
    else if (size > other.size) {
        return false;
    }

    // Comparing each digit starting from the most significant
    for (int i = size - 1; i >= 0; --i) {
        if (digits[i] < other.digits[i]) {
            return true;
        }
        else if (digits[i] > other.digits[i]) {
            return false;
        }
    }

    return false; // Equal numbers
}
bool Octal::operator>(const Octal& other) const {
    // Using the already defined < and !=
    return !(*this < other) && !(*this == other);
}
bool Octal::operator<=(const Octal& other) const {
    // Using the already defined < and ==
    return *this < other || *this == other;
}
bool Octal::operator>=(const Octal& other) const {
    // Using the already defined > and ==
    return *this > other || *this == other;
}

Octal::operator std::string() const {
    // Convert Octal to string
    std::ostringstream oss;
    for (int i = size - 1; i >= 0; --i) {
        oss << static_cast<int>(digits[i]);
    }
    return oss.str();
}

std::ostream& operator<<(std::ostream& output, const Octal& oct) {
    // Output Octal object
    for (int i = oct.size - 1; i >= 0; --i) {
        output << static_cast<int>(oct.digits[i]);
    }
    return output;
}
std::istream& operator>>(std::istream& input, Octal& oct) {
    // Input Octal object
    std::string inputStr;
    input >> inputStr;

    // Reverse the string since the least significant digits are stored at the beginning of the array
    std::reverse(inputStr.begin(), inputStr.end());

    // Check for valid input characters
    for (char ch : inputStr) {
        if (ch < '0' || ch > '7') {
            std::cerr << "Error: Invalid input. Please enter only octal digits (0-7)." << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    // Clear previous Octal data
    oct.size = 0;

    // Fill the array with data
    for (char ch : inputStr) {
        oct.digits[oct.size++] = ch - '0';
    }

    return input;
}
