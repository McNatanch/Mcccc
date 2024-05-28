#include "hw2.h"

void params::parameters_IO(int argc, char** argv)
{
    for(int i = 1; i<argc; i++)
    {
        char temp_string [64] = "";
        switch(argv[i][1])
        {

        case 'i':{
            for(int j = 3; argv[i][j] != '\0'; j++)
            {
                inputFile[j-3] = argv[i][j];
            }
            break;
        }
        case 'o':
        {
            for(int j = 3; argv[i][j] != '\0'; j++)
            {
                outputFile[j-3] = argv[i][j];
            }
            break;
        }
        case 'w':
        {
            for(int j = 3; argv[i][j] != '\0'; j++)
            {
                temp_string[j-3] = argv[i][j];
            }
            w = std::atoi(temp_string);
            break;
        }
        case 'l':{
            for(int j = 3; argv[i][j] != '\0'; j++)
            {
                temp_string[j-3] = argv[i][j];
            }
            coloumns = std::atoi(temp_string);
            break;
        }
        case 'f':
        {
            for(int j = 3; argv[i][j] != '\0'; j++)
            {
                temp_string[j-3] = argv[i][j];
            }

            if (strcmp(temp_string, "moving_average"))
            {
                IfSync = true;
            }
            if (!strcmp(temp_string, "moving_average"))
            {
                IfSync = true;
            }
                   
            break;
        }
        case 'c':
        {
            int k = 1;
            for(int n = 3; n < strlen(argv[i]); n++)
            {
                strcpy(temp_string, "");
                for(int j = 0; argv[i][n] != ',' && n < strlen(argv[i]); n++, j++)
                {
                    temp_string[j] = argv[i][n];
                }
                c[k++] = std::atoi(temp_string);
                c[0] = k;
            }
        }
        }
    }
}

void FileData::normalise()
{
    minMax();
    float space = max - min;
    for(int i = 0 ; i < ln; i++)
    {
        if(i%coloumns != 0)
        {
            ar[i] = ((ar[i] - min)/space)*1000;
        }
    }
}

params::params()
{
    c[0] = 1;
    for(int i = 1; i < 128; i++)
    {
        c[i] = 0;
    }
}

void params::print_params()
{
    std::cout<<"Input data file: "<<inputFile<<std::endl;
    std::cout<<"Output data file: "<<outputFile<<std::endl;
    std::cout<<"Filter with: ";
    if (IfSync)
    {
        std::cout<<"synchronising filtering";
    }    
    if (!IfSync)
    {
        std::cout<<"moving average filtering";
    }
    std::cout<<""<<std::endl;
    std::cout<<"Filter width: "<<w<<std::endl;
    std::cout<<"Filtered coloumns: ";
    for(int i = 1; i < c[0]; i++)
    {
        std::cout<<c[i];
        if(i + 1 != c[0])
        {
            std::cout<<", ";
        }
    }
    std::cout<<std::endl;
    std::cout<<"Number of coloumns total: "<<coloumns<<std::endl;
    std::cout<<"Time consumed: "<<time<<" s"<<std::endl;
}

FileData::FileData()
{
    c[0] = 1;
    for(int i = 1; i < 128; i++)
    {
        c[i] = 0;
    }
    ar = (int*)malloc(sizeof(int)*1000000);
}

FileData::~FileData()
{
    delete [] ar;
}

void FileData::filter(int argc, char** argv)
{
    clock_t start = clock();
    parameters_IO(argc, argv);
    getData();
    normalise();
    IfSync ? synchronized() : moving_average();
    sendData();
    clock_t end = clock();
    time = (double)(end-start) / CLOCKS_PER_SEC;
    print_params();
    return;
}

void FileData::getData()
{   //inputFile
    FILE* f = fopen(inputFile, "r");
    if(f == nullptr)
    {
        return;
    }
    for(char ch = ' '; !feof(f); ln++)
    {
        fscanf(f, "%d%c", &ar[ln], &ch);
    }
    ln--;
    fclose(f);
    return;
}

void FileData::sendData()
{   //outputFile
    FILE* f = fopen(outputFile, "w");
    if(f == nullptr)
    {
        return;
    }
    for(int i = 0; i < ln/coloumns; i++)
    {
        for(int j = 0; j < coloumns; j++)
        {
            fprintf(f, "%d\t", ar[i * coloumns + j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void FileData::moving_average()
{
    for(int i = 1; i < c[0]; i++)
    {
        for(int j = c[i]; j < ln; j += coloumns)
        {
            for(int k = 0; k < w; k++)
            {
                if(j/coloumns < w || j + w*coloumns > ln)
                {
                    ar[j] = 0;
                }
                else
                {
                    int sum = 0;
                    for(int k = 0; k <= 2*w; k++)
                    {
                        sum += ar[j + w*coloumns - k*coloumns];
                    }
                    ar[j] = sum/(2*w + 1);
                }
            }
        }
    }
}

void FileData::synchronized()
{
    for(int k = 1; k < c[0]; k++)
    {
        for(int i = 1; i < ln; i += coloumns)
        {
            int sum = 0;
            for(int j = 0; j < ln/w; j++)
            {
              sum += ar[i + j * w];
            }
            ar[i] = sum/(ln/(w * coloumns));
        }
        for(int i = w * coloumns; i < ln; i++)
        {
            if(i%coloumns != 0)
            {
                ar[i] = 0;
            }
        }
    }
}

void FileData::minMax()
{
    for(int i = 0; i < ln; i++)
    {
        if(ar[i] > max && i%coloumns != 0)
        {
            max = ar[i];
        }
        if(ar[i] < min && i%coloumns != 0)
        {
            min = ar[i];
        }
    }
}
