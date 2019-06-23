#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "solve.h"
#define MAX_IT 1000
int fun (double (*f)(double),double a,double b,double e,double *r)
{
    int n=10,it,i;
    double sn=0,s2n=0,h=(b-a)/(2*n),fa=(*f)(a),fb=(*f)(b),sn1=0,sn2=(*f)(a+h),s2n1=0,s2n2=0;
    sn=(h*fa)/3 + (h*fb)/3;
    for(i=1;i<n;i++)
    {
        sn1+=(*f)(a+2*i*h);
        sn2+=(*f)(a+(2*i+1)*h);
    }
    sn=(2*h*sn1)/3 + (4*h*sn2)/3;
    for(it=0;it<MAX_IT;it++)
    {
        h=(b-a)/(2*n);
        s2n1=sn1+sn2;
        s2n=(h*fa)/6 + (h*fb)/6;
        s2n2=0;
        for(i=0;i<2*n;i++)
        {
            s2n2+=(*f)(a+((2*i+1)*h)/2);
        }
        s2n=(h*s2n1)/3+(2*h*s2n2)/3;
        if(fabs(s2n-sn)<e)
        {
         *r=s2n;
         return n;
        }
        n*=2;
        sn=s2n;
        sn1=s2n1;
        sn2=s2n2;


    }
    return -1;
}


double solve (double (*f)(double),double a,double e,double *r)
{
    double h=1,s=0,i=0,b=a;
    int it,k;
    for(it=0;it<MAX_IT;it++)
    {
        b=b+h;
        k=fun(f,a,b,e,&s);
        if (k==-1)
            return -2;
        if (fabs(s)<e)
            {
                *r=i;
                return b;
            }

            i+=s;
            a=b;
            h=h*2;

    }
    return -1;

}
