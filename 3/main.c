#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double solve (double (*f)(double),double x,double h);
double f (double x);
double f (double x)
{
    return x*x;
}
double solve (double (*f)(double),double x,double h)
{
    return ((*f)(x+h)-2*(*f)(x)+(*f)(x-h))/(h*h);
}
int main(void)
{
    double x,h,res;
    int k;
    double (*ptr)(double);
    ptr=&f;
    for(k=0;;k++)
    {
        printf("Input x and h:");
        if(scanf("%lf%lf",&x,&h)!=2)
        {
            printf("Cannot read!\n");
            return 1;
        }
        if ((h<1e-16)||(h*h<1e-16))
            break;
        res=solve(ptr,x,h);
        printf("Otvet for x=%.2f",x);
        printf(" and h=%.2f",h);
        printf(" %.2f\n",res);


    }
    return 0;
}
