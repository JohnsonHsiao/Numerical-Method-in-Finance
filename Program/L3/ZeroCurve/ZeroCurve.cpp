#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  int i,j,k;
  float ZeroRate[5]; 
  float Yield[5];
  float C;
  printf("�п�J�Ů�:");
  scanf("%f",&C);
  for(i=0;i<5;i=i+1)
  {                                 //��J�ާQ�v
   printf("��J�� %d ��Yield rate:",i+1);
   scanf("%f",&Yield[i]);
  }
  ZeroRate[0]=Yield[0];          //�Ĥ@�����s���Q�v����Ĥ@�����ާQ�v
  for(i=1;i<=4;i++)             //�p���i+1��zero rate

  {
   float BondValue=0;
   for(j=0;j<=i;j=j+1)     //�p��Ũ����Bi+1
   {
	 float Discount=1;
	 for(k=0;k<=j;k++)
	 {
	  Discount=Discount/(1+Yield[i]); 	 
	 }
     BondValue=BondValue+Discount*C;
	 if(j==i)
	 {
	  BondValue=BondValue+Discount*100;
	 }
   }
   for(j=0;j<i;j=j+1)
   {
     float PV=C;
	 for(k=0;k<=j;k++)
	 {
	  PV=PV/(1+ZeroRate[j]);
	 }  
     BondValue=BondValue-PV;
   }  
   ZeroRate[i]=pow(1.0*(C+100)/BondValue,1.0/(i+1))-1;
  }  
  for(i=0;i<=4;i++)   //�C�L�s���Q�v
  {
   printf("��%d��zero rate=%f\n",i+1,ZeroRate[i]);  
  }

system("pause");
return 0;
}
