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
  int i,j;
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
  //計算最後一期的payoff
  double Array[500];
  double CurrentS=S*pow(U,n);
  for(i=0;i<=n;i=i+1)
  {
   Array[i]=Max(CurrentS-X,0);
   CurrentS=CurrentS*D*D;
  }
  //Backward Induction
  for(i=n-1;i>=0;i=i-1)
  {
   for(j=0;j<=i;j++)
   {
    Array[j]=exp(-r*DeltaT)*(Array[j]*Pu+Array[j+1]*Pd);
   }  
  }
  //輸出評價結果
  printf("選擇權價格=%f\n",Array[0]);

  system("pause");
  return 0;
}
