// lab06_01_rec.cpp
// Кіц Роман Романович
// Лабораторна робота № 6.1 рек
// Пошук елементів одновимірного масиву рекурсивним способом.
// Варіант 12

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* c, int i, const int size, const int Low, const int High);
void Print(int* c, int i, const int size);
int Count(int* c, int i, const int size);
int Sum(int* c, int i, const int size);
void Modify(int* c, int i, const int size);

// Рекурсивно заповнює масив випадковими числами.
void Create(int* c, int i, const int size, const int Low, const int High) {
    c[i] = Low + rand() % (High - Low + 1);

    if (i < size - 1)
        Create(c, i + 1, size, Low, High);
}

// Рекурсивно виводить елементи масиву.
void Print(int* c, int i, const int size) {
    cout << setw(4) << c[i];

    if (i < size - 1)
        Print(c, i + 1, size);
    else
        cout << endl << endl;
}

// Рекурсивно підраховує кількість потрібних елементів.
int Count(int* c, int i, const int size) {
    if (i == size)
        return 0;

    if (c[i] % 2 == 0 || i % 8 != 0)
        return 1 + Count(c, i + 1, size);

    return Count(c, i + 1, size);
}

// Рекурсивно обчислює суму потрібних елементів.
int Sum(int* c, int i, const int size) {
    if (i == size)
        return 0;

    if (c[i] % 2 == 0 || i % 8 != 0)
        return c[i] + Sum(c, i + 1, size);

    return Sum(c, i + 1, size);
}

// Рекурсивно замінює потрібні елементи нулями.
void Modify(int* c, int i, const int size) {
    if (c[i] % 2 == 0 || i % 8 != 0) {
        c[i] = 0;
    }

    if (i < size - 1)
        Modify(c, i + 1, size);
}

// Виконує основні дії програми.
int main() {
    srand((unsigned)time(NULL));

    const int n = 25;
    int c[n];
    int Low = 5, High = 90;

    // 1. Формування та виведення початкового масиву
    Create(c, 0, n, Low, High);
    cout << "Initial array:\n";
    Print(c, 0, n);

    // 2. Обчислення кількості та суми за критерієм
    int count = Count(c, 0, n);
    int sum = Sum(c, 0, n);
    cout << "Count = " << count << endl;
    cout << "Sum = " << sum << endl;

    // 3. Заміна елементів нулями та виведення масиву
    Modify(c, 0, n);
    cout << "Modified array:\n";
    Print(c, 0, n);

    return 0;
}