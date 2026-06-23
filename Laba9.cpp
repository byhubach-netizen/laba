#include <iostream>
#include <string>

using namespace std;

// Завдання 1

// Власна реалізація методу string::insert()
void myInsert(char result[], const char source[], const char insertStr[], int pos)
{
    int i = 0;
    int j = 0;
    int k = 0;

    // Копіюємо символи до позиції вставки
    while (i < pos && source[i] != '\0')
    {
        result[k++] = source[i++];
    }

    // Вставляємо новий рядок
    while (insertStr[j] != '\0')
    {
        result[k++] = insertStr[j++];
    }

    // Копіюємо решту вихідного рядка
    while (source[i] != '\0')
    {
        result[k++] = source[i++];
    }

    result[k] = '\0';
}

// Виконання завдання 1
void task1()
{
    string str;
    string ins;
    int pos;

    cout << "\nEnter string: ";
    getline(cin, str);

    cout << "Enter substring to insert: ";
    getline(cin, ins);

    cout << "Enter insertion position: ";
    cin >> pos;
    cin.ignore();

    string strCopy = str;

    // Виклик стандартного методу
    strCopy.insert(pos, ins);

    char result[500];

    // Виклик власної функції
    myInsert(result, str.c_str(), ins.c_str(), pos);

    cout << "\nResult of string::insert():\n";
    cout << strCopy << endl;

    cout << "\nResult of custom function:\n";
    cout << result << endl;
}

// Завдання 2 

// Перевірка, чи є рядок цілим числом
bool isInteger(string s)
{
    if (s.empty())
        return false;

    int start = 0;

    if (s[0] == '+' || s[0] == '-')
        start = 1;

    if (start == (int)s.length())
        return false;

    for (int i = start; i < (int)s.length(); i++)
    {
        if (!isdigit(s[i]))
            return false;
    }

    return true;
}

// Перевірка, чи є рядок дійсним числом
bool isReal(string s)
{
    if (s.empty())
        return false;

    int start = 0;
    int dots = 0;

    if (s[0] == '+' || s[0] == '-')
        start = 1;

    if (start == (int)s.length())
        return false;

    for (int i = start; i < (int)s.length(); i++)
    {
        if (s[i] == '.')
        {
            dots++;
        }
        else if (!isdigit(s[i]))
        {
            return false;
        }
    }

    return dots == 1;
}

// Визначення типу числа
int checkNumber(string s)
{
    if (isInteger(s))
        return 1;   // Ціле число

    if (isReal(s))
        return 2;   // Дійсне число

    return 0;       // Не число
}

// Виконання завдання 2
void task2()
{
    string s;

    cout << "\nEnter string: ";
    getline(cin, s);

    cout << "Result: " << checkNumber(s) << endl;
}

// Головне меню

int main()
{
    int choice;

    do
    {
        cout << "\nMENU\n";
        cout << "1 - Task 1 (insert)\n";
        cout << "2 - Task 2 (number check)\n";
        cout << "0 - Exit\n";
        cout << "Your choice: ";

        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            task1();
            break;

        case 2:
            task2();
            break;

        case 0:
            cout << "Program finished.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}