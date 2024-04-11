// Array.h
#pragma once
#include <iostream>

class Array {
protected:
    static const int MAX_SIZE = 100;
    unsigned char digits[MAX_SIZE];
    int size;
    void rangeCheck(int index) const;
public:
    Array();
    Array(const unsigned char arr[], int size);
    virtual ~Array();
    Array(const Array& other);
    Array& operator=(const Array& other);

    unsigned char& operator[](int index);
    const unsigned char& operator[](int index) const;

    operator std::string() const;

    int getSize() const;
    void setSize(int newSize);
};