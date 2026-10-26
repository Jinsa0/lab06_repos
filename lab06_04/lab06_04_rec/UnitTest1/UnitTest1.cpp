
#include "pch.h"
#include "CppUnitTest.h"
#include "../lab06_04_rec/lab06_04_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64rec
{
    TEST_CLASS(UnitTest64rec)
    {
    public:

        // Тест 1: Максимальний за модулем елемент на початку
        TEST_METHOD(Test_AbsMaxIndex_First)
        {
            const int size = 4;
            double a[size] = { -20.5, 3.0, 8.2, -4.1 };

            int expectedNumber = 1;
            int actualNumber = AbsMaxIndex(a, 0, size, 0);

            Assert::AreEqual(expectedNumber, actualNumber);
        }

        // Тест 2: Максимальний за модулем елемент у кінці
        TEST_METHOD(Test_AbsMaxIndex_Last)
        {
            const int size = 5;
            double a[size] = { 2.0, -4.5, 7.1, 3.2, -18.6 };

            int expectedNumber = 5;
            int actualNumber = AbsMaxIndex(a, 0, size, 0);

            Assert::AreEqual(expectedNumber, actualNumber);
        }

        // Тест 3: Усі елементи від'ємні
        TEST_METHOD(Test_AbsMaxIndex_Negative)
        {
            const int size = 4;
            double a[size] = { -2.0, -9.5, -3.1, -6.0 };

            int expectedNumber = 2;
            int actualNumber = AbsMaxIndex(a, 0, size, 0);

            Assert::AreEqual(expectedNumber, actualNumber);
        }

        // Тест 4: Перший додатний елемент розташований на початку
        TEST_METHOD(Test_FindFirstPositive_First)
        {
            const int size = 4;
            double a[size] = { 2.5, -3.0, 7.0, 1.0 };

            int expectedIndex = 0;
            int actualIndex = FindFirstPositive(a, 0, size);

            Assert::AreEqual(expectedIndex, actualIndex);
        }

        // Тест 5: Перший додатний елемент розташований у кінці
        TEST_METHOD(Test_FindFirstPositive_Last)
        {
            const int size = 4;
            double a[size] = { -2.0, -5.0, -1.5, 4.2 };

            int expectedIndex = 3;
            int actualIndex = FindFirstPositive(a, 0, size);

            Assert::AreEqual(expectedIndex, actualIndex);
        }

        // Тест 6: Сума після першого додатного елемента
        TEST_METHOD(Test_SumAfterFirstPositive_NegativeSum)
        {
            const int size = 5;
            double a[size] = { -1.0, 3.0, -5.0, -2.0, 1.0 };

            // Сума після першого додатного: -5 + (-2) + 1 = -6
            double expectedSum = -6.0;
            double actualSum = SumAfterFirstPositive(a, 0, size);

            Assert::AreEqual(expectedSum, actualSum, 0.0001);
        }

        // Тест 7: Сума після першого додатного елемента дорівнює нулю
        TEST_METHOD(Test_SumAfterFirstPositive_ZeroSum)
        {
            const int size = 4;
            double a[size] = { -2.0, 5.0, -3.0, 3.0 };

            // Сума після першого додатного: -3 + 3 = 0
            double expectedSum = 0.0;
            double actualSum = SumAfterFirstPositive(a, 0, size);

            Assert::AreEqual(expectedSum, actualSum, 0.0001);
        }

        // Тест 8: Перетворення масиву — перевірка порядку елементів
        TEST_METHOD(Test_TransformArray_Order)
        {
            const int size = 6;
            double a[size] = { 9.2, 3.5, 7.8, 2.4, 5.6, 1.3 };

            int a_val = 3;
            int b_val = 6;

            // Цілі частини: 9, 3, 7, 2, 5, 1
            // Спочатку елементи з цілою частиною в [3, 6],
            // потім решта, зі збереженням порядку.
            double expected[size] = { 3.5, 5.6, 9.2, 7.8, 2.4, 1.3 };

            TransformArray(a, 0, size, a_val, b_val);

            for (int i = 0; i < size; i++)
            {
                Assert::AreEqual(expected[i], a[i], 0.0001);
            }
        }
    };
}
