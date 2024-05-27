#include "tasks_rk1.h"

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
	{
		printf(" ");
	}
	for (int i = 0; i < (2*a + 1); i++)
	{
		printf("*");
	}
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

union type
{
    float f;
    int i;
};



char reverse(char a)
{
    char b = 0;
    for(int i = 0; i < (sizeof(char)*8); i++)
    {
        b = (b<<1)|(a&1);
        a = a>>1;
    }
    return b;
}

void lsbchange(char* a)
{
    int l = 0;
    while(a[l] != '\0')
    {
        l ++;

    }

    for(int i = 0; i < l/2; i ++)
    {
        char bf =a[i];
        a[i] = reverse(a[l-i-1]);
        a[l-i-1] = reverse(bf);

    }
    a[l] = '\0';

}


char* convertBinToHex(const char* binNum)
{
    int n = strlen(binNum);
    char* g = new char [(n / 4) + 1];
    for (int i = n - 1; i >= 0; i -= 4)
    {
        int a = 0;
        char t;
        for(int j = 0; j < 4; j++)
        {
            if(i - j < 0)
                t = '0';
            else
                t = binNum[i - j];
            a += (atoi(&t)) * (std::pow(2, j));
        }
        if(a > 9)
            t = 'A' + (a - 10);
        else
            t = '0' + (a);
        g[(n - i - 1) / 4] = t;
        g[1 + (n - i - 1) / 4] = '\0';
    }
    for(int i = 0; i < (strlen(g)) / 2; i++)
        std::swap(g[i], g[strlen(g) - 1 - i]);
    return g;
}

void ConvertDecToHex(int d, char* h)
{
    bool hell = false;
    int bf;
    if(d < 0)
    {
        d = abs(d);
        hell = true;
    }
    char st[17] = "0123456789ABCDEF";
    int i = 7;
    do
    {
        h[i] = st[d % 16];
        d /= 16;
        i--;
    }while(i > -1);
    if(h[0] == '0')
    {
        for(int j = 0; j < 8; j++)
        {
            if(h[j] != '0' && hell == false)
            {
                for(int t = j; t < strlen(h) + 1; t++)
                {
                    h[t - j] = h[t];
                }
                break;
            }
            if(h[j] != '0' && hell == true)
            {
                h[0] = '-';
                for(int t = j; t < strlen(h) + 1; t++)
                {
                    h[t - j + 1] = h[t];
                }
                break;

             }
        }
    } else if(hell)
    {
        for(int t = strlen(h) + 1; t > -1; t--)
        {
            h[t + 1] = h[t];
        }
        h[0] = '-';
    }


}

long long int GetMantissa(float n)
{
    long long int a = 0;
    char* boof = new char[32];
    sprintf(boof, "%f", n);

    int k = 0;
    for(int i = 0; i < strlen(boof); i++)
    {
        if(boof[i] == '.')
        {
            k = strlen(boof) - i;
            for(int j = i + 1; j < strlen(boof) + i; j++)
            {
                boof[j - i - 1] = boof[j];
            }
            i = 1000;
        }
    }
    a = atoi(boof);
    while(a % 10 == 0)
    {
        a /= 10;
    }
    return a;
}


char* reverse1(char* buffer, int i, int j) {
  while (i < j) {
    char t = buffer[i];
    buffer[i++] = buffer[j];
    buffer[j--] = t;
  }

  return buffer;
}

char* itoa1(int value, char* buffer, int base) {
  if (base < 2 || base > 32) return NULL;

  int n = abs(value);
  int i = 0;

  do {
    int r = n % base;
    buffer[i++] = (r < 10) ? (r + '0') : (r - 10 + 'A');
    n /= base;
  } while (n);

  if (value < 0 && base == 10) buffer[i++] = '-';
  buffer[i] = '\0';

  return reverse1(buffer, 0, i - 1);
}

void SeparateFloat(float a, const char* fname)
{

    type b;
    b.f = a;
    char degree = (b.i << 1 >> 24);
    int mantissa = (b.i << 9 >> 9);
    char c[30];
    char c1[30];
    itoa1(1, c, 16);
    itoa1(1, c1, 2);
    FILE* f = fopen(fname, "w");
    if(!f)
        std::cout << "File could not be opened" << std::endl;
    fprintf(f, "%f\n", a);
    fprintf(f, "%s\t%s\n", c, c1);
    itoa1(degree, c, 16);
    itoa1(degree, c1, 2);
    fprintf(f, "%s \t %s \n", c, c1);
    itoa1(mantissa, c, 16);
    itoa1(mantissa, c1, 2);
    fprintf(f, "%s \t %s \n", c, c1);
    fclose(f);
}

