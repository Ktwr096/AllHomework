#define INTEGER 
#include <iostream>
#include <ctime>  
#include "function.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    srand(time(0));

    const int size = 10;
    int array[size];

    FillArray(array, size);

    cout << "Початковий масив: ";
    PrintArray(array, size);

    cout << "Мінімальний елемент: " << FindMin(array, size) << endl;
    cout << "Максимальний елемент: " << FindMax(array, size) << endl;

    cout << "\nЗмінюємо елемент з індексом 2 на значення 99..." << endl;
    EditArray(array, size, 2, 99);
    cout << "Масив після редагування: ";
    PrintArray(array, size);

    cout << "\nСортуємо масив..." << endl;
    SortArray(array, size);
    cout << "Відсортований масив: ";
    PrintArray(array, size);

    return 0;
}