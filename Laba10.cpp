#include <iostream>
#include <cmath>

using namespace std;

// Завдання 1
// Структура для зберігання координат точки
struct TPoint
{
    double x;
    double y;
};
// Структура для зберігання вершин трикутника
struct TTriangle
{
    TPoint A;
    TPoint B;
    TPoint C;
};
// Функція обчислення довжини відрізка між двома точками
double Length(TPoint P1, TPoint P2)
{
    return sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2));
}
// Функція обчислення площі трикутника за формулою Герона
double Area(TTriangle T)
{
    // Знаходимо довжини сторін трикутника
    double a = Length(T.A, T.B);
    double b = Length(T.B, T.C);
    double c = Length(T.C, T.A);
    // Напівпериметр
    double p = (a + b + c) / 2.0;
    // Формула Герона
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void TaskParam66()
{
    TPoint A, B, C, D;

    cout << "\n Task 1 \n";
    // Введення координат точок
    cout << "Enter point A (x y): ";
    cin >> A.x >> A.y;

    cout << "Enter point B (x y): ";
    cin >> B.x >> B.y;

    cout << "Enter point C (x y): ";
    cin >> C.x >> C.y;

    cout << "Enter point D (x y): ";
    cin >> D.x >> D.y;
    // Створення трикутників
    TTriangle ABC = { A, B, C };
    TTriangle ABD = { A, B, D };
    TTriangle ACD = { A, C, D };
    // Виведення площ
    cout << "\nArea ABC = " << Area(ABC);
    cout << "\nArea ABD = " << Area(ABD);
    cout << "\nArea ACD = " << Area(ACD) << endl;
}

// Завдання 2

struct AverageData
{
    double a;
    double b;
    double average;
};
// Функція обчислення середнього арифметичного
void CalculateAverage(AverageData& data)
{
    data.average = (data.a + data.b) / 2.0;
}

void TaskBegin8()
{
    AverageData data;

    cout << "\n= Task 2\n";

    cout << "Enter a: ";
    cin >> data.a;

    cout << "Enter b: ";
    cin >> data.b;
    // Виклик функції
    CalculateAverage(data);

    cout << "Arithmetic mean = " << data.average << endl;
}

// Завдання 3

struct TriangleData
{
    int a;
    int b;
    int c;
    bool exists;
};
// Перевірка існування трикутника
void CheckTriangle(TriangleData& t)
{
    // Трикутник існує, якщо сума будь-яких двох сторін більша за третю сторону
    t.exists =
        (t.a + t.b > t.c) &&
        (t.a + t.c > t.b) &&
        (t.b + t.c > t.a);
}

void TaskBoolean33()
{
    TriangleData t;

    cout << "\n Task 3\n";

    cout << "Enter sides a b c: ";
    cin >> t.a >> t.b >> t.c;

    CheckTriangle(t);

    if (t.exists)
        cout << "TRUE - triangle exists\n";
    else
        cout << "FALSE - triangle does not exist\n";
}

// Меню

int main()
{
    int choice;

    do
    {
        cout << "\n1 - Task 1";
        cout << "\n2 - Task 2";
        cout << "\n3 - Task 3";
        cout << "\n0 - Exit";
        cout << "\nChoose: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            TaskParam66();
            break;

        case 2:
            TaskBegin8();
            break;

        case 3:
            TaskBoolean33();
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