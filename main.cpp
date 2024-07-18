#include<iostream>
int MAX = 100;
#include<fstream>
#define SET_BIT(number, bit)((number | (1 << bit))

#define RESET_BIT(number, bit)(number & ~(1 << bit))

#include<cstring>
using namespace std;

//Here I declare all variable, arrays and all the shit needed for the code
long long int a1 = 0x0101010202030408;
unsigned short a2 = 0xFF01;
const unsigned int ar3[3] = {0x01020109, 0x07890909, 0x8899AABB};
const int ar4[3] = {0x01020109, 0x07890909, 0x07890909};
size_t size3 = 3;

//SW_1111111111111111111111111
int CountSimilarBytes(long long int byte);

void SwapBytes(unsigned short* b);

unsigned char GetMaxByte(const unsigned int* ar, size_t size);
//SW_2222222222222222222222222
int CountEl(const int* ar, int size, int num_bit);

void ShiftNumber( int* element, int countShiftBit, bool left = true);

void SwapTetrad(char* number);
//SW_33333333333333333333333333333
int GetNumberWithMaxBits(const int* number, size_t size);
void SortWithFile(const char* file_name);

int ProcessKeys(const char* key);
int main(int argc, char** argv)
{
   
   for (int i = 0; i < argc; i++)
   {
       if (i == 0)
       {

       }
       else
       {
            int code = ProcessKeys(argv[i]);
            if (code == -1)
            {
                cout << "kakayato hueta" << endl;
            }
            else
            {
                cout << "da vrode norm" << endl;
            }
       }
   }
     return 0;
}

int ProcessKeys(const char* key)
{
    int N = key[3] - '0';
    int K = key[5] - '0';
    if (key[0] != 'S' || key[1] != 'W' || key[2] != '_' || key[4] != '_')
    {
        return -1;
    }
    else
    {
        switch (N)
        {
        case 1:

            switch (K)
            {
            case 1:
                cout << "CountSimilarBytes" << CountSimilarBytes(a1) << endl;
                break;

            case 2:
                cout << "SwapBytes" << endl;
                SwapBytes(&a2);
                break;

            case 3:
                cout << "GetMaxByte" << GetMaxByte(ar3, size3) << endl;
                break;
            }
            break;

        case 2:

            switch (K)
            {
            case 1:
            {
                int a5 = 1;
                a5 = RESET_BIT(a5,2);
                break;
            }
            case 2:
            {
                cout << "CountEl" << CountEl(ar4,size3, 2) << endl;
                break;
            }
            case 3:
            {
                int a0 = 0x00000001;
                ShiftNumber(&a0,5);
                cout << "ShiftNumber" << endl;
                break;
            }
            case 4:
            {
                cout << "SwapTetrad" << endl;
                char a4 = 0xA7;
                SwapTetrad(&a4);
                break;
            }
            }
            break;
        case 3:

            switch (K)
            {
            case 2:
            {
                cout << GetNumberWithMaxBits(ar4,3) << "bits has the number with most bits in it"<<  endl;
                break;
            }
            case 3:
            {
                char a[MAX];
                cout << "Enter the file_name: ";
                cin >> a;
                SortWithFile(a);
                break;
            }
            }

        }
    }
    return 0;
}
void BubbleSort(int* M, size_t size) {
    bool done;
    for(int i=size-1; i>0; i--) {
        // отмечает, завершена ли сортировка
        // на данном проходе внешнего цикла
        done = true;
        for(int j=0; j<i; j++) {
            if (M[j] > M[j+1]) {
                done = false;
                swap(M[j], M[j+1]);
            }
        }

        if (done) break; // если сортировка уже завершена
    }
}

void SelectionSort(int* M, size_t size)
{
    do
        {
            int indmax = 0;
            for (int i = 0; i < size; i++)
            {
                if (M[i] >M[indmax])
                {
                    indmax = i;
                }
            }
            swap(M[indmax],M[size-1]);
            size--;
        }while(size > 1);
}

