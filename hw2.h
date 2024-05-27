#ifndef hw_2_H
#define hw_2_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <math.h>
#include <chrono>
#include <time.h>

class params
{

public:
    char inputFile [64] = "";
    char outputFile [64] = "";
    bool IfSync = true;
    int w = 0;
    int c [128];
    int coloumns = 17;
    double time = 0;

protected:
    void print_params();
    void parameters_IO(int argc, char** argv);

public:
    params();

};

class FileData : public params
{
public:
    int* ar;
    int ln = 0;
    float min = 10000000;
    float max = 1;

public:
    FileData();
    ~FileData();
    void filter(int argc, char** argv);

protected:
    void getData();
    void sendData();
    void normalise();

private:
    void moving_average();
    void synchronized();
    void minMax();

};
#endif
