#include<stdio.h>
#include<stdlib.h>

int main()
{
  float ZeroRate[5];   
  float C;
  printf("�п�J�Ů�:");
  scanf("%f",&C);
  printf("��JZero rate\n");
  for(int i=0;i<5;i=i+1) //��Jzero rate
  {
   printf("��J��%d����Zero rate:",i+1);
   scanf("%f",&ZeroRate[i]);
  }
  float BondValue=0;
  for(int k=0;k<5;k=k+1)
  {  //�p���i��payoff���{��
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
  printf("�Ũ����=%f\n", BondValue);

system("pause");
return 0;
}
