#include "pch.h"
#include "CppUnitTest.h"
#include "../lab06_01_it/lab06_01_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        // 1. Тестування функції Count (обчислення кількості)
        TEST_METHOD(TestCount)
        {
            const int size = 5;
            int a[size] = { 5, 10, 15, 20, 25 };

            int expectedCount = 4;
            int actualCount = Count(a, size);

            Assert::AreEqual(expectedCount, actualCount);
        }

        // 2. Тестування функції Sum (обчислення суми)
        TEST_METHOD(TestSum)
        {
            const int size = 5;
            int a[size] = { 5, 10, 15, 20, 25 };

            int expectedSum = 70; // 10 + 15 + 20 + 25
            int actualSum = Sum(a, size);

            Assert::AreEqual(expectedSum, actualSum);
        }

        // 3. Тестування функції Modify (заміна нулями)
        TEST_METHOD(TestModify)
        {
            const int size = 5;
            int a[size] = { 5, 10, 15, 20, 25 };

            Modify(a, size);

            // Перший елемент не підпадає під умову, тому залишається без змін
            Assert::AreEqual(5, a[0]);

            // Всі інші підпадають, тому мають стати нулями
            Assert::AreEqual(0, a[1]);
            Assert::AreEqual(0, a[2]);
            Assert::AreEqual(0, a[3]);
            Assert::AreEqual(0, a[4]);
        }
    };
}