#include "pch.h"
#include "CppUnitTest.h"
#include "../lab06_03_it/lab06_03_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:
        // Перевіряє підрахунок непарних елементів звичайною функцією для масиву int
        TEST_METHOD(TestCountOrdinary)
        {
            const int size = 6;
            int a[size] = { 1, 2, 3, 4, 5, 6 };
            int expected = 3; // непарні: 1, 3, 5
            int actual = Count(a, size);
            Assert::AreEqual(expected, actual);
        }

        // Перевіряє роботу шаблону функції для типу int (включаючи від'ємні значення)
        TEST_METHOD(TestCountTemplateInt)
        {
            const int size = 5;
            int a[size] = { -3, -2, 0, 7, 11 };
            int expected = 3; // непарні: -3, 7, 11
            int actual = Count<int>(a, size);
            Assert::AreEqual(expected, actual);
        }

        // Перевіряє випадок, коли непарних елементів у масиві немає
        TEST_METHOD(TestCountNoOdds)
        {
            const int size = 4;
            int a[size] = { 2, 4, 6, 8 };
            Assert::AreEqual(0, Count(a, size));
            Assert::AreEqual(0, Count<int>(a, size));
        }

        // Перевіряє роботу шаблону для іншого цілочисельного типу (long)
        TEST_METHOD(TestCountTemplateLong)
        {
            const int size = 5;
            long a[size] = { 13L, 22L, 35L, 44L, 57L };
            int expected = 3; // непарні: 13, 35, 57
            int actual = Count<long>(a, size);
            Assert::AreEqual(expected, actual);
        }
    };
}
