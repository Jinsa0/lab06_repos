// lab06_01_rec.cpp
// Кіц Роман Романович
// Лабораторна робота № 6.1 рек
// Пошук елементів одновимірного масиву рекурсивним способом.
// Варіант 12

#include <iostream>
#include <iomanip>
#include <time.h> 

using namespace std;

void Create(int* a, int i, const int size, const int Low, const int High);
void Print(int* a, int i, const int size);
int Count(int* a, int i, const int size);
int Sum(int* a, int i, const int size);
void Modify(int* a, int i, const int size);

void Create(int* a, int i, const int size, const int Low, const int High) {
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, i + 1, size, Low, High);
}

void Print(int* a, int i, const int size) {
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, i + 1, size);
    else 
        cout << endl << endl;
}

int Count(int* a, int i, const int size) {
    if (i == size)
        return 0;
    if (a[i] % 2 == 0 || i % 8 != 0)
        return 1 + Count(a, i + 1, size);
    return Count(a, i + 1, size);
}

int Sum(int* a, int i, const int size) {
    if (i == size)
        return 0;
    if (a[i] % 2 == 0 || i % 8 != 0)
        return a[i] + Sum(a, i + 1, size);
    return Sum(a, i + 1, size);
}

void Modify(int* a, int i, const int size) {
    if ((a[i] % 2 == 0) || (i % 8 != 0)) {
        a[i] = 0;
    }
    if (i < size - 1)
        Modify(a, i + 1, size);
}

int main() {
    srand((unsigned)time(NULL));

    const int n = 25;
    int a[n];
    int Low = 5, High = 90;

    // 1. Формування та виведення початкового масиву
    Create(a, 0, n, Low, High);
    cout << "Initial array:\n";
    Print(a, 0, n);

    // 2. Обчислення кількості та суми за критерієм
    int count = Count(a, 0, n);
    int sum = Sum(a, 0, n);
    cout << "Count = " << count << endl;
    cout << "Sum = " << sum << endl;

    // 3. Заміна елементів нулями та виведення зміненого масиву
    Modify(a, 0, n);
    cout << "Modified array:\n";
    Print(a, 0, n);

    return 0;
}