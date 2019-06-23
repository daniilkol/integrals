#include <stdio.h>
#include <stdlib.h>
#include "solve.h"
double solve (double (*f)(double),double a,double b,int n)
{
    double h=(b-a)/(2*n),fa=(*f)(a)/2,fb=(*f)(b)/2,xk=a,fxk,sn=fa+fb;
    int k;
    for (k=1;k<2*n;k++)
    {
        xk+=h;
        if (k%2==0)
         fxk=(*f)(xk);
        else fxk=2*(*f)(xk);
        sn+=fxk;

    }
    return (2*h*sn)/3;
}
