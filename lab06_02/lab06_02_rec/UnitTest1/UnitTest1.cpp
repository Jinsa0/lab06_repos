#include "pch.h"
#include "CppUnitTest.h"
#include "../lab06_02_rec/lab06_02_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:
        // Перевіряє пошук індексів мінімального та максимального елементів.
        TEST_METHOD(TestFindMinMaxIndexes)
        {
            const int size = 5;
            int a[size] = { 7, -3, 14, 2, -8 };

            int expectedMinIndex = 4; // елемент -8
            int expectedMaxIndex = 2; // елемент 14

            int actualMinIndex = FindMinIndex(a, size, 1, 0);
            int actualMaxIndex = FindMaxIndex(a, size, 1, 0);

            Assert::AreEqual(expectedMinIndex, actualMinIndex);
            Assert::AreEqual(expectedMaxIndex, actualMaxIndex);
        }

        // Перевіряє випадок, коли мінімум і максимум на краях масиву.
        TEST_METHOD(TestMinMaxAtEdges)
        {
            const int size = 5;
            int a[size] = { -50, 10, 0, 25, 50 };

            Assert::AreEqual(0, FindMinIndex(a, size, 1, 0));
            Assert::AreEqual(4, FindMaxIndex(a, size, 1, 0));
        }

        // Перевіряє, що за однакових значень повертається індекс першого входження.
        TEST_METHOD(TestRepeatedMinMax)
        {
            const int size = 6;
            int a[size] = { 10, -5, 20, -5, 20, 3 };

            Assert::AreEqual(1, FindMinIndex(a, size, 1, 0));
            Assert::AreEqual(2, FindMaxIndex(a, size, 1, 0));
        }

        // Перевіряє коректну роботу рекурсії для масиву з одного елемента.
        TEST_METHOD(TestSingleElement)
        {
            const int size = 1;
            int a[size] = { -7 };

            Assert::AreEqual(0, FindMinIndex(a, size, 1, 0));
            Assert::AreEqual(0, FindMaxIndex(a, size, 1, 0));
        }
    };
}