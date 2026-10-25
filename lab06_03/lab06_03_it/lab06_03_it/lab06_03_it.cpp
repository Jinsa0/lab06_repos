// lab06_03_it.cpp
// Кіц Роман Романович
// Лабораторна робота № 6.3 іт
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів (ітераційний спосіб).
// Варіант 12

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Прототипи звичайних функцій (для роботи з масивом int)
void Create(int* a, const int size, const int Low, const int High);
void Print(const int* a, const int size);
int Count(const int* a, const int size);

// 2. Прототипи шаблонів функцій (для універсальної роботи з різними типами)
template <typename T>
void Create(T* a, const int size, const T Low, const T High);

template <typename T>
void Print(const T* a, const int size);

template <typename T>
int Count(const T* a, const int size);

// --- Реалізація звичайних функцій ---

// Заповнює масив випадковими числами (ітераційно)
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// Виводить елементи масиву в одному рядку (ітераційно)
void Print(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(5) << a[i];
    cout << endl << endl;
}

// Обчислює кількість непарних елементів масиву (ітераційно)
int Count(const int* a, const int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] % 2 != 0)
            count++;
    }
    return count;
}

// --- Реалізація шаблонів функцій ---

// Універсальне заповнення масиву випадковими числами
template <typename T>
void Create(T* a, const int size, const T Low, const T High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// Універсальне форматоване виведення елементів масиву
template <typename T>
void Print(const T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(5) << a[i];
    cout << endl << endl;
}

// Універсальний підрахунок кількості непарних елементів масиву
template <typename T>
int Count(const T* a, const int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] % 2 != 0)
            count++;
    }
    return count;
}

// Головна функція програми
int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];
    int Low = -20, High = 20;

    // 1. Формування та виведення масиву a (звичайні функції)
    Create(a, n, Low, High);
    cout << "Initial array a (int):" << endl;
    Print(a, n);

    // 2. Обчислення кількості непарних елементів звичайною та шаблонною функцією
    int countOrdinary = Count(a, n);
    int countTemplate = Count<int>(a, n);
    cout << "Count (ordinary function)   = " << countOrdinary << endl;
    cout << "Count<int> (template function) = " << countTemplate << endl << endl;

    // 3. Демонстрація роботи шаблону функцій для іншого типу (long)
    const int n2 = 8;
    long b[n2];
    long lowL = 1, highL = 50;
    Create<long>(b, n2, lowL, highL);
    cout << "Array b (long):" << endl;
    Print<long>(b, n2);
    cout << "Count<long> (template function) = " << Count<long>(b, n2) << endl;

    return 0;
}
