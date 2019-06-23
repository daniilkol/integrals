#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.h"
double sgnn (double x);
double sgnn (double x)
{
    if (x>=0)
        return x;
    else return -x;
}

double solve (double (*f)(double),double a,double b,int n)
{
    double h=(b-a)/n,fxk0,fxk1,xk0=a,xk1=a+h,sn=0;
    int k;
    fxk0=(*f)(xk0);
    fxk1=(*f)(xk1);
    for (k=0;k<n;k++)
    {
        sn+=fxk1*((fabs(xk1)*sqrt(fabs(xk1))-fabs(xk0)*sqrt(fabs(xk0)))/3 - xk0*(sgnn(xk1)*sqrt(fabs(xk1))-sgnn(xk0)*sqrt(fabs(xk0))))+fxk0*((fabs(xk0)*sqrt(fabs(xk0))-fabs(xk1)*sqrt(fabs(xk1)))/3 + xk1*(sgnn(xk1)*sqrt(fabs(xk1))-sgnn(xk0)*sqrt(fabs(xk0))));
        xk0=xk1;
        fxk0=fxk1;
        xk1+=h;
        fxk1=(*f)(xk1);

    }
    return (2*sn)/h;
}
