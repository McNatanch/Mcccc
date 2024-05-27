#ifndef TESTS_H
#define TESTS_H

#include <iostream>

static void ShowInfoTest();

void Assert(bool expression);


void run_test(void (*test)(), const std::string& name_func);

void AssertArray(const char *array_in, const char *array_etalon, int size);

#endif // TESTS_H
