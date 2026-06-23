#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_SIZE = 20; 
// Зчитування масиву з файлу
void get_mas(string inputFile, int arr[], int &n)
{
    
    ifstream fin(inputFile);

    if (!fin)
    {
        cout << "File opening error!" << endl;
        return;
    }

    fin >> n;

    for (int i = 0; i < n; i++)
    {
        fin >> arr[i];
    }

    fin.close();
}

// Запис масиву у файл
void show_mas(string outFile, const int arr[], int n)
{
    ofstream fout(outFile);

    if (!fout)
    {
        cout << "File creation error!" << endl;
        return;
    }

    fout << "Sorted array:" << endl;

    for (int i = 0; i < n; i++)
    {
        fout << arr[i] << " ";
    }

    fout << endl;

    fout.close();
}

// Бульбашкове сортування за зростанням
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[MAX_SIZE];
    int n;

    string inputFile;
    string outputFile;

    cout << "Enter input file name: ";
    cin >> inputFile;

    cout << "Enter output file name: ";
    cin >> outputFile;

    get_mas(inputFile, arr, n);

    cout << "\nArray before sorting:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    bubbleSort(arr, n);

    cout << "\n\nArray after sorting:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    show_mas(outputFile, arr, n);

    cout << "\nResult written to file " << outputFile << endl;

    return 0;
}