#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.h"
#include "solve.c"
double f (double x);
double f (double x)
{
    return x*x;
}
int main(void)
{
    double a,b,e,r;
    int k,n,res;
    double (*ptr)(double);
    ptr=&f;
    for(k=0;;k++)
    {
        printf("Input a and b,e:");
        if(scanf("%lf%lf%lf",&a,&b,&e)!=3)
        {
            printf("Cannot read!\n");
            return 1;
        }
        if (e<1e-16)
            break;
        res=solve(ptr,a,b,e,&r);
        printf("Otvet=%.2f n=%d\n",r,res);

    }
    return 0;
}
