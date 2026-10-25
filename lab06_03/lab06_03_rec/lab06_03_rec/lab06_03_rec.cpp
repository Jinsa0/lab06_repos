// lab06_03_rec.cpp
// Кіц Роман Романович
// Лабораторна робота № 6.3 рек
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів (рекурсивний спосіб).
// Варіант 12

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Прототипи звичайних рекурсивних функцій (для роботи з масивом int)
void Create(int* a, int i, const int size, const int Low, const int High);
void Print(int* a, int i, const int size);
int Count(const int* a, int i, const int size);

// 2. Прототипи рекурсивних шаблонів функцій (для універсальної роботи з різними типами)
template <typename T>
void Create(T* a, int i, const int size, const T Low, const T High);

template <typename T>
void Print(const T* a, int i, const int size);

template <typename T>
int Count(const T* a, int i, const int size);

// --- Реалізація звичайних рекурсивних функцій ---

// Рекурсивно заповнює масив випадковими числами.
void Create(int* a, int i, const int size, const int Low, const int High)
{
    a[i] = Low + rand() % (High - Low + 1);

    if (i < size - 1)
        Create(a, i + 1, size, Low, High);
}

// Рекурсивно виводить елементи масиву в одному рядку.
void Print(int* a, int i, const int size)
{
    cout << setw(5) << a[i];

    if (i < size - 1)
        Print(a, i + 1, size);
    else
        cout << endl << endl;
}


// Рекурсивно підраховує кількість непарних елементів масиву
int Count(const int* a, int i, const int size)
{
    if (i < size)
    {
        if (a[i] % 2 != 0)
            return 1 + Count(a, i + 1, size);
        else
            return Count(a, i + 1, size);
    }
    else
        return 0;
}

// --- Реалізація рекурсивних шаблонів функцій ---

// Універсальне рекурсивне заповнення масиву випадковими числами
template <typename T>
void Create(T* a, int i, const int size, const T Low, const T High)
{
    a[i] = Low + rand() % (High - Low + 1);

    if (i < size - 1)
        Create<T>(a, i + 1, size, Low, High);
}

// Універсальне рекурсивне виведення елементів масиву
template <typename T>
void Print(const T* a, int i, const int size)
{
    cout << setw(5) << a[i];

    if (i < size - 1)
        Print<T>(a, i + 1, size);
    else
        cout << endl << endl;
}

// Універсальний рекурсивний підрахунок кількості непарних елементів масиву
template <typename T>
int Count(const T* a, int i, const int size)
{
    if (i < size)
    {
        if (a[i] % 2 != 0)
            return 1 + Count<T>(a, i + 1, size);
        else
            return Count<T>(a, i + 1, size);
    }
    else
        return 0;
}

// Головна функція програми
int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];
    int Low = -20, High = 20;

    // 1. Формування та виведення масиву a (звичайні рекурсивні функції)
    Create(a, 0, n, Low, High);
    cout << "Initial array a (int):" << endl;
    Print(a, 0, n);

    // 2. Обчислення кількості непарних елементів звичайною та шаблонною функцією
    int countOrdinary = Count(a, 0, n);
    int countTemplate = Count<int>(a, 0, n);
    cout << "Count (ordinary recursive function)   = " << countOrdinary << endl;
    cout << "Count<int> (template recursive function) = " << countTemplate << endl << endl;

    // 3. Демонстрація роботи шаблону функцій для типу long
    const int n2 = 8;
    long b[n2];
    long lowL = 1, highL = 50;
    Create<long>(b, 0, n2, lowL, highL);
    cout << "Array b (long):" << endl;
    Print<long>(b, 0, n2);
    cout << "Count<long> (template recursive function) = " << Count<long>(b, 0, n2) << endl;

    return 0;
}
