#include <iostream>
#include <time.h>
#include "sorts.h"
void test_BubbleSort(int* ar, size_t size, bool (*comp)(int, int));

void test_InsertionSort(int* ar, size_t size, bool (*comp)(int, int));

void test_SelectionSort(int* ar, size_t size, bool (*comp)(int, int));

void test_ShellSort(int* ar, size_t size, bool (*comp)(int, int));

bool test_IfSorted (int* ar, size_t size, bool (*comp)(int, int));

void test_MYSort(int* ar, size_t size, bool (*comp)(int, int));//<---------------

void test_QuickSort(int* ar, size_t size, bool (*comp)(int, int));

void test_QuickSortMod(int* ar, size_t size, bool (*comp)(int, int));

void test_CountSort(int* ar, size_t size, bool (*comp)(int, int));

void test_HeapSort(int* ar, size_t size, bool (*comp)(int, int));

void test_MergeSort(int* A, int first, int last, bool (*comp)(int, int));

void test_Sort ( void (*sort)(int* , size_t, bool (*comp)(int, int)), bool (*comp)(int, int));

