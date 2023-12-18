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
int main()
{  
  //輸入資料
  float S,T,X,r,Sigma; 
  int n;
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
  printf("輸入模擬的次數:");
  scanf("%d",&n); 

   //蒙地卡羅模擬
   srand( (unsigned)time( NULL ) );
   double OptionValue=0;
   double SquareSum=0;
   for(int i=0;i<n;i++)
   {
    double N=Normal();
	double ST=S*exp((r-Sigma*Sigma/2)*T+Sigma*sqrt(T)*N);
	double Payoff=exp(-r*T)*Max(ST-X,0);
    OptionValue=OptionValue+Payoff;
	SquareSum=SquareSum+pow(Payoff,2);
   }
   OptionValue=OptionValue/n;
   double STDERR=sqrt((SquareSum/n-pow(OptionValue,2))/(n-1));
   printf("Value=%f, Standard Err~%f\n",OptionValue,STDERR);

   system("pause");
   return 0;
}
