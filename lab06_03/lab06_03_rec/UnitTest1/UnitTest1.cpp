#include "pch.h"
#include "CppUnitTest.h"
#include "../lab06_03_rec/lab06_03_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:
        // Перевіряє підрахунок непарних елементів звичайною рекурсивною функцією для int
        TEST_METHOD(TestCountOrdinaryRec)
        {
            const int size = 6;
            int a[size] = { 1, 2, 3, 4, 5, 6 };
            int expected = 3; // непарні: 1, 3, 5
            int actual = Count(a, 0, size);
            Assert::AreEqual(expected, actual);
        }

        // Перевіряє роботу рекурсивного шаблону функції для типу int
        TEST_METHOD(TestCountTemplateIntRec)
        {
            const int size = 5;
            int a[size] = { -3, -2, 0, 7, 11 };
            int expected = 3; // непарні: -3, 7, 11
            int actual = Count<int>(a, 0, size);
            Assert::AreEqual(expected, actual);
        }

        // Перевіряє випадок масиву, де немає непарних елементів
        TEST_METHOD(TestCountNoOddsRec)
        {
            const int size = 4;
            int a[size] = { 2, 4, 6, 8 };
            Assert::AreEqual(0, Count(a, 0, size));
            Assert::AreEqual(0, Count<int>(a, 0, size));
        }

        // Перевіряє рекурсивний шаблон на масиві іншого типу (long)
        TEST_METHOD(TestCountTemplateLongRec)
        {
            const int size = 5;
            long a[size] = { 13L, 22L, 35L, 44L, 57L };
            int expected = 3; // непарні: 13, 35, 57
            int actual = Count<long>(a, 0, size);
            Assert::AreEqual(expected, actual);
        }
    };
}