void SortWithFile(const char* file_name)
{
    __func__;
    char HowToSort[MAX];
    char str[MAX];

    FILE* f;
    f = fopen(file_name, "r");
    fgets(str, MAX, f);
    fgets(HowToSort, MAX, f);
    fclose(f);

    int k = 1;
    for (int i = 0; str[i] != '\n'; i++)
        if (str[i] == ' ' || str[i] == '\n')
            k++;

    int* ar = new int[k];
    for (int i = 0; i < k; i++)
        ar[i] = 0;

    int i = 0;
    int a = 0;
    while (str[i] != '\n')
    {
        if (str[i] == ' ' || str[i] == '\n')
        {
            a++;
        }
        else
        {
            ar[a] = ar[a] * 10 + (str[i] - '0');
        }
        i++;
    }

    if (strcmp(HowToSort, "BubbleSort") == 0)
        BubbleSort(ar, k);


    else if(strcmp(HowToSort, "SelectionSort") == 0)
        BubbleSort(ar, k);
    f = fopen ("../res_sort.txt", "w");

    for (int i = 0; i < k; i ++)
        fprintf(f, "%d ", ar[i]);

    fclose(f);
}

int TellHowMany (int number)
{
    int count = 0;
    int mask = 1;
    for (int i = 0; i < 8; i++)
    {
        if (number & mask)
        {
            count++;
        }
        mask = mask << 1;
    }
    return count;
}

int GetNumberWithMaxBits(const int* number, size_t size)
{

    __func__;
    int max = 0;
    int current = 0;
    for (unsigned i = 0; i < size; i++)
    {
        if (number[i] > 0)
        {
            current = TellHowMany(number[i]);
        }
        if (current > max)
        {
            max = current;
        }
    }
    return max;
}

//SW1111111111111111111111111111111111111

int CountSimilarBytes(long long int byte)
{
    __func__;
    int maxCount = 0;
    int currentCount = 0;
    int prevByte = -1;

    for (int i = 0; i < sizeof(long long int); ++i) {
        int currentByte = (byte >> (8 * i)) & 0xFF;
        if (currentByte != 0xFF && currentByte != 0x00) {
            if (currentByte == prevByte) {
                currentCount++;
            } else {
                currentCount = 1;
            }
            if (currentCount > maxCount) {
                maxCount = currentCount;
            }
        }
        prevByte = currentByte;
    }

    return maxCount;
}

void SwapBytes(unsigned short* b)
{
    __func__;
    unsigned short bf = (*b << 4*6 >> 4*6);
    *b = *b + ~bf + 1;
    *b = (*b >> 4*2);
    *b = *b + (bf << 4*2);
}

unsigned char GetMaxByte(const unsigned int* ar, size_t size)
{
    __func__;
    unsigned char maxByte = 0;
    for (size_t i = 0; i < size; ++i) {
        const unsigned char* bytePtr = reinterpret_cast<const unsigned char*>(&ar[i]);
        for (size_t j = 0; j < sizeof(unsigned int); ++j) {
            if (bytePtr[j] > maxByte) {
                maxByte = bytePtr[j];
            }
        }
    }
    return maxByte;
}

//SW222222222222222222222222222222222222222222222222222222

void ShiftNumber(int* element, int countShiftBit, bool left)
{
    __func__;
    unsigned* p = (unsigned*)element;
    int greatest_bit_mask = (1 << 31);
    bool ifcarry;

    if(left)
    {
        for (int i = 0; i < countShiftBit; i++)
        {
            ifcarry = (*p & greatest_bit_mask);
            *p = *p << 1;
            if (ifcarry)
            {
                *p |= 1;
            }
        }
    }

    else
    {
        for (int i = 0; i < countShiftBit; i++)
        {
            ifcarry = *p & 1;
            *p = *p >> 1;
            if (ifcarry)
            {
                *p |= greatest_bit_mask;
            }
        }
    }
}

int CountEl(const int* ar, int size, int num_bit)
{
    __func__;
    int result = 0;
    int mask = 1 << num_bit;

    for (int i = 0; i < size; i++)
    {
        if(ar[i] & mask != 0)
        {
            result++;
        }
    }

    return result;
}

void SwapTetrad(char* number)
{
    __func__;
    unsigned char* p = (unsigned char*)number;

    unsigned char save = *p & 0b00001111;
    *p = *p >> 4;
    save = save << 4;
    *p |= save;
}
