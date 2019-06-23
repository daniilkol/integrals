#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.h"
#define MAX_IT 1000
int solve(double (*f)(double),double a,double b,double e,double *r)
{
    int n=10,it,i;
    double sn=(*f)(a)/2+(*f)(b)/2,s2n=0,h=(b-a)/n;
    for(i=1;i<n;i++)
    {
        sn+=h*(*f)(a+i*h);
    }
    for(it=0;it<MAX_IT;it++)
    {
        h=(b-a)/n;
        s2n=0;
        for(i=1;i<=n;i++)
        {
            s2n+=(h*(*f)(a+(2*i-1)*h/2))/2;
        }
        if(fabs(sn/2-s2n)<e)
        {
         *r=sn/2+s2n;
         return n;
        }
        n*=2;
        sn=sn/2+s2n;

    }
    return -1;
}
