#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.h"
#include "solve.c"
double f (double x);
double f (double x)
{
    return 1/(x*x);
}
int main(void)
{
    double a,e,r,b;
    int k;
    double (*ptr)(double);
    ptr=&f;
    for(k=0;;k++)
    {
        printf("Input a and e:");
        if(scanf("%lf%lf",&a,&e)!=2)
        {
            printf("Cannot read!\n");
            return 1;
        }
        if (e<1e-16)
            break;
        b=solve(ptr,a,e,&r);
        printf("Otvet=%.2f b=%.2f\n",r,b);

    }
    return 0;
}
