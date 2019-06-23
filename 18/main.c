#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "solve.h"
#include "solve.c"
double f( double x)
{
    return 0.5*(25/x+x);
}
int main(void)
{
    int k;
    double t,x0,e,x;
    double (*ptr)(double);
    ptr=&f;
    printf("Input x0 and e:\n");
    if(scanf("%lf%lf",&x0,&e)!=2)
    {
        printf("Cannot read!\n");
        return 1;
    }
    t=clock();
    k=solve(x0,e,&x,ptr);
    t=(clock()-t)/CLOCKS_PER_SEC;
    printf("Chislo iteracii:%d\n",k);
    printf("Otvet:%.6f\n",x);
    printf("Nevyazka:%e\n",f(x));
    printf("Elapse time=%.2f\n",t);
    return 0;
}


