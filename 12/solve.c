#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXIT 10000
double intg (double (*f)(double),double a,double b,int n)
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
int solve(double a,double b,double e,double* x,double (*f)(double),double (*g)(double),double (*v_p)(double),double (*n_p)(double))
{
    int it,n=1e6;
    double c,fa,fb,fc,vp,np;
    vp=(*v_p)(a);
    np=(*n_p)(a);
    fa=(*g)(a)+intg(f,np,vp,n);
    vp=(*v_p)(b);
    np=(*n_p)(b);
    fb=(*g)(b)+intg(f,np,vp,n);

    for (it=0;it<MAXIT;it++)
    {
        c=(a+b)/2;
        vp=(*v_p)(c);
        np=(*n_p)(c);
        fa=(*g)(c)+intg(f,np,vp,n);
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
