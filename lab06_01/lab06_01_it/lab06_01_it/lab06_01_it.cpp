// lab06_01_it.cpp
// Кіц Роман Романович
// Лабораторна робота № 6.1 іт
// Пошук елементів одновимірного масиву ітераційним способом.
// Варіант 12

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* c, const int size, const int Low, const int High);
void Print(int* c, const int size);
int Count(int* c, const int size);
int Sum(int* c, const int size);
void Modify(int* c, const int size);

// Заповнює масив випадковими числами.
void Create(int* c, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        c[i] = Low + rand() % (High - Low + 1);
    }
}

// Виводить елементи масиву в одному рядку.
void Print(int* c, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << c[i];
    }
    cout << endl << endl;
}

// Підраховує кількість потрібних елементів.
int Count(int* c, const int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (c[i] % 2 == 0 || !(i % 8 == 0)) {
            count++;
        }
    }

    return count;
}

// Обчислює суму потрібних елементів.
int Sum(int* c, const int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        if (c[i] % 2 == 0 || !(i % 8 == 0)) {
            sum += c[i];
        }
    }

    return sum;
}

// Замінює потрібні елементи нулями.
void Modify(int* c, const int size) {
    for (int i = 0; i < size; i++) {
        if (c[i] % 2 == 0 || !(i % 8 == 0)) {
            c[i] = 0;
        }
    }
}

// Виконує основні дії програми.
int main() {
    srand((unsigned)time(NULL));

    const int n = 25;
    int c[n];
    int Low = 5, High = 90;

    // 1. Формування та виведення початкового масиву
    Create(c, n, Low, High);
    cout << "Initial array:\n";
    Print(c, n);

    // 2. Обчислення кількості та суми за критерієм
    int count = Count(c, n);
    int sum = Sum(c, n);
    cout << "Count = " << count << endl;
    cout << "Sum = " << sum << endl;

    // 3. Заміна елементів нулями та виведення масиву
    Modify(c, n);
    cout << "Modified array:\n";
    Print(c, n);

    return 0;
}