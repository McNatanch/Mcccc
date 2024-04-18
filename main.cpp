#include <iostream>
#define HOW

#define SET_BIT(number, bit)((number) * (bit))

int CountEl(const int* ar, int size, int num_bit);
bool shit (int a, int num_bit1);

void ShiftNumber(int* element, int countShiftBit, bool left = true);

void SwapTetrad(unsigned char *number);
//Работает почти все
int main()
{



    return 0;
}

int CountEl(const int* ar, int size, int num_bit)
{
    int amount = 0;
    for (int i = 0; i < size; i++)
    {
        if (shit(ar[i],num_bit))
        {
            amount++;
        }
    }

    return amount;
}

bool shit (int a, int num_bit1)
{
    a = a >> num_bit1;
    a &= 1;

    return a;
}

void ShiftNumber(int* element, int countShiftBit, bool left)
{
    if (left)
    {
        int a = (*element);
        a = a >> (32 - countShiftBit);
        //a = a & 0xF;

        (*element) = (*element) << countShiftBit;

        (*element) = (*element) | a;
    }
    else
    {
        int a = (*element);
        a = a << (32 - countShiftBit);
        (*element) = (*element) >> countShiftBit;

        (*element) = (*element) | a;
    }
}

void SwapTetrad(unsigned char* number)
{
    unsigned char a = (*number) & 0b1111;
    (*number) = (*number) >> 4;
    a = a << 4;
    (*number) = (*number) | a;
}


//void ShiftNumber1(int* element, int countShiftBit, bool left)
//{
//    if (left)
//    {
//это короче Нагайцев предложил,но тут тоже не работает полностью, поставьте ему за это -
//    }
//    else
//    {
//        int temp = (*element) & 0b11;
//        (*element) = (*element) >> countShiftBit;

//        (*element) &= ~(0b11 >> 32 - countShiftBit);
//        (*element) |= temp << 32 - countShiftBit;
//    }
//}
