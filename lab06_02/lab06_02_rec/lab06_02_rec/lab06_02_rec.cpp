// lab06_02_rec.cpp
// Кіц Роман Романович
// Лабораторна робота № 6.2 рек
// Опрацювання одновимірних масивів ітераційним способом.
// Варіант 12

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* c, int i, const int size, const int Low, const int High);
void Print(int* c, int i, const int size);
void FindMinMaxIndexes(int* a, int i, int size, int* minIndex, int* maxIndex);

// Рекурсивно заповнює масив випадковими числами.
void Create(int* c, int i, const int size, const int Low, const int High) 
{
    c[i] = Low + rand() % (High - Low + 1);

    if (i < size - 1)
        Create(c, i + 1, size, Low, High);
}

// Рекурсивно виводить елементи масиву.
void Print(int* c, int i, const int size) 
{
    cout << setw(4) << c[i];

    if (i < size - 1)
        Print(c, i + 1, size);
    else
        cout << endl << endl;
}

// Рекурсивно знаходить індекси мінімального та максимального елементів.
void FindMinMaxIndexes(int* a, int i, int size, int* minIndex, int* maxIndex)
{
    if (i == size)
        return;

    if (a[i] < a[*minIndex])
        *minIndex = i;

    if (a[i] > a[*maxIndex])
        *maxIndex = i;

    FindMinMaxIndexes(a, i + 1, size, minIndex, maxIndex);
}

// Виконує основні дії програми.
int main() {
    srand((unsigned)time(NULL));

    const int n = 20;
    int a[n];
    int Low = -50, High = 50;

    int maxIndex = 0, minIndex = 0;

    // 1. Формування та виведення початкового масиву
    Create(a, 0, n, Low, High);
    cout << "Initial array:\n";
    Print(a, 0, n);

    // 2. Знаходимо Індекси мінімального та максимального значення
    FindMinMaxIndexes(a, 0, n, &minIndex, &maxIndex);
    cout << "Min Index: " << minIndex << ". Min value: " << a[minIndex] << ".\n";
    cout << "Max Index: " << maxIndex << ". Max value: " << a[maxIndex] << ".\n";

    return 0;
}
