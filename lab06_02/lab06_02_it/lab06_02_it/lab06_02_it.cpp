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
void FindMinMaxIndexes(int* a, int size, int* minIndex, int* maxIndex);

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

// Знаходить індекси мінімального та максимального елементів.
void FindMinMaxIndexes(int* a, int size, int* minIndex, int* maxIndex) 
{
    int currentMax = 0;
    for (int i = 1; i < size; i++)
    {
        if (a[i] > a[currentMax])
            currentMax = i;
    }
    *maxIndex = currentMax;

    int currentMin = 0;
    for (int i = 1; i < size; i++)
    {
        if (a[i] < a[currentMin])
            currentMin = i;
    }
    *minIndex = currentMin;
}

// Виконує основні дії програми.
int main() {
    srand((unsigned)time(NULL));

    const int n = 20;
    int a[n];
    int Low = -50, High = 50;
    
    int maxIndex = 0, minIndex = 0;

    // 1. Формування та виведення початкового масиву
    Create(a, n, Low, High);
    cout << "Initial array:\n";
    Print(a, n);

    // 2. Знаходимо Індекси мінімального та максимального значення
    FindMinMaxIndexes(a, n, &minIndex, &maxIndex);
    cout << "Min Index: " << minIndex << ". Min value: " << a[minIndex] << ".\n";
    cout << "Max Index: " << maxIndex << ". Max value: " << a[maxIndex] << ".\n";

    return 0;
}