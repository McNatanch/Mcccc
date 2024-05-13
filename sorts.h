#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>


void BubbleSort(int* ar, size_t size, bool (*comp)(int, int));

void InsertionSort(int* ar, size_t size, bool (*comp)(int, int));

void SelectionSort(int* ar, size_t size, bool (*comp)(int, int));

void ShellSort(int* ar, size_t size, bool (*comp)(int, int));

bool IfSorted (int* ar, size_t size, bool (*comp)(int, int));

void Swap (int* a, int* b);

bool SortUp(int a, int b);

bool SortDown(int a, int b);

