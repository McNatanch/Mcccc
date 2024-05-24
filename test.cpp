#include "test.h"
#include <time.h>
#include <fstream>
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



void test_Sort ( void (*sort)(int* ,size_t , bool (*comp)(int, int)),  bool (*comp)(int, int) )
{
    int size = 100;
    int* ar = new int [size];

    for (int i = 0; i < size; i++)
    {
        ar[i] = rand()%201-100;
    }

    clock_t start = clock();
    sort(ar,size,comp);
    clock_t end = clock();
    double seconds1 = (double)(end-start) / CLOCKS_PER_SEC;
    delete [] ar;
    //======================

    size = 200;
     ar = new int [size];
    for (int i = 0; i < size; i++)
    {
       ar[i] = rand()%201-100;
    }
    start = clock();
    sort(ar,size,comp);
    end = clock();
    double seconds2 = (double)(end - start) / CLOCKS_PER_SEC;
    delete [] ar;
   //====================== 

    size = 300;
     ar = new int [size];
    for (int i = 0; i < size; i++)
    {
       ar[i] = rand()%201-100;
    }
    start = clock();
    sort(ar,size,comp);
    end = clock();
    double seconds3 = (double)(end - start) / CLOCKS_PER_SEC;
    delete [] ar;
    //====================

    size = 400;
     ar = new int [size];
    for (int i = 0; i < size; i++)
    {
       ar[i] = rand()%201-100;
    }
    start = clock();
    sort(ar,size,comp);
    end = clock();
    double seconds4 = (double)(end - start) / CLOCKS_PER_SEC;
    delete [] ar;
    //====================

    size = 500;
     ar = new int [size];
    for (int i = 0; i < size; i++)
    {
       ar[i] = rand()%201-100;
    }
    start = clock();
    sort(ar,size,comp);
    end = clock();
    double seconds5 = (double)(end - start) / CLOCKS_PER_SEC;
    delete [] ar;

    //======================

size = 600;
     ar = new int [size];
    for (int i = 0; i < size; i++)
    {
       ar[i] = rand()%201-100;
    }
    start = clock();
    sort(ar,size,comp);
    end = clock();
    double seconds6 = (double)(end - start) / CLOCKS_PER_SEC;
    delete [] ar;
//=====================

size = 700;
     ar = new int [size];
    for (int i = 0; i < size; i++)
    {
       ar[i] = rand()%201-100;
    }
    start = clock();
    sort(ar,size,comp);
    end = clock();
    double seconds7 = (double)(end - start) / CLOCKS_PER_SEC;
    delete [] ar;
//=====================

size = 800;
     ar = new int [size];
    for (int i = 0; i < size; i++)
    {
       ar[i] = rand()%201-100;
    }
    start = clock();
    sort(ar,size,comp);
    end = clock();
    double seconds8 = (double)(end - start) / CLOCKS_PER_SEC;
    delete [] ar;
//====================

    size = 900;
     ar = new int [size];
    for (int i = 0; i < size; i++)
    {
       ar[i] = rand()%201-100;
    }
    start = clock();
    sort(ar,size,comp);
    end = clock();
    double seconds9 = (double)(end - start) / CLOCKS_PER_SEC;
    delete [] ar;
//====================

size = 1000;
    ar = new int [size];
    for (int i = 0; i < size; i++)
    {
       ar[i] = rand()%201-100;
    }
    start = clock();
    sort(ar,size,comp);
    end = clock();
    double seconds10 = (double)(end - start) / CLOCKS_PER_SEC;
    delete [] ar;



    FILE* f = fopen("../SORT_TIME.txt", "w");

    fprintf(f,"QuickSort100\tQuickSort200\tQuickSort300\tQuickSort400\tQuickSort500\tQuickSort600\tQuickSort700\tQuickSort800\tQuickSort900\tQuickSort1000\n");
    fprintf(f,"%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",seconds1,seconds2,seconds3,seconds4,seconds5,seconds6,seconds7,seconds8,seconds9,seconds10);
    fclose(f);
}


void test_BubbleSort(int* ar, size_t size, bool (*comp)(int , int ))
{
    int arl = 50;
    int etalar[arl];
    srand(time(0));
    for (int i = 0; i < arl; i ++)
    {
        etalar[i] = rand()%201-100;
    }

    BubbleSort(etalar, arl, comp);
    if (IfSorted(etalar, arl, comp))
    {
        std::cout<<"Not Sorted"<<std::endl;
    }
    else
    {
        std::cout<<"Sorted"<<std::endl;
    }
}

