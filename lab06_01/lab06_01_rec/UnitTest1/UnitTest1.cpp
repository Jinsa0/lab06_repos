#include "pch.h"
#include "CppUnitTest.h"
#include "../lab06_01_rec/lab06_01_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        // Перевіряє підрахунок потрібних елементів.
        TEST_METHOD(TestCountRecursive)
        {
            const int size = 10;
            int c[size] = { 5, 10, 15, 20, 25, 30, 35, 40, 9, 50 };

            int expectedCount = 8;
            int actualCount = Count(c, 0, size);

            Assert::AreEqual(expectedCount, actualCount);
        }

        // Перевіряє обчислення суми потрібних елементів.
        TEST_METHOD(TestSumRecursive)
        {
            const int size = 10;
            int c[size] = { 5, 10, 15, 20, 25, 30, 35, 40, 9, 50 };

            int expectedSum = 225;
            int actualSum = Sum(c, 0, size);

            Assert::AreEqual(expectedSum, actualSum);
        }

        // Перевіряє заміну потрібних елементів нулями.
        TEST_METHOD(TestModifyRecursive)
        {
            const int size = 10;
            int c[size] = { 5, 10, 15, 20, 25, 30, 35, 40, 9, 50 };

            int expected[size] = { 5, 0, 0, 0, 0, 0, 0, 0, 9, 0 };

            Modify(c, 0, size);

            for (int i = 0; i < size; i++)
                Assert::AreEqual(expected[i], c[i]);
        }
    };
}