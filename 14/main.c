#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "solve.h"
#include "solve.c"
double f( double x)
{
    return x*x;
}
double d( double x)
{
    return 2*x;
}
int main(void)
{
    int k;
    double t,x0,e,x;
    double (*ptr1)(double);
    double (*ptr2)(double);
    ptr1=&f;
    ptr2=&d;
    printf("Input x0 and e:\n");
    if(scanf("%lf%lf",&x0,&e)!=2)
    {
        printf("Cannot read!\n");
        return 1;
    }
    t=clock();
    k=solve(x0,e,&x,ptr1,ptr2);
    t=(clock()-t)/CLOCKS_PER_SEC;
    if (k>=0)
    {
        printf("Chislo iteracii:%d\n",k);
        printf("Otvet:%.6f\n",x);
        printf("Nevyazka:%e\n",f(x));
        printf("Elapse time=%.2f\n",t);
    } else printf("Metod neprimenim");
    return 0;
}


