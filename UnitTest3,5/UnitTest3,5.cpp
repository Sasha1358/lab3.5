#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3.5/Octal.h"
#include "../lab3.5/Octal.cpp"
#include "../lab3.5/Array.h"
#include "../lab3.5/Array.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest35
{
    TEST_CLASS(UnitTest35)
    {
    public:

        TEST_METHOD(TestAddition)
        {
            // Arrange
            unsigned char arr1[] = { 1, 2, 3 };
            unsigned char arr2[] = { 4, 5, 6 };
            Octal octal1(arr1, 3);
            Octal octal2(arr2, 3);

            // Act
            Octal sum = octal1 + octal2;

            // Assert
            Assert::AreEqual(std::string("5175"), static_cast<std::string>(sum), L"Sum is not correct.");
        }
    };
}
