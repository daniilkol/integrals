#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.h"
#define MAXIT 100000
int solve(double a,double b,double e,double* x,double (*f)(double))
{
    int it;
    double fx0=(*f)(a),fx1=(*f)(b),x0=a,x1=b,x2,fx2;
    for (it=0;it<MAXIT;it++)
    {
        if (fabs(fx0-fx1)<1e-16)
            return -1;
        x2=(x0*fx1-x1*fx0)/(fx1-fx0);
        fx2=(*f)(x2);
        if (fabs(fx2)<e)
        {
            *x=x2;
            return it;
        }
        x0=x1;
        x1=x2;
        fx0=fx1;
        fx1=fx2;

    }

    return it;
}
