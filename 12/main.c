#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.c"
#include <time.h>
#define MAX_IT 10000
double f (double x);
double v_p (double x);
double n_p (double x);
double g (double x);
double v_p (double x)
{
    return x+1;
}
double n_p (double x)
{
    return x-1;
}
double g (double x)
{
    return x;
}
double f (double x)
{
    return x*x*x;
}
int main(void)
{
    int it,k,i,n=1e6;
    double t,e,x,h=0.15,a=-2,b=3,c,fa,fc,vp,np;
    double (*ptr1)(double);
    double (*ptr2)(double);
    double (*ptr3)(double);
    double (*ptr4)(double);
    ptr1=&f;
    ptr2=&g;
    ptr3=&v_p;
    ptr4=&n_p;
    printf("Input e:");
    if (scanf("%lf",&e)!=1)
    {
        printf("Cannot read!\n");
        return 1;
    }
    vp=v_p(a);
    np=n_p(a);
    fa=g(a)+intg(ptr1,np,vp,n);
    t=clock();
    for (it=0;it<MAX_IT;it++)
    {
        c=a+h;
        vp=v_p(c);
        np=n_p(c);
        fc=g(c)+intg(ptr1,np,vp,n);
        if (fa*fc<0)
        {
            k=solve(a,c,e,&x,ptr1,ptr2,ptr3,ptr4);
            printf("Otvet:%e\n",x);
            printf("Nevyazka:%e\n",g(x)+intg(f,n_p(x),v_p(x),n));
            fa=fc;
            a=c;

        } else
        {
            a=c;
            fa=fc;
        }
        if(c>b)
            break;
    }
    t=(clock()-t)/CLOCKS_PER_SEC;
    printf("Chislo iteracii:%d\n",it);
    printf("Elapsed time:%.2f\n",t);
    return 0;
}
