// lab06_02_it.cpp
// Кіц Роман Романович
// Лабораторна робота № 6.2 іт
// Опрацювання одновимірних масивів ітераційним способом.
// Варіант 12

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* a, const int size, const int Low, const int High);
void Print(int* a, const int size);
int FindMinIndex(int* a, const int size);
int FindMaxIndex(int* a, const int size);

// Заповнює масив випадковими числами.
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

// Виводить елементи масиву в одному рядку.
void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++) {
        cout << setw(6) << a[i];
    }
    cout << endl << endl;
}

int FindMinIndex(int* a, const int size)
{
    int minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (a[i] < a[minIndex])
            minIndex = i;
    }

    return minIndex;
}

int FindMaxIndex(int* a, const int size)
{
    int maxIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (a[i] > a[maxIndex])
            maxIndex = i;
    }

    return maxIndex;
}


// Виконує основні дії програми.
int main() {
    srand((unsigned)time(NULL));

    const int n = 20;
    int a[n];
    int Low = -50, High = 50;

    int maxIndex, minIndex;

    // 1. Формування та виведення початкового масиву
    Create(a, n, Low, High);
    cout << "Initial array:\n";
    Print(a, n);

    // 2. Знаходимо Індекси мінімального та максимального значення
    minIndex = FindMinIndex(a, n);
    maxIndex = FindMaxIndex(a, n);
    cout << "Min Index: " << minIndex << ". Min value: " << a[minIndex] << ".\n";
    cout << "Max Index: " << maxIndex << ". Max value: " << a[maxIndex] << ".\n";

    return 0;
}