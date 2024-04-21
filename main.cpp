//Напишем функцию, именно функцию, которая сбрасывает/устанавливает n-ый бит в числе
#include <iostream>

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

    int num = 27;
    printf("%X\n", num);
    Set_bit(&num,2);
    printf("%X\n", num);

    printf("%d\n", num);
    return 0;
}

void Drop_bit (int* a, int n)
{
    int copy = (*a);
    copy = copy << 32 - n;
    copy = copy >> 32 - n;

    (*a) = (*a) >> n - 1;
}
