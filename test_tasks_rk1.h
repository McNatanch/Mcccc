#ifndef TEST_TASKS_RK1_H
#define TEST_TASKS_RK1_H

#include <iostream>
#include <bitset>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "tests.h"
#include "tasks_rk1.h"
void buildTree(int height, int shift, int rotate);

void SeparateFloat(float a, const char* fname);

int kolvo_raz(int a);

long long int GetMantissa(float a);

void ConvertDecToHex(int a, char* h);

char* convertBinToHex(const char* binNum);

void ChangeLSB(char* a);

char* reverse(char* buffer, int i, int j);

char* itoa(int value, char* buffer, int base);

void task_3();

void task_4();

void task_2();

void task_5();

void task_6();

#endif // TEST_TASKS_RK1_H
