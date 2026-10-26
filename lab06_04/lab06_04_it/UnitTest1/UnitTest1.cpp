#include "pch.h"
#include "CppUnitTest.h"
#include "../lab06_04_it/lab06_04_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64it
{
	TEST_CLASS(UnitTest64it)
	{
	public:

		// Тест 1: Перевірка пошуку НОМЕРА (index + 1) максимального за модулем елемента
		TEST_METHOD(Test_AbsMaxIndex)
		{
			const int size = 5;
			double a[size] = { -2.5, 3.1, -15.8, 10.2, -4.0 };

			// Максимальний за модулем елемент: -15.8
			// Його індекс index = 2
			// Його НОМЕР = index + 1 = 3
			int expectedNumber = 3;
			int actualNumber = AbsMaxIndex(a, size);

			Assert::AreEqual(expectedNumber, actualNumber);
		}

		// Тест 2: Обчислення суми елементів після першого додатного елемента
		TEST_METHOD(Test_SumAfterFirstPositive)
		{
			const int size = 5;
			double a[size] = { -5.0, 2.0, -3.0, 4.5, 1.5 };

			// Перший додатний елемент: 2.0 (індекс 1)
			// Елементи після нього: -3.0, 4.5, 1.5
			// Сума = -3.0 + 4.5 + 1.5 = 3.0
			double expectedSum = 3.0;
			double actualSum = SumAfterFirstPositive(a, size);

			Assert::AreEqual(expectedSum, actualSum, 0.0001);
		}

		// Тест 3: Обчислення суми, якщо додатних елементів немає (має повернути 0.0)
		TEST_METHOD(Test_SumAfterFirstPositive_NoPositive)
		{
			const int size = 4;
			double a[size] = { -5.0, -2.0, -3.0, -4.5 };

			double expectedSum = 0.0;
			double actualSum = SumAfterFirstPositive(a, size);

			Assert::AreEqual(expectedSum, actualSum, 0.0001);
		}

		// Тест 4: Перетворення масиву за цілою частиною в інтервалі [a, b]
		TEST_METHOD(Test_TransformArray)
		{
			const int size = 5;
			double a[size] = { 2.4, 8.9, 4.1, 12.3, 5.7 };
			int a_val = 3;
			int b_val = 6;

			// Цілі частини: 2, 8, 4, 12, 5
			// Попадають в інтервал [3, 6]: 4.1 (ціла 4), 5.7 (ціла 5)
			// Не попадають: 2.4 (ціла 2), 8.9 (ціла 8), 12.3 (ціла 12)
			// Очікуваний результат з збереженням відносного порядку:
			// { 4.1, 5.7, 2.4, 8.9, 12.3 }
			double expected[size] = { 4.1, 5.7, 2.4, 8.9, 12.3 };

			TransformArray(a, size, a_val, b_val);

			for (int i = 0; i < size; i++)
			{
				Assert::AreEqual(expected[i], a[i], 0.0001);
			}
		}
	};
}