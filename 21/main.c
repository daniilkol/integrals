#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "solve.h"
#include "solve.c"
double f( double x)
{
    return sin(x);
}
int main(void)
{
    int k;
    double t,a,b,e,x;
    double (*ptr)(double);
    ptr=&f;
    printf("Input a and b,e:\n");
    if(scanf("%lf%lf%lf",&a,&b,&e)!=3)
    {
        printf("Cannot read!\n");
        return 1;
    }
    t=clock();
    k=solve(a,b,e,&x,ptr);
    t=(clock()-t)/CLOCKS_PER_SEC;
    if(k>=0)
    {
        printf("Chislo iteracii:%d\n",k);
        printf("Otvet:%.6f\n",x);
        printf("Elapse time=%.2f\n",t);
    } else printf ("Metod neprimenim");
    return 0;
}


