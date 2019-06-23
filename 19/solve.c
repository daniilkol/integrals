#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.h"
#define MAXIT 10000000
int solve(double a,double b,double e,double* x,double (*f)(double))
{
    int it,k;
    double h=(b-a)/10,maxf=(*f)(a),xk,fxk;
    for (it=0;it<MAXIT;it++)
    {
        if (fabs(h)<e)
        {
            *x=maxf;
            return it;
        }
        if(h>0)
        {
            for (k=0;;k++)
            {
                xk=a+k*h;
                if (xk>b)
                    break;
                fxk=(*f)(xk);
                if (fxk>maxf)
                    maxf=fxk;
            }
            it+=k;
        }
        if (h<0)
        {
            for (k=0;;k++)
            {
                xk=b+k*h;
                if (xk<a)
                    break;
                fxk=(*f)(xk);
                if (fxk>maxf)
                    maxf=fxk;
            }
            it+=k;
        }
        h=-h/10;
    }

    return it;
}
