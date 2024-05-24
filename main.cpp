#include <chrono>
#include <iostream>
#include "test.h"
#include <time.h>
using namespace std;
#define SET_BIT(number, bit)((number) |= (1 << n-1))

#define RESET_BIT(number, bit)((number) &= (~(1<n-1)))



int main()
{

 //   std::cout<<__func__<<std::endl;
    bool (*comp)(int, int);
    comp = SortDown;
    test_Sort(QuickSort,comp);

 

 
 


 

     return 0;
}
