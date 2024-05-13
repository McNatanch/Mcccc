#include <iostream>

void print_space(int a)
{
for (int i = 0; i < a; i++)
{
printf(" ");
}
}

void print_star(int a)
{
for (int i = 0; i < a; i++)
{
printf("*");
}
}

void BuildLeft(int ht, int sh)
{
int check = ht - sh;
if (check < 0)
{
check = 0;
}

for (int i = 0; i < ht - 1; i++)
{
print_space(sh-i-1+check);
print_star(i+1);
printf("\n");
}
print_space(sh-ht+check); print_star(ht); printf("\n");
for (int i = 0; i < ht - 1; i++)
{
print_space(sh-ht+1+i+check);
print_star(ht-1-i);
printf("\n");
}

}

void print_row_down(int a, int sh1, int check, int ht1)
{
for (int i = 0; i < sh1-ht1+1+a-check; i++)
{
printf(" ");
}
for (int i = 0; i < 2*ht1 - 1 - 2*a; i++)
{
printf("*");
}
printf("\n");
}

void BuildDown(int ht, int sh)
{
int a = sh - ht;
if (a > 1)
{
a = 0;
}
for (int i = 0; i < ht; i++)
{
print_row_down(i,sh,a,ht);
}
}

void BuildRight(int hg, int sh)
{
int help = hg - 1;
for (int i = 1; i < hg; i++)
{
print_space(sh);
print_star(i);
printf("\n");
}
print_space(sh); print_star(hg); printf("\n");


for (int i = 0; i < (hg - 1); i++)
{
print_space(sh);
print_star(help);
help = help - 1;
printf("\n");
}
}

void print_row1(int a, int sh1, int check)
{
for (int i = 0; i < sh1-1-a-check; i++)
printf(" ");
for (int i = 0; i < (2*a + 1); i++)
printf("*");
printf("\n");
}

void BuildUp(int ht, int sh)
{
int a = sh - ht;
if (a > 1)
{
a = 0;
}
for (int i = 0; i < ht; i++)
{
print_row1(i, sh, a);
}
}

void buildTree(int height, int shift, int rotate)
{
    if ((rotate % 360) == 0)
    {
        BuildUp(height,shift);
    }
    else if(((rotate-90) % 360) == 0)
    {
        BuildRight(height, shift);
    }
    else if(((rotate-180) % 360) == 0)
    {
        BuildDown(height,shift);
    }
    else if(((rotate+90) % 360) == 0)
    {
        BuildLeft(height,shift);
    }
}


int main()



{
    buildTree(5,5,360);
    return 0;
}

