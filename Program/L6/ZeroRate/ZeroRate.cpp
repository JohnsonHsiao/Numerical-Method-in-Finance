#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i;
  float ZeroRate[5];   
  float C;
  printf("�п�J�Ů�:");
  scanf("%f",&C);
  printf("��J�s���Q�v:\n");
  for(i=0;i<5;i=i+1)
  {
   printf("��%d���s���Q�v(%%):",i+1);
   scanf("%f",&ZeroRate[i]);
   ZeroRate[i]/=100;
  }
  float BondValue=0;
  for(i=0;i<5;i=i+1)
  {
   float Discount=1;
   for(int j=0;j<=i;j=j+1)
   {
    Discount=Discount/(1+ZeroRate[i]);
   }
   BondValue=BondValue+C*Discount;
   if(i==4)
   {
      BondValue=BondValue+100*Discount;
   }
  }
  printf("�Ũ����=%f\n", BondValue);

  system("pause");
  return 0;
}
