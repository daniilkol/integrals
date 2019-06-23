#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.h"
#define MAXIT 10000000
int solve(double a,double b,double e,double* x,double (*f)(double))
{
    int it,k;
    double h=(3-sqrt(5))/2,x1=a+(b-a)*h,x2=b-(b-a)*h,fx1=(*f)(x1),fx2=(*f)(x2),p,fa=(*f)(a),fb=(*f)(b);
    for (it=0;it<MAXIT;it++)
    {
        if (fx1>fx2)
        {
            b=x2;
            x2=x1;
            fx2=fx1;
            x1=a+(b-a)*h;
            fx1=(*f)(x1);
        } else
             {
                 a=x1;
                 x1=x2;
                 fx1=fx2;
                 x2=b-(b-a)*h;
                 fx2=(*f)(x2);
             }
        if (fabs(b-a)<e)
        {
            p=(*f)((a+b)/2);
            if (fa>fb)
            {
                if(p<fa)
                p=fa;
            }
                else
                {
                    if (p<fb)
                       p=fb;
                }
            *x=p;
            return it;
        }
    }
    return -1;
}
