#include<stdio.h>
#include<stdlib.h>

int main()
{
	//For �j�骺����c
    for(int j=1;j<5;j++)
	{
	  for(int z=1;z<j;z++)
	  {
		printf(" %d-th Execution\n",j);
	  }
	}
  //Bond value���p��
	int n;
	float c, r, Value=0,Discount;
	printf("�п�J����:");
    scanf("%d",&n);
	printf("�п�J�Ů�:");
	scanf("%f",&c);
	printf("�п�J�Q�v:");
	scanf("%f",&r);
    for(int i=1;i<=n;i=i+1)
	{//�p���i �� payoff��  �{��
	 Discount=1;
	 //�p��(1+r)^(-i) 
	 for(int j=1;j<=i;j++)
	 {
	  Discount=Discount/(1+r); 	 
	 }
     Value=Value+Discount*c;
	 if(i==n)
	 {//�Ҽ{�̫�@��������{
	  Value=Value+Discount*100;
	 }
	}
    printf("BondValue=%f\n",Value);
  
  system("pause");
  return 0;
}
