#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.h"
#define MAXIT 10000
int solve(double a,double b,double e,double* x,double (*f)(double))
{
    int it;
    double c,fa=(*f)(a),fb=(*f)(b),fc;
    for (it=0;it<MAXIT;it++)
    {
        c=(a+b)/2;
        fc=(*f)(c);
        if((fabs(c-a)<1e-16)||(fabs(c-b)<1e-16))
        {
            *x=c;
            return it;
        }
        if(fa*fc<0)
            b=c;
        if(fb*fc<0)
            a=c;
        if ((b-a<e)||(fabs(fc)<e))
        {
            *x=c;
            return it;
        }

    }

    return -1;
}
