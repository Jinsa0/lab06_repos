// lab06_04_rec.cpp
// Кіц Роман Романович
// Лабораторна робота № 6.4 рек
// Опрацювання та впорядкування одновимірних динамічних масивів.
// Варіант 12

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Прототипи функцій
void Create(double* a, int i, const int size, const double Low, const double High);
void Print(const double* a, int i, const int size);
int AbsMaxIndex(const double* a, int i, const int size, int maxIdx);
int FindFirstPositive(const double* a, int i, const int size);
double SumRecursive(const double* a, int i, const int size);
double SumAfterFirstPositive(const double* a, int i, const int size);
int CopyInRange(const double* a, double* temp, int i, int k, const int size, const int a_val, const int b_val);
int CopyOutsideRange(const double* a, double* temp, int i, int k, const int size, const int a_val, const int b_val);
void CopyBack(double* a, const double* temp, int i, const int size);
void TransformArray(double* a, int i, const int size, const int a_val, const int b_val);
void FreeMemory(double*& a);


// 1. Формування масиву випадковими дійсними числами
void Create(double* a, int i, const int size,
    const double Low, const double High)
{
    if (i == size)
        return;

    double random_factor = (double)rand() / RAND_MAX;
    a[i] = Low + random_factor * (High - Low);

    Create(a, i + 1, size, Low, High);
}


// 2. Виведення масиву
void Print(const double* a, int i, const int size)
{
    if (i == size)
    {
        cout << endl << endl;
        return;
    }

    cout << setw(8) << fixed << setprecision(2) << a[i];

    Print(a, i + 1, size);
}


// 3. Повертає НОМЕР (index + 1) максимального за модулем елемента
int AbsMaxIndex(const double* a, int i, const int size, int maxIdx)
{
    if (i == size)
        return maxIdx + 1;

    if (fabs(a[i]) > fabs(a[maxIdx]))
        maxIdx = i;

    return AbsMaxIndex(a, i + 1, size, maxIdx);
}


// 4.1. Знаходження індексу першого додатного числа
int FindFirstPositive(const double* a, int i, const int size)
{
    if (i == size)
        return -1;

    if (a[i] > 0)
        return i;

    return FindFirstPositive(a, i + 1, size);
}


// 4.2. Рекурсивне сумування елементів від індексу i до кінця
double SumRecursive(const double* a, int i, const int size)
{
    if (i == size)
        return 0.0;

    return a[i] + SumRecursive(a, i + 1, size);
}


// 4. Обчислення суми елементів після першого додатного
double SumAfterFirstPositive(const double* a, int i, const int size)
{
    int firstPosIdx = FindFirstPositive(a, 0, size);

    if (firstPosIdx == -1 || firstPosIdx == size - 1)
        return 0.0;

    return SumRecursive(a, firstPosIdx + 1, size);
}


// 5.1. Перший прохід: елементи, ціла частина яких у [a_val, b_val]
int CopyInRange(const double* a, double* temp, int i, int k, const int size, const int a_val, const int b_val)
{
    if (i == size)
        return k;

    int intPart = (int)a[i];

    if (intPart >= a_val && intPart <= b_val)
        temp[k++] = a[i];

    return CopyInRange(a, temp, i + 1, k, size, a_val, b_val);
}


// 5.2. Другий прохід: усі інші елементи
int CopyOutsideRange(const double* a, double* temp, int i, int k, const int size, const int a_val, const int b_val)
{
    if (i == size)
        return k;

    int intPart = (int)a[i];

    if (intPart < a_val || intPart > b_val)
        temp[k++] = a[i];

    return CopyOutsideRange(a, temp, i + 1, k, size, a_val, b_val);
}


// 5.3. Третій прохід: копіювання назад у вихідний масив
void CopyBack(double* a, const double* temp, int i, const int size)
{
    if (i == size)
        return;

    a[i] = temp[i];

    CopyBack(a, temp, i + 1, size);
}


// 5. Перетворення масиву за цілою частиною в інтервалі [a, b]
void TransformArray(double* a, int i, const int size, const int a_val, const int b_val)
{
    if (i == size)
        return;

    double* temp = new double[size];

    // Перший прохід
    int k = CopyInRange(a, temp, 0, 0, size, a_val, b_val);

    // Другий прохід
    k = CopyOutsideRange(a, temp, 0, k, size, a_val, b_val);

    // Третій прохід
    CopyBack(a, temp, 0, size);

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
    Create(a, 0, n, Low, High);

    cout << "\nInitial array a:" << endl;
    Print(a, 0, n);

    // 1.1. Номер максимального за модулем елемента
    int maxNum = AbsMaxIndex(a, 0, n, 0);
    cout << "Number of max absolute element: " << maxNum << endl;

    // 1.2. Сума елементів після першого додатного
    double sum = SumAfterFirstPositive(a, 0, n);
    cout << "Sum after first positive element: "
        << fixed << setprecision(2) << sum << endl << endl;

    // 2. Перетворення масиву за інтервалом [a_val, b_val]
    int a_val, b_val;

    cout << "Enter interval [a, b] for integer part:" << endl;
    cout << "a = ";
    cin >> a_val;
    cout << "b = ";
    cin >> b_val;

    if (a_val > b_val)
    {
        cout << "Invalid interval!" << endl;
        FreeMemory(a);
        return 1;
    }

    TransformArray(a, 0, n, a_val, b_val);

    cout << "\nModified array a:" << endl;
    Print(a, 0, n);

    // Звільнення пам'яті
    FreeMemory(a);

    return 0;
}
