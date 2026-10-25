// lab06_02_rec.cpp
// Кіц Роман Романович
// Лабораторна робота № 6.2 рек
// Опрацювання одновимірних масивів рекурсивним способом.
// Варіант 12

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* a, int i, const int size, const int Low, const int High);
void Print(int* a, int i, const int size);
int FindMinIndex(int* a, const int size, int i, int minIndex);
int FindMaxIndex(int* a, const int size, int i, int maxIndex);

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
    cout << setw(6) << a[i];

    if (i < size - 1)
        Print(a, i + 1, size);
    else
        cout << endl << endl;
}

// Рекурсивно шукає індекс мінімального елемента масиву.
int FindMinIndex(int* a, const int size, int i, int minIndex)
{
    if (i >= size)
        return minIndex;

    if (a[i] < a[minIndex])
        minIndex = i;

    return FindMinIndex(a, size, i + 1, minIndex);
}

// Рекурсивно шукає індекс максимального елемента масиву.
int FindMaxIndex(int* a, const int size, int i, int maxIndex)
{
    if (i >= size)
        return maxIndex;

    if (a[i] > a[maxIndex])
        maxIndex = i;

    return FindMaxIndex(a, size, i + 1, maxIndex);
}

// Виконує основні дії програми.
int main() {
    srand((unsigned)time(NULL));

    const int n = 20;
    int a[n];
    int Low = -50, High = 50;

    // 1. Формування та виведення початкового масиву
    Create(a, 0, n, Low, High);
    cout << "Initial array:\n";
    Print(a, 0, n);

    // 2. Знаходимо індекси мінімального та максимального значень
    // Починаємо перевірку з індексу i = 1, вважаючи 0-й початковим екстремумом
    int minIndex = FindMinIndex(a, n, 1, 0);
    int maxIndex = FindMaxIndex(a, n, 1, 0);

    cout << "Min Index: " << minIndex << ". Min value: " << a[minIndex] << ".\n";
    cout << "Max Index: " << maxIndex << ". Max value: " << a[maxIndex] << ".\n";

    return 0;
}