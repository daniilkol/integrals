#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.h"
#define MAXIT 10000
int solve(double x0,double e,double* x,double (*f)(double),double (*d)(double))
{
    int it;
    double fx=(*f)(x0),xk,dx=(*d)(x0);
    for (it=0;it<MAXIT;it++)
    {
        if(fabs(dx)<1e-16)
            return -1;
        if (fabs(fx)<e)
        {
            *x=x0;
            break;
        }
        xk=x0-fx/dx;
        fx=(*f)(xk);
        dx=(*d)(xk);
        x0=xk;
    }

    return it;
}
