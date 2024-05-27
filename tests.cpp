#include "tests.h"

int num_test = 1;

static void ShowInfoTest() {
    std::cout << "\tTest " << num_test++ << " - ";
}

void Assert(bool expression) {
    ShowInfoTest();
    if (expression == true) {
        std::cout << " OK";
    }
    else {
        std::cout << " BAD";
    }
    std::cout << std::endl;
}

void run_test(void (*test)(), const std::string& nfunc) {
    std::cout << "Testing  " << nfunc << std::endl;
    num_test = 1;
    test();
    std::cout << "Finished testing\n\n" << std::endl;
}

void AssertArray(const char *array_in, const char *array_etalon, int size) {
    ShowInfoTest();

    for (int i = 0; i < size; i++) {
        if (array_in[i] != array_etalon[i]) {
            std::cout << " FAIL";
            std::cout << std::endl;
            return;
        }
    }
    std::cout << " OK" << std::endl;
}
