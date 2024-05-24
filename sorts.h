#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>


void Swap (int* a, int* b);

void BubbleSort(int* ar, size_t size, bool (*comp)(int, int));

void InsertionSort(int* ar, size_t size, bool (*comp)(int, int));

void SelectionSort(int* ar, size_t size, bool (*comp)(int, int));

void ShellSort(int* ar, size_t size, bool (*comp)(int, int));

void MYSort(int* ar, size_t size, bool (*comp)(int, int));//<---------------

void QuickSort(int* ar, size_t size, bool (*comp)(int, int));

void QuickSortMod(int* ar, size_t size, bool (*comp)(int, int));

void CountSort(int* ar, size_t size, bool (*comp)(int, int));

void HeapSort(int* ar, size_t size, bool (*comp)(int, int));

void heapify(int* arr, int n, int i, bool (*comp)(int, int));

void Merge(int* A, int first, int last, bool (*comp)(int, int));

void MergeSort(int* A, int first, int last, bool (*comp)(int, int));

bool SortUp(int a, int b);

bool SortDown(int a, int b);
