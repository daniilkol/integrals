#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.h"
#define MAXIT 1000000
int minznach(double a,double b,double c,double d)
{
    int num1,num2;
    double min1,min2;
    if (a>b)
        {
            num1=2;
            min1=b;
        }
    else
        {
            num1=1;
            min1=a;
        }
    if(c>d)
        {
            num2=4;
            min2=d;
        }
    else
       {
        num2=3;
        min2=c;
       }
    if(min1>min2)
        return num2;
    else return num1;
}
int solve(double a,double b,double e,double* x,double (*f)(double))
{
    int it,p;
    double x0=a,x2=b,x1=(a+b)/2,fx0=(*f)(x0),fx1=(*f)(x1),fx2=(*f)(x2),x3,fx3,fx0x1,fx0x1x2;
    for (it=0;it<MAXIT;it++)
    {

        fx0x1=(fx1-fx0)/(x1-x0);
        fx0x1x2=(((fx2-fx1)/(x2-x1))-fx0x1)/(x2-x0);
        x3=-0.5*(fx0x1/fx0x1x2-(x1+x0));
        fx3=(*f)(x3);
        p=minznach(fx0,fx1,fx2,fx3);
        if (p==4)
            return -1;
        if (fabs(x0-x2)<e)
        {
            *x=fx3;
            return it;
        }
        if (p==1)
        {
            x0=x1;
            fx0=fx1;
            x1=x2;
            fx1=fx2;
            x2=x3;
            fx2=fx3;
        }
        if(p==2)
        {
            x1=x2;
            fx1=fx2;
            x2=x3;
            fx2=fx3;
        }
        if(p==3)
        {
            x2=x3;
            fx2=fx3;
        }




    }

    return it;
}
