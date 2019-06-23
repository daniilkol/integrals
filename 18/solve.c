#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.h"
#define MAXIT 10000
int solve(double x0,double e,double* x,double (*f)(double))
{
    int it;
    double fx0=(*f)(x0),xk,fxk;
    for (it=0;it<MAXIT;it++)
    {

        xk=fx0;
        fxk=(*f)(xk);
        if (fabs(fxk-xk)<e)
        {
            *x=xk;
            break;
        }
        x0=xk;
        fx0=fxk;

    }

    return it;
}