void test_InsertionSort(int* ar, size_t size, bool (*comp)(int, int))
{
    int arl = 50;
    int etalar[arl];
    srand(time(0));
    for (int i = 0; i < arl; i ++)
    {
        etalar[i] = rand()%201-100;
    }

    InsertionSort(etalar,arl,comp);
    if (IfSorted(etalar, arl, comp))
    {
         std::cout<<"Not Sorted"<<std::endl;
    }  
    else
    {
        std::cout<<"Sorted"<<std::endl;
    } 
}

void test_SelectionSort(int* ar, size_t size, bool (*comp)(int, int))
  {
      	int arl = 50;
      	int etalar[arl];
      	srand(time(0));
      	for (int i = 0; i < arl; i ++)
     	{
          	etalar[i] = rand()%201-100;
      	}

        SelectionSort(etalar,arl,comp);
      	if (IfSorted(etalar, arl, comp))
     	{
           std::cout<<"Not Sorted"<<std::endl;
	}
      	else
      	{
          std::cout<<"Sorted"<<std::endl;
     	}
  }

void test_ShellSort(int* ar, size_t size, bool (*comp)(int, int))
  {
      	int arl = 50;
      	int etalar[arl];
      	srand(time(0));
      	for (int i = 0; i < arl; i ++)
     	{
          	etalar[i] = rand()%201-100;
      	}

        ShellSort(etalar,arl,comp);
      	if (IfSorted(etalar, arl, comp))
     	{
           std::cout<<"Not Sorted"<<std::endl;
	}
      	else
      	{
          std::cout<<"Sorted"<<std::endl;
     	}
  }

void test_MYSort(int* ar, size_t size, bool (*comp)(int, int))
  {
      	int arl = 50;
      	int etalar[arl];
      	srand(time(0));
      	for (int i = 0; i < arl; i ++)
     	{
          	etalar[i] = rand()%201-100;
      	}

        MYSort(etalar,arl,comp);
      	if (IfSorted(etalar, arl, comp))
     	{
           std::cout<<"Not Sorted"<<std::endl;
	}
      	else
      	{
          std::cout<<"Sorted"<<std::endl;
     	}
  }

void test_QuickSort(int* ar, size_t size, bool (*comp)(int, int))
  {
      	int arl = 50;
      	int etalar[arl];
      	srand(time(0));
      	for (int i = 0; i < arl; i ++)
     	{
          	etalar[i] = rand()%201-100;
      	}

        QuickSort(etalar, arl, comp);
      	if (IfSorted(etalar, arl, comp))
     	{
           std::cout<<"Not Sorted"<<std::endl;
	}
      	else
      	{
          std::cout<<"Sorted"<<std::endl;
     	}
  }

void test_QuickSortMod(int* ar, size_t size, bool (*comp)(int, int))
  {
      	int arl = 50;
      	int etalar[arl];
      	srand(time(0));
      	for (int i = 0; i < arl; i ++)
     	{
          	etalar[i] = rand()%201-100;
      	}

        QuickSortMod(etalar, arl, comp);
      	if (IfSorted(etalar, arl, comp))
     	{
           std::cout<<"Not Sorted"<<std::endl;
	}
      	else
      	{
          std::cout<<"Sorted"<<std::endl;
     	}
  }

void test_CountSort(int* ar, size_t size, bool (*comp)(int, int))
  {
      	int arl = 50;
      	int etalar[arl];
      	srand(time(0));
      	for (int i = 0; i < arl; i ++)
     	{
          	etalar[i] = rand()%201-100;
      	}

        CountSort(etalar,arl,comp);
      	if (IfSorted(etalar, arl, comp))
     	{
           std::cout<<"Not Sorted"<<std::endl;
	}
      	else
      	{
          std::cout<<"Sorted"<<std::endl;
     	}
  }

void test_HeapSort(int* ar, size_t size, bool (*comp)(int, int))
  {
      	int arl = 50;
      	int etalar[arl];
      	srand(time(0));
      	for (int i = 0; i < arl; i ++)
     	{
          	etalar[i] = rand()%201-100;
      	}

        HeapSort(etalar,arl,comp);
      	if (IfSorted(etalar, arl, comp))
     	{
           std::cout<<"Not Sorted"<<std::endl;
	}
      	else
      	{
          std::cout<<"Sorted"<<std::endl;
     	}
  }

void test_MergeSort(int* ar,int first, size_t size, bool (*comp)(int, int))
  {
      	int arl = 50;
      	int etalar[arl];
      	srand(time(0));
      	for (int i = 0; i < arl; i ++)
     	{
          	etalar[i] = rand()%201-100;
      	}

        MergeSort(etalar,first,arl,comp);
      	if (IfSorted(etalar, arl, comp))
     	{
           std::cout<<"Not Sorted"<<std::endl;
	}
      	else
      	{
          std::cout<<"Sorted"<<std::endl;
     	}
  }
