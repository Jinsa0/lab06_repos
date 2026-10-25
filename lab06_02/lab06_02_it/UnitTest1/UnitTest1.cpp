#include "pch.h"
#include "CppUnitTest.h"
#include "../lab06_02_it/lab06_02_it.cpp"

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

            int minIndex = -1;
            int maxIndex = -1;

            FindMinMaxIndexes(a, size, &minIndex, &maxIndex);

            Assert::AreEqual(4, minIndex);
            Assert::AreEqual(2, maxIndex);
        }

        // Перевіряє, що за однакових значень знаходиться перше входження.
        TEST_METHOD(TestFindMinMaxIndexesDuplicates)
        {
            const int size = 5;
            int a[size] = { 5, 9, 2, 9, 2 };

            int minIndex = -1;
            int maxIndex = -1;

            FindMinMaxIndexes(a, size, &minIndex, &maxIndex);

            Assert::AreEqual(2, minIndex);
            Assert::AreEqual(1, maxIndex);
        }

        // Перевіряє роботу функції з одним елементом.
        TEST_METHOD(TestFindMinMaxIndexesSingleElement)
        {
            const int size = 1;
            int a[size] = { -7 };

            int minIndex = -1;
            int maxIndex = -1;

            FindMinMaxIndexes(a, size, &minIndex, &maxIndex);

            Assert::AreEqual(0, minIndex);
            Assert::AreEqual(0, maxIndex);
        }
    };
}