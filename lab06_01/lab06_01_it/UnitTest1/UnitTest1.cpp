#include "pch.h"
#include "CppUnitTest.h"
#include "../lab06_01_it/lab06_01_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        // Перевіряє підрахунок потрібних елементів.
        TEST_METHOD(TestCount)
        {
            const int size = 5;
            int c[size] = { 5, 10, 15, 20, 25 };

            int expectedCount = 4;
            int actualCount = Count(c, size);

            Assert::AreEqual(expectedCount, actualCount);
        }

        // Перевіряє обчислення суми потрібних елементів.
        TEST_METHOD(TestSum)
        {
            const int size = 5;
            int c[size] = { 5, 10, 15, 20, 25 };

            int expectedSum = 70;
            int actualSum = Sum(c, size);

            Assert::AreEqual(expectedSum, actualSum);
        }

        // Перевіряє заміну потрібних елементів нулями.
        TEST_METHOD(TestModify)
        {
            const int size = 5;
            int c[size] = { 5, 10, 15, 20, 25 };

            int expected[size] = { 5, 0, 0, 0, 0 };

            Modify(c, size);

            for (int i = 0; i < size; i++)
                Assert::AreEqual(expected[i], c[i]);
        }
    };
}