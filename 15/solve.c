#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.h"
#define MAXIT 1000000
int solve(double a,double b,double e,double* x,double (*f)(double))
{
    int it;
    double c,fa=(*f)(a),fb=(*f)(b),fc;
    for (it=0;it<MAXIT;it++)
    {
        c=(b*fa-fb*a)/(fa-fb);
        fc=(*f)(c);
        if(fa*fc<0)
            b=c;
        if(fb*fc<0)
            a=c;
        if (fabs(fc)<e)
        {
            *x=c;
            return it;
        }

    }

    return -1;
}
