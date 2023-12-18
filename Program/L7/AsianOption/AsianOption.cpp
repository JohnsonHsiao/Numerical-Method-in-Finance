#include<math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double Max(double a,double b)
{
 if(a>b) return a;
 else return b;
}
double Normal()
{
     double N=0;
	 for(int j=0;j<12;j++)
	 {
	   N=N+double(rand())/RAND_MAX;
	 }
     N=N-6;
	return N;
}
///Control Variate 計算
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
   double MPI=3.14159265359;
   double value=1-exp(d*d/(-2))*(a1*k+a2*pow(k,2)+a3*pow(k,3)+a4*pow(k,4)
                  +a5*pow(k,5))/sqrt(2*MPI);
   if(flag) return 1-value;
    else return value;
}
double GeometricCall(double S, double T, double X, double r, double Sigma)
{
  double OptionValue;
  double D_Start=(r-(Sigma*Sigma)/6.0)/2.0*T;
  double D=(log(S/X)+
	      (r+(Sigma*Sigma)/6.0)/2.0*T)/
		  (Sigma*sqrt(T/3.0));
  OptionValue=exp(D_Start)*S*Standard_Normal_Distribution(D)-
	 X*Standard_Normal_Distribution(D-Sigma*sqrt(T/3.0));
  double Discounted=exp(r*T);
  OptionValue/=Discounted; 
 return OptionValue;
}
////
int main()
{  
  //輸入資料
  float S,T,X,r,Sigma; 
  int m,n;
  printf("輸入標的物價格:");
  scanf("%f",&S);
  printf("輸入到期日:");
  scanf("%f",&T);
  printf("輸入履約價格:");
  scanf("%f",&X);
  printf("輸入無風險利率:");
  scanf("%f",&r);
  printf("輸入標的物價格波動率:");
  scanf("%f",&Sigma); 
  printf("輸入切割的期數:");
  scanf("%d",&m); 
  printf("輸入模擬的次數:");
  scanf("%d",&n); 
   printf("%f\n", GeometricCall(S, T,X,  r, Sigma));
   //蒙地卡羅模擬
   srand( (unsigned)time( NULL ) );
   double OptionValue=0;
   double SquareSum=0;
   double DT=T/m;
   for(int i=0;i<n;i++)
   {
	double ST=S;
	double Sum=ST;
	for(int j=1;j<=m;j++)
	{
		double N=Normal();
		ST=ST*exp((r-Sigma*Sigma/2)*DT+Sigma*sqrt(DT)*N);
	    Sum=Sum+ST; 
	}
	double Avg=Sum/(m+1); 
	double Payoff=exp(-r*T)*Max(Avg-X,0);
    OptionValue=OptionValue+Payoff;
	SquareSum=SquareSum+pow(Payoff,2);
   }
   OptionValue=OptionValue/n;
   double STDERR=sqrt((SquareSum/n-pow(OptionValue,2))/n);
   printf("Value=%f, Standard Err~%f\n",OptionValue,STDERR);

   system("pause");
   return 0;
}
