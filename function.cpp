#include <iostream>
#include <cstdlib> 
#include "function.h"

using namespace std;

void add_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        *(array + i) = rand() % 100;
    }
}

void cout_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(array + i) << " ";
    }
    cout << endl;
}

int find_min(int* array, int size) {
    int min_val = *array;
    for (int i = 1; i < size; i++) {
        if (*(array + i) < min_val) {
            min_val = *(array + i);
        }
    }
    return min_val;
}

int find_max(int* array, int size) {
    int max_val = *array;
    for (int i = 1; i < size; i++) {
        if (*(array + i) > max_val) {
            max_val = *(array + i);
        }
    }
    return max_val;
}

void sort_array(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(array + j) > *(array + j + 1)) {
                int temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
            }
        }
    }
}

void edit_array(int* array, int size, int index, int new_value) {
    if (index >= 0 && index < size) {
        *(array + index) = new_value;
    }
    else {
        cout << "Помилка: Індекс виходить за межі масиву!" << endl;
    }
}