#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.h"
#define MAXIT 1000000
int maxznach(double a,double b,double c,double d)
{
    int num1,num2;
    double max1,max2;
    if (a>b)
        {
            num1=1;
            max1=a;
        }
    else
        {
            num1=2;
            max1=b;
        }
    if(c>d)
        {
            num2=3;
            max2=c;
        }
    else
       {
        num2=4;
        max2=d;
       }
    if(max1>max2)
        return num1;
    else return num2;
}
int solve(double a,double b,double e,double* x,double (*f)(double))
{
    int it,p;
    double x0=a,x2=b,x1=(a+b)/2,fx0=(*f)(x0),fx1=(*f)(x1),fx2=(*f)(x2),x3,fx3;
    for (it=0;it<MAXIT;it++)
    {

        x3=x0-fx0*((x1-x0)/(fx1-fx0))+fx0*fx1*((((x2-x1)/(fx2-fx1))-((x1-x0)/(fx1-fx0)))/(fx2-fx0));
        fx3=(*f)(x3);
        p=maxznach(fx0,fx1,fx2,fx3);
        if(p==4)
            return -1;

        if (p==1)
        {
            x0=x1;
            fx0=fx1;
            x1=x2;
            fx1=fx2;
            x2=x3;
            fx2=fx3;
        }
        if (p==2)
        {
            x1=x2;
            fx1=fx2;
            x2=x3;
            fx2=fx3;
        }
        if (p==3)
         {
             x2=x3;
             fx2=fx3;
         }
        if (fabs(fx3)<e)
        {
            *x=x3;
            return it;
        }


    }

    return it;
}
