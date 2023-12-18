#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double Max(double a,double b)
{
  if(a>b)  return a;
  else return b;
}
int main()
{
  //輸入資料
  float S,T,X,r,Sigma; 
  int n;  //期數           
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
  printf("輸入期數:");
  scanf("%d",&n);
  //計算CRR二元樹的相關參數
  double U, D, Pu,Pd,DeltaT;
  DeltaT=T/n;
  U=exp(Sigma*sqrt(DeltaT));
  D=exp(-Sigma*sqrt(DeltaT));
  Pu=(exp(r*DeltaT)-D)/(U-D);
  Pd=1-Pu;
  //計算payoff的折現期望值
  double CurrentS=S*pow(U,n);
  double CurrentProb=pow(Pu,n);
  double OptionValue=0;
  for(int i=0;i<=n;i=i+1)
  {
   OptionValue=OptionValue+exp(-r*T)*CurrentProb*Max(CurrentS-X,0);
   CurrentS=CurrentS*D/U;
   CurrentProb=CurrentProb*(n-i)/(i+1)*Pd/Pu;
  }
  //輸出評價結果
  printf("選擇權價格=%f\n",OptionValue);

  system("pause");
  return 0;
}
