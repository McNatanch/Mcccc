#include "sorts.h"


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

void ShellSort(int* ar, size_t size, bool (*comp)(int, int))
{
    do
    {
        for (int j = 5; j > 0; j--)
        {
            for (int i = 0; i < size - 1; i = i + j)
            {
                if (i+j > size-1)
                {
                    break;
                }
                else
                {
                    if (comp(ar[i],ar[i+j]))
                    {
                        Swap(&ar[i], &ar[i+j]);
                    }
                }
            }
        }
    }while(IfSorted(ar,size,comp));
}

bool IfSorted (int* ar, size_t size, bool (*comp)(int, int))
{
    for (int i = 0; i < size-1; i++)
    {
        if(!comp(ar[i+1], ar[i]))
        {
            return 1;
        }
    }
    return 0;
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
            if (comp(ar[i],space))//<--- DIFFERENCE HERE
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
