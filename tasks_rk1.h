#include <iostream>
#include <ostream>
#include <cmath>
#include <cstdint>
#include <bitset>
#include <sstream>
#include <string.h>
#include <string>
#include <cstring>

void print_space(int a);

void print_star(int a);

void BuildLeft(int ht, int sh);

void print_row_down(int a, int sh1, int check, int ht1);

void BuildDown(int ht, int sh);

void BuildRight(int hg, int sh);

void print_row1(int a, int sh1, int check);

void BuildUp(int ht, int sh);

void buildTree(int height, int shift, int rotate);

void SeparateFloat(float a, const char* fname);

long long int GetMantissa(float a);

void ConvertDecToHex(int a, char* h);

char* convertBinToHex(const char* binNum);

int kolvo_raz(int a);

void lsbchange(char* a);

char* reverse1(char* buffer, int i, int j);

char* itoa1(int value, char* buffer, int base);

char reverse(char a);
