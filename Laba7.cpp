// Лабораторна робота 7
// Тема: Реалізація алгоритмів обробки двовимірних масивів мовою С++
// Завдання 1: Matrix25 – знайти номер рядка з найбільшою сумою елементів
// Завдання 2: Matrix77 – обнулити елементи вище побічної діагоналі (без if)

#include <iostream>
using namespace std;

const int MAX = 50;

// Введення матриці
void inputMatrix(int a[MAX][MAX], int& rows, int& cols)
{
    do
    {
        cout << "Rows (2-50): ";
        cin >> rows;
        cout << "Cols (2-50): ";
        cin >> cols;
    } while (rows < 2 || rows > 50 || cols < 2 || cols > 50);

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> a[i][j];
}

// Виведення матриці
void printMatrix(int a[MAX][MAX], int rows, int cols)
{
    cout << "\nMatrix:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}

// Matrix25
void task25()
{
    int a[MAX][MAX];
    int rows, cols;

    inputMatrix(a, rows, cols);
    printMatrix(a, rows, cols);

    int maxSum = 0;
    int maxRow = 0;

    for (int j = 0; j < cols; j++)
        maxSum += a[0][j];

    for (int i = 1; i < rows; i++)
    {
        int sum = 0;

        for (int j = 0; j < cols; j++)
            sum += a[i][j];

        if (sum > maxSum)
        {
            maxSum = sum;
            maxRow = i;
        }
    }

    cout << "\nRow number with maximum sum: "
        << maxRow + 1 << endl;

    cout << "Maximum sum: "
        << maxSum << endl;
}
void task77()
{
    int a[MAX][MAX];
    int n;

    do
    {
        cout << "Enter matrix size (2-50): ";
        cin >> n;
    } while (n < 2 || n > 50);

    cout << "Enter matrix elements:\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "\nOriginal matrix:\n";
    printMatrix(a, n, n);

    // Обнулення елементів вище побічної діагоналі
    for (int i = 0; i < n; i++)
        for (int j = n - i; j < n; j++)
            a[i][j] = 0;

    cout << "\nResult matrix:\n";
    printMatrix(a, n, n);
}

int main()
{
    int choice;

    do
    {
        cout << "\n1 - Matrix25\n";
        cout << "2 - Matrix77\n";
        cout << "0 - Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            task25();
            break;

        case 2:
            task77();
            break;

        case 0:
            cout << "Program finished.\n";
            break;

        default:
            cout << "Wrong choice!\n";
        }
    } while (choice != 0);

    return 0;
}


