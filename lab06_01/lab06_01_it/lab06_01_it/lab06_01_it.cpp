// lab06_01_it.cpp
// Кіц Роман Романович
// Лабораторна робота № 6.1 іт
// Пошук елементів одновимірного масиву ітераційним способом.
// Варіант 12

#include <iostream>
#include <iomanip>
#include <time.h> 

using namespace std;

void Create(int* a, const int size, const int Low, const int High);
void Print(int* a, const int size);
int Count(int* a, const int size);
int Sum(int* a, const int size);
void Modify(int* a, const int size);

void Create(int* a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

void Print(int* a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << a[i];
    }
    cout << endl << endl;
}

int Count(int* a, const int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if ((a[i] % 2 == 0) || (i % 8 != 0)) {
            count++;
        }
    }
    return count; // повертаємо результат у main, НЕ виводимо через cout всередині!
}

int Sum(int* a, const int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if ((a[i] % 2 == 0) || (i % 8 != 0)) {
            sum += a[i];
        }
    }
    return sum;
}

void Modify(int* a, const int size) {
    for (int i = 0; i < size; i++) {
        if ((a[i] % 2 == 0) || (i % 8 != 0)) {
            a[i] = 0;
        }
    }
}

int main() {
    srand((unsigned)time(NULL));

    const int n = 25;
    int a[n];
    int Low = 5, High = 90;

    // 1. Формування та виведення початкового масиву
    Create(a, n, Low, High);
    cout << "Initial array:\n";
    Print(a, n);

    // 2. Обчислення кількості та суми за критерієм
    int count = Count(a, n);
    int sum = Sum(a, n);
    cout << "Count = " << count << endl;
    cout << "Sum = " << sum << endl;

    // 3. Заміна елементів нулями та виведення зміненого масиву
    Modify(a, n);
    cout << "Modified array:\n";
    Print(a, n);

    return 0;
}