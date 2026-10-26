// lab06_04_it.cpp
// Кіц Роман Романович
// Лабораторна робота № 6.4 іт
// Опрацювання та впорядкування одновимірних динамічних масивів.
// Варіант 12

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Прототипи функцій
void Create(double* a, const int size, const double Low, const double High);
void Print(const double* a, const int size);
int AbsMaxIndex(const double* a, const int size);
double SumAfterFirstPositive(const double* a, const int size);
void TransformArray(double* a, const int size, const int a_val, const int b_val);
void FreeMemory(double*& a);

// 1. Формування масиву випадковими дійсними числами
void Create(double* a, const int size, const double Low, const double High)
{
    for (int i = 0; i < size; i++)
    {
        double random_factor = (double)rand() / RAND_MAX;
        a[i] = Low + random_factor * (High - Low);
    }
}

// 2. Виведення масиву у рядок з форматним виведенням
void Print(const double* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(8) << fixed << setprecision(2) << a[i];
    cout << endl << endl;
}

// 3. Повертає НОМЕР (index + 1) максимального за модулем елемента
int AbsMaxIndex(const double* a, const int size)
{
    int maxIdx = 0;
    for (int i = 1; i < size; i++)
    {
        if (abs(a[i]) > abs(a[maxIdx]))
            maxIdx = i;
    }
    return maxIdx + 1; // НОМЕР = індекс + 1
}

// 4. Обчислення суми елементів після першого додатного
double SumAfterFirstPositive(const double* a, const int size)
{
    int posIdx = -1;
    for (int i = 0; i < size; i++)
    {
        if (a[i] > 0)
        {
            posIdx = i;
            break;
        }
    }

    if (posIdx == -1 || posIdx == size - 1)
        return 0.0;

    double sum = 0.0;
    for (int i = posIdx + 1; i < size; i++)
        sum += a[i];

    return sum;
}

// 5. Перетворення масиву за цілою частиною в інтервалі [a, b]
void TransformArray(double* a, const int size, const int a_val, const int b_val)
{
    double* temp = new double[size]();
    int k = 0;

    // Перший прохід: елементи, ціла частина яких в інтервалі [a, b]
    for (int i = 0; i < size; i++)
    {
        int intPart = (int)a[i];
        if (intPart >= a_val && intPart <= b_val)
            temp[k++] = a[i];
    }

    // Другий прохід: всі інші елементи
    for (int i = 0; i < size; i++)
    {
        int intPart = (int)a[i];
        if (intPart < a_val || intPart > b_val)
            temp[k++] = a[i];
    }

    // Скопіювати назад у вихідний масив
    for (int i = 0; i < size; i++)
        a[i] = temp[i];

    delete[] temp;
}

// 6. Звільнення динамічної пам'яті
void FreeMemory(double*& a)
{
    delete[] a;
    a = nullptr;
}

int main()
{
    srand((unsigned)time(NULL));

    int n;
    cout << "n = ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    // Створення динамічного масиву
    double* a = new double[n];

    double Low = -50.0, High = 50.0;
    Create(a, n, Low, High);

    cout << "\nInitial array a:" << endl;
    Print(a, n);

    // 1.1 Номер максимального за модулем елемента
    int maxNum = AbsMaxIndex(a, n);
    cout << "Number of max absolute element: " << maxNum << endl;

    // 1.2 Сума елементів після першого додатного
    double sum = SumAfterFirstPositive(a, n);
    cout << "Sum after first positive element: " << fixed << setprecision(2) << sum << endl << endl;

    // 2. Перетворення масиву за інтервалом [a_val, b_val]
    int a_val, b_val;
    cout << "Enter interval [a, b] for integer part:" << endl;
    cout << "a = "; cin >> a_val;
    cout << "b = "; cin >> b_val;

    TransformArray(a, n, a_val, b_val);

    cout << "\nModified array a:" << endl;
    Print(a, n);

    // Звільнення пам'яті
    FreeMemory(a);

    return 0;
}