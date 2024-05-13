//Напишем функцию, именно функцию, которая сбрасывает/устанавливает n-ый бит в числе
#include <chrono>
#include <iostream>
#include "sorts.cpp"
#define SET_BIT(number, bit)((number) |= (1 << n-1))

#define RESET_BIT(number, bit)((number) &= (~(1<n-1)))


//сброс бита
//void Set_bit (int* a, int n)
//{
//    int copy = (*a);
//    copy = copy << 32 - n;
//    copy = copy >> 32 - n;

//    (*a) = (*a) >> n - 1;
//    (*a) |= 1;
//    (*a) = (*a) << n - 1;

//    (*a) |= copy;
//}

void Set_bit (int* a, int n)
{
    (*a) |= (1 << n-1);
}



int main()
{

    bool (*comp)(int, int);
    comp = SortUp;
    int ar1[30];
size_t size1 = 30;
for (int i = 0; i < size1; i++)
{
ar1[i] = rand()%201-100;
}

auto start_time = chrono::steady_clock::now();
InsertionSort(ar1,size1,comp);
auto end_time = std::chrono::steady_clock::now();
std::cout « chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() « std::endl;
    return 0;
}

void Drop_bit (int* a, int n)
{
    int copy = (*a);
    copy = copy << 32 - n;
    copy = copy >> 32 - n;

    (*a) = (*a) >> n - 1;
}
