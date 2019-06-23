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
    double h=(b-a)/(2*n),fxk0,fxk1,fxk2,xk0=a,xk1=a+h,xk2=a+2*h,sn=0,c,d,e;
    int k;
    fxk0=(*f)(xk0);
    fxk1=(*f)(xk1);
    fxk2=(*f)(xk2);
    for (k=0;k<n;k++)
    {
        c=(fxk2+fxk0-2*fxk1)/(2*h*h);
        d=(fxk1-fxk0)/h - (xk0+xk1)*c;
        e=fxk0-(xk0*(fxk1-fxk0))/h + xk0*xk1*c;
        sn+=(2*c*(fabs(xk2)*fabs(xk2)*sqrt(fabs(xk2))-fabs(xk0)*fabs(xk0)*sqrt(fabs(xk0))))/5 + (2*d*(fabs(xk2)*sqrt(fabs(xk2))-fabs(xk0)*sqrt(fabs(xk0))))/3 + 2*e*(sgnn(xk2)*sqrt(fabs(xk2))-sgnn(xk0)*sqrt(fabs(xk0)));
        xk0=xk2;
        fxk0=fxk2;
        xk1+=2*h;
        fxk1=(*f)(xk1);
        xk2+=2*h;
        fxk2=(*f)(xk2);

    }
    return sn;
}
