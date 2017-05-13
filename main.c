#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Task author: Anna Fabijańska
// Program author: Jakub Czaja

// Task: 
	// program finding zero of a function between a and b with e accuracy using bisection method
	// a, b and e are main() function arguments
	// exceptions handling


int float_check(const char *, int);
float bisection(float , float, float);
float f(float);
float mod(float);

float f(float x)
{
    return x*x+4-15*x;
}

int float_check(const char *num, int l)
{
	char a[l];
	--l;
	strcpy(a, num);
    char *l1;
    strtod(a, &l1);
    l1 -= a;
    if(l1 == l)
    	return 1;
    else
    	return 0;
}

float bisection(float a, float b, float e)
{
    float x1 = (a + b)/2;

    if(mod(a - b) < e)
        return x1;


    if(f(x1)*f(a) <= 0) return bisection(a, x1, e);
    if(f(x1)*f(b) <= 0) return bisection(x1, b, e);
    else
    {
        printf("SDGDSGH");
        exit(44);
    }
}

float mod(float a)
{
    if (a < 0)
        return -a;
    return a;
}

int main(int argc, char **argv)
{
    int i;
    if(argc != 4)
    {
    	printf("%d", argc);
        printf("wrong number of arguments");
        exit(-1);
    }

    for(i = 1; i < 4; ++i)
    {
        if(!float_check(*(argv + i), 1 + strlen(*(argv + i))))
        {
            printf("argument nr %d isn't a number", i);
            exit(55);
        }
    }

    float a = atof(argv[1]);
    float b = atof(argv[2]);
    float e = atof(argv[3]);

    if((f(a)*f(b)) > 0)
    {
        printf("wrong function arguments");
        exit(65);
    }

    if((f((a - b)/2) == 0))
        printf("Zero of a function: %f", (a - b)/2);
    else
        printf("Zero of a function: %f", bisection(a, b, e));
    printf("Hello world!\n");
    return 0;
}
