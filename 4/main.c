#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.c"
#include "solve.h"
double f (double x);
double f (double x)
{
    return 1;
}
int main(void)
{
    double a,b,res;
    int k,n;
    double (*ptr)(double);
    ptr=&f;
    for(k=0;;k++)
    {
        printf("Input a and b,n:");
        if(scanf("%lf%lf%d",&a,&b,&n)!=3)
        {
            printf("Cannot read!\n");
            return 1;
        }
        if (n<0)
            break;
        res=solve(ptr,a,b,n);
        printf("Otvet:%e\n",res);

    }
    return 0;
}
