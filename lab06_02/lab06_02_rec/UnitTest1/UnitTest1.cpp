
#include "pch.h"
#include "CppUnitTest.h"
#include "../lab06_02_rec/lab06_02_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        // Перевірка індексів мінімального та максимального елементів.
        TEST_METHOD(TestFindMinMaxIndexes)
        {
            const int size = 5;
            int a[size] = { 7, -3, 14, 2, -8 };

            int minIndex = 0;
            int maxIndex = 0;

            FindMinMaxIndexes(a, 0, size, &minIndex, &maxIndex);

            Assert::AreEqual(4, minIndex);
            Assert::AreEqual(2, maxIndex);
        }

        // Перевірка, коли мінімум і максимум на краях масиву.
        TEST_METHOD(TestMinMaxAtEdges)
        {
            const int size = 5;
            int a[size] = { -50, 10, 0, 25, 50 };

            int minIndex = 0;
            int maxIndex = 0;

            FindMinMaxIndexes(a, 0, size, &minIndex, &maxIndex);

            Assert::AreEqual(0, minIndex);
            Assert::AreEqual(4, maxIndex);
        }

        // Перевірка однакових мінімальних і максимальних значень.
        TEST_METHOD(TestRepeatedMinMax)
        {
            const int size = 6;
            int a[size] = { 10, -5, 20, -5, 20, 3 };

            int minIndex = 0;
            int maxIndex = 0;

            FindMinMaxIndexes(a, 0, size, &minIndex, &maxIndex);

            // Має повертатися індекс першого входження.
            Assert::AreEqual(1, minIndex);
            Assert::AreEqual(2, maxIndex);
        }
    };
}
