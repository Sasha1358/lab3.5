#include "Array.h"
#include <stdexcept>
#include <sstream>

Array::Array() : size(0) {
    for (int i = 0; i < MAX_SIZE; ++i) {
        digits[i] = 0;
    }
}

Array::Array(const unsigned char arr[], int size) {
    if (size > MAX_SIZE) {
        throw std::invalid_argument("Size exceeds maximum allowed size.");
    }
    for (int i = 0; i < size; ++i) {
        digits[i] = arr[i];
    }
    this->size = size;
}

Array::~Array() {}

Array::Array(const Array& other) : size(other.size) {
    for (int i = 0; i < size; ++i) {
        digits[i] = other.digits[i];
    }
}

Array& Array::operator=(const Array& other) {
    if (this == &other) {
        return *this;
    }
    size = other.size;
    for (int i = 0; i < size; ++i) {
        digits[i] = other.digits[i];
    }
    return *this;
}

unsigned char& Array::operator[](int index) {
    rangeCheck(index);
    return digits[index];
}

const unsigned char& Array::operator[](int index) const {
    rangeCheck(index);
    return digits[index];
}

int Array::getSize() const {
    return size;
}

void Array::setSize(int newSize) {
    if (newSize < 0 || newSize > MAX_SIZE) {
        throw std::invalid_argument("Invalid size. Size must be between 0 and MAX_SIZE.");
    }
    size = newSize;
}

Array::operator std::string() const {
    std::string result = "";
    for (int i = size - 1; i >= 0; --i) {
        result += std::to_string(digits[i]);
    }
    return result;
}

void Array::rangeCheck(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds.");
    }
}
