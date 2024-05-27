#include <chrono>
#include <iostream>
#include "test.h"
#include <time.h>
#include "hw2.h"

using namespace std;


int main(int argc, char** argv){
    FileData params;

    params.filter(argc, argv);

    return 0;
}
