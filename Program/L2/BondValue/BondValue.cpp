#include<stdio.h>
#include<stdlib.h>

int main()
{
	//For 迴圈的控制結構
    for(int j=1;j<5;j++)
	{
	  for(int z=1;z<j;z++)
	  {
		printf(" %d-th Execution\n",j);
	  }
	}
  //Bond value的計算
	int n;
	float c, r, Value=0,Discount;
	printf("請輸入期數:");
    scanf("%d",&n);
	printf("請輸入債息:");
	scanf("%f",&c);
	printf("請輸入利率:");
	scanf("%f",&r);
    for(int i=1;i<=n;i=i+1)
	{//計算第i 次 payoff的  現值
	 Discount=1;
	 //計算(1+r)^(-i) 
	 for(int j=1;j<=i;j++)
	 {
	  Discount=Discount/(1+r); 	 
	 }
     Value=Value+Discount*c;
	 if(i==n)
	 {//考慮最後一期本金折現
	  Value=Value+Discount*100;
	 }
	}
    printf("BondValue=%f\n",Value);
  
  system("pause");
  return 0;
}
