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

        // Тест 3: Перший додатний елемент розташований у кінці
        TEST_METHOD(Test_FindFirstPositive_Last)
        {
            const int size = 4;
            double a[size] = { -2.0, -5.0, -1.5, 4.2 };

            int expectedIndex = 3;
            int actualIndex = FindFirstPositive(a, 0, size);

            Assert::AreEqual(expectedIndex, actualIndex);
        }

        // Тест 4: Сума після першого додатного — від'ємний результат
        TEST_METHOD(Test_SumAfterFirstPositive_NegativeSum)
        {
            const int size = 5;
            double a[size] = { -1.0, 3.0, -5.0, -2.0, 1.0 };

            // Перший додатний: 3.0 (індекс 1)
            // Сума після нього: -5 + (-2) + 1 = -6
            double expectedSum = -6.0;
            double actualSum = SumAfterFirstPositive(a, size);

            Assert::AreEqual(expectedSum, actualSum, 0.0001);
        }

        // Тест 5: Жодного додатного елемента — має повернути 0.0
        TEST_METHOD(Test_SumAfterFirstPositive_NoPositive)
        {
            const int size = 4;
            double a[size] = { -5.0, -2.0, -3.0, -4.5 };

            double expectedSum = 0.0;
            double actualSum = SumAfterFirstPositive(a, size);

            Assert::AreEqual(expectedSum, actualSum, 0.0001);
        }

        // Тест 6: Shift — перевірка коректності рекурсивного зсуву вправо
        TEST_METHOD(Test_Shift_Basic)
        {
            double a[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };

            // Shift(a, k=4, target=2): a[4]=a[3], a[3]=a[2]
            // Очікується: { 1.0, 2.0, 3.0, 3.0, 4.0 }
            Shift(a, 4, 2);

            double expected[5] = { 1.0, 2.0, 3.0, 3.0, 4.0 };
            for (int i = 0; i < 5; i++)
                Assert::AreEqual(expected[i], a[i], 0.0001);
        }

        // Тест 7: TransformArray — базовий порядок елементів
        TEST_METHOD(Test_TransformArray_Order)
        {
            const int size = 6;
            double a[size] = { 9.2, 3.5, 7.8, 2.4, 5.6, 1.3 };
            int a_val = 3;
            int b_val = 6;

            // Цілі частини: 9, 3, 7, 2, 5, 1
            // В [3,6]: 3.5, 5.6 — ідуть першими; решта після них
            double expected[size] = { 3.5, 5.6, 9.2, 7.8, 2.4, 1.3 };

            TransformArray(a, size, a_val, b_val, 0, 0);

            for (int i = 0; i < size; i++)
                Assert::AreEqual(expected[i], a[i], 0.0001);
        }

        // Тест 8: TransformArray — жоден елемент не потрапляє в інтервал
        TEST_METHOD(Test_TransformArray_NoMatch)
        {
            const int size = 4;
            double a[size] = { 8.1, 9.9, 7.2, 10.5 };
            int a_val = 1;
            int b_val = 5;

            // Жоден елемент не підходить — масив не змінюється
            double expected[size] = { 8.1, 9.9, 7.2, 10.5 };

            TransformArray(a, size, a_val, b_val, 0, 0);

            for (int i = 0; i < size; i++)
                Assert::AreEqual(expected[i], a[i], 0.0001);
        }
    };
}