#include "sorts.h"


void ShellSort(int* ar, size_t size, bool (*comp)(int, int))
{

 for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int space = ar[i];
            int j;
            for(j = i; j >= gap && comp(ar[j-gap],space); j -= gap)
            {
                ar[j] = ar[j - gap];
            }
            ar[j] = space;
        }
    }
}



void Swap (int* a, int* b)
{
    int space = (*a);
    (*a) = (*b);
    (*b) = space;
}

void InsertionSort(int* ar, size_t size, bool (*comp)(int, int))
{
    int lb = 1;






    int space = 0;
    do
    {
        space = ar[lb];
        for (int i = 0; i < lb; i++)
        {
            if (comp(ar[i],space))
            {
                for (int j = lb; j != i-1; j--)
                {
                    ar[j] = ar[j-1];
                }
                ar[i] = space;
                break;
            }
        }
        lb++;
    }while(lb != size);
}

void SelectionSort(int* ar, size_t size, bool (*comp)(int, int))
{
    if (comp)
    {
        do
        {
            int indmax = 0;
            for (int i = 0; i < size; i++)
            {
                if (comp(ar[i],ar[indmax]))
                {
                    indmax = i;
                }
            }
            Swap(&ar[indmax],&ar[size-1]);
            size--;
        }while(size > 1);
    }
}

void BubbleSort(int* ar, size_t size, bool (*comp)(int, int))
{ 
 

    bool mark = true;
    do
    {
        mark = false;
        for (int i = 0; i < size-1; i++)
        {
            if (comp(ar[i],ar[i+1]))
                {
                    int space = ar[i];
                    ar[i] = ar[i+1];
                    ar[i+1] = space;
                    mark = true;
                }
        }

    }while(mark);
}

void MYSort(int* ar, size_t size, bool (*comp)(int, int))
{ 


    int space[size];
    int lin = size - 1;
    do
    {
        int maxim = 0;
        for (int i = 0; i < size; i++)
            if(ar[i] != 0)
                maxim = i;


        for (int i = 0;i < size; i++)
        {
            if (ar[i] == 0)
            {}
            else
                if (comp(ar[i],ar[maxim]))
                    maxim = i;
        }
        space[lin] = ar[maxim];
        ar[maxim] = 0;
        lin--;
    }while(lin != -1);
    for (int i = 0; i < size; i++)
        ar[i] = space[i];
}

void QuickSort(int* ar, size_t size, bool (*comp)(int, int))
{
    int i = 0;
    int j = size - 1;
    int mid = ar[size / 2];

    do
    {
        while(comp(mid,ar[i]))
        {
            i++;
        }
        while(comp(ar[j],mid))
        {
            j--;
        }
        if (i <= j)
        {
            int space = ar[i];
            ar[i] = ar[j];
            ar[j] = space;
            i++;
            j--;
        }
    }while(i <= j);

    if (j > 0)
    {
        QuickSort(ar,j+1, comp);
    }
    if(i < size)
    {
        QuickSort(&ar[i], size - i, comp);
    }
}
// !!
void QuickSortMod(int* ar, size_t size, bool (*comp)(int, int))
{ 


    int i = 0;
    int j = size - 1;
    int mid = ar[size / 2];

    do
    {
        while(comp(mid,ar[i]))
        {
            i++;
        }
        while(comp(ar[j],mid))
        {
            j--;
        }
        if (i <= j)
        {
            int space = ar[i];
            ar[i] = ar[j];
            ar[j] = space;
            i++;
            j--;
        }
    }while(i - j < 10);

    InsertionSort(&ar[i], j - i, comp);

    if (j > 0)
    {
        QuickSort(ar,j+1, comp);
    }
    if(i < size)
    {
        QuickSort(&ar[i], size - i, comp);
    }
}

void CountSort(int* ar, size_t size, bool (*comp)(int, int))
{ 
int ln = 1001;
    int bf[ln];

    for (int i = 0; i < ln; i++)
    {
        bf[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < ln; j++)
        {
            if(ar[i] == j)
            {
                bf[j]++;
            }
        }
    }

    int l = 0;
    //int i = 0; i < ln; i++
    //Сортировка подсчетом не сравнивает числа
    //Поэтому применить компаратор невозможно
    //Поэтому определение направления сортировки вручную
    //Вообще сортировка говно - мое личное мнение
    for (int i = ln-1; i >= 0; i--)
    {
        for(int j = 0; j < bf[i]; j++)
        {
            ar[l] = i;
            l++;
        }
    }
}

void HeapSort(int* ar, size_t size, bool (*comp)(int, int))
{ 
for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(ar, size, i, comp);
    }
    for (int i = size-1; i >= 0; i--)
    {
        Swap(&ar[0], &ar[i]);
        heapify(ar, i, 0, comp);
    }
}

void heapify(int* arr, int n, int i, bool (*comp)(int, int))
{
    int largest = i;

    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && comp(arr[l], arr[largest]))
        largest = l;

    if (r < n && comp(arr[r], arr[largest]))
        largest = r;
    if (largest != i)
    {
        Swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest, comp);
    }
}

void Merge(int* A, int first, int last, bool (*comp)(int, int))
{
    int* mas = new int[100];
    int middle = (first + last) / 2;
    int start = first;
    int final = middle + 1;


    int j;
    for (j = first; j <= last; j++)
    {
        if ((start <= middle) && ((final > last) || (comp(A[final],A[start]))))
        {
            mas[j] = A[start];
            start++;
        }
        else
        {
            mas[j] = A[final];
            final++;
        }
    }
    for (j = first; j <= last; j++)
    {
        A[j] = mas[j];
    }
    delete[] mas;
}

void MergeSort(int* A, int first, int last, bool (*comp)(int, int))
{ 
  

    if (first < last)
    {
        MergeSort(A, first, (first + last) / 2, comp);
        MergeSort(A, (first + last) / 2 + 1, last, comp);
        Merge(A, first, last, comp);
    }
}

bool SortUp(int a, int b)
{
    if (a > b)
        return true;
    else
        return false;
}
bool SortDown(int a, int b)
{
    if (a < b)
        return true;
    else
        return false;
}

