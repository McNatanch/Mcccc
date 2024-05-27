#include "test_tasks_rk1.h"


void task_3()
{
    float a = 0;

    a = 178.125;
    long long int b = GetMantissa(a);
    Assert(b == 125);

    a = 123.45678;
    b = GetMantissa(a);
    Assert(b == 456779); //погрешность

    a = 111.99999;
    b = GetMantissa(a);
    Assert(b == 999992);
}

void task_4()
{
    int a = 178;
    char* bf = new char[32];

    ConvertDecToHex(a, bf);
    AssertArray(bf, "B2", 3);


    a = 37111;
    ConvertDecToHex(a, bf);
    AssertArray(bf, "90F7", 5);

    a = 55555;
    ConvertDecToHex(a, bf);
    AssertArray(bf, "D903", 5);
}

void task_2()
{
    float a = 125.178;
    char b[13] = "../test4.txt";

    SeparateFloat(a, b);

    FILE* f = fopen(b, "r");
    Assert(f != NULL);
}


void task_5()
{
    char a[17] = "1001000110101111";
    char* b = new char[17];

    b = convertBinToHex(a);
    AssertArray(b, "91AF", 5);

    char c[9] = "10110010";
    b = convertBinToHex(c);
    AssertArray(b, "B2", 3);

    char d[10]  = "101000001";
    b = convertBinToHex(d);
    AssertArray(b, "141", 4);
}

void task_6()
{
    char g[3] = "AB";
    lsbchange(g);
    AssertArray(g, "B\202", 3);
}
