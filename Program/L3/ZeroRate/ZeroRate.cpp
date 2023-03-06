#include<stdio.h>
#include<stdlib.h>

int main()
{
  float ZeroRate[5];   
  float C;
  printf("請輸入債息:");
  scanf("%f",&C);
  printf("輸入Zero rate\n");
  for(int i=0;i<5;i=i+1) //輸入zero rate
  {
   printf("輸入第%d期的Zero rate:",i+1);
   scanf("%f",&ZeroRate[i]);
  }
  float BondValue=0;
  for(int k=0;k<5;k=k+1)
  {  //計算第i次payoff的現值
   float Discount=1;
   for(int j=0;j<=k;j=j+1)
   {
    Discount=Discount/(1+ZeroRate[k]);
   }
   BondValue=BondValue+C*Discount;
   if(k==4)
   {
      BondValue=BondValue+100*Discount;
   }
  }
  printf("債券價格=%f\n", BondValue);

system("pause");
return 0;
}
