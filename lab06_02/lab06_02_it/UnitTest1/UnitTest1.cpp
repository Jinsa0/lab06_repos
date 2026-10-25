#include "pch.h"
#include "CppUnitTest.h"
#include "../lab06_02_it/lab06_02_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:
        // Перевіряє пошук індексів мінімального та максимального елементів у звичайному масиві.
        TEST_METHOD(TestFindMinMaxIndexes)
        {
            const int size = 5;
            int a[size] = { 7, -3, 14, 2, -8 };

            int expectedMinIndex = 4; // елемент -8
            int expectedMaxIndex = 2; // елемент 14

            int actualMinIndex = FindMinIndex(a, size);
            int actualMaxIndex = FindMaxIndex(a, size);

            Assert::AreEqual(expectedMinIndex, actualMinIndex);
            Assert::AreEqual(expectedMaxIndex, actualMaxIndex);
        }

        // Перевіряє, що за наявності дублікатів знаходиться саме перше входження.
        TEST_METHOD(TestFindMinMaxIndexesDuplicates)
        {
            const int size = 5;
            int a[size] = { 5, 9, 2, 9, 2 };

            int expectedMinIndex = 2; // перша 2 на позиції 2
            int expectedMaxIndex = 1; // перша 9 на позиції 1

            int actualMinIndex = FindMinIndex(a, size);
            int actualMaxIndex = FindMaxIndex(a, size);

            Assert::AreEqual(expectedMinIndex, actualMinIndex);
            Assert::AreEqual(expectedMaxIndex, actualMaxIndex);
        }

        // Перевіряє роботу функцій для масиву, що складається лише з одного елемента.
        TEST_METHOD(TestFindMinMaxIndexesSingleElement)
        {
            const int size = 1;
            int a[size] = { -7 };

            int expectedMinIndex = 0;
            int expectedMaxIndex = 0;

            int actualMinIndex = FindMinIndex(a, size);
            int actualMaxIndex = FindMaxIndex(a, size);

            Assert::AreEqual(expectedMinIndex, actualMinIndex);
            Assert::AreEqual(expectedMaxIndex, actualMaxIndex);
        }

        // Перевіряє випадок, коли мінімум і максимум знаходяться на краях масиву.
        TEST_METHOD(TestFindMinMaxIndexesEdges)
        {
            const int size = 4;
            int a[size] = { -100, 0, 50, 100 };

            Assert::AreEqual(0, FindMinIndex(a, size));
            Assert::AreEqual(3, FindMaxIndex(a, size));
        }
    };
}