#include <stdio.h>
#include <math.h>
double Standard_Normal_Distribution(double d)
{
   int flag=0;   //Flag =1 if d<0
   if(d<0)
     {
      flag=1;
      d=fabs(d);
     }
   double rr=0.2316419;
   double a1=0.31938153;
   double a2=-0.356563782;
   double a3=1.781477937;
   double a4=-1.821255978;
   double a5=1.330274429;
   double k=1/(1+d*rr);
   double M_PI=3.14159265359;
   double value=1-exp(d*d/(-2))*(a1*k+a2*pow(k,2)+a3*pow(k,3)+a4*pow(k,4)
                  +a5*pow(k,5))/sqrt(2*M_PI);
   if(flag) return 1-value;
    else return value;
}

void main()
{
   float S,r,T,X,V;
   printf("輸入股價:");
   scanf("%f",&S);
   printf("輸入利率:");
   scanf("%f",&r);
   printf("輸入到期日:");
   scanf("%f",&T);
   printf("輸入履約價:");
   scanf("%f",&X);
   printf("輸入波動率:");
   scanf("%f",&V);
   double b=1/exp(r*T);
   double d1=(log(S/(X*b))+V*V*T/2)/(V*sqrt(T));
   double d2=d1-V*sqrt(T);
   double Value=S*Standard_Normal_Distribution(d1)-X*b*Standard_Normal_Distribution(d2);
   printf("Call value=%f",Value);  
}