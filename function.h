#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>

void add_array(int* array, int size);
void cout_array(int* array, int size);
int find_min(int* array, int size);
int find_max(int* array, int size);
void sort_array(int* array, int size);
void edit_array(int* array, int size, int index, int new_value);

#ifdef INTEGER
#define FillArray add_array
#define PrintArray cout_array
#define FindMin find_min
#define FindMax find_max
#define SortArray sort_array
#define EditArray edit_array
#endif

#endif