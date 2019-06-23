#include <stdio.h>
#include <stdlib.h>
#include "solve.h"
double solve (double (*f)(double),double a,double b,int n)
{
    double h=(b-a)/n,fa=(*f)(a)/2,fb=(*f)(b)/2,xk=a,fxk,sn=fa+fb;
    int k;
    for (k=1;k<n;k++)
    {
        xk+=h;
        fxk=(*f)(xk);
        sn+=fxk;

    }
    return h*sn;
}
