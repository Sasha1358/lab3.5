#pragma once
#include "Array.h"
#include <iostream>

class Octal : public Array {
public:
    Octal();
    Octal(const unsigned char arr[], int size);
    ~Octal();
    Octal(const Octal& other);
    Octal(int value);

    Octal operator+(const Octal& other) const;
    Octal operator-(const Octal& other) const;
    Octal operator*(const Octal& other) const;
    Octal operator/(const Octal& other) const;

    bool operator==(const Octal& other) const;
    bool operator!=(const Octal& other) const;
    bool operator<(const Octal& other) const;
    bool operator>(const Octal& other) const;
    bool operator<=(const Octal& other) const;
    bool operator>=(const Octal& other) const;

    operator std::string() const;

    friend std::ostream& operator<<(std::ostream& output, const Octal& oct);
    friend std::istream& operator>>(std::istream& input, Octal& oct);
};
