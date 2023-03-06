#include<stdio.h>
#include<stdlib.h>

int main()
{
	//while迴圈的架構
	int i;
	scanf("%d",&i);
	while(i<5)
	{
		printf("Input:%d\n",i);
		scanf("%d",&i);
		if(i==3) break;     //簡介  break和continue的功能
		continue;
		printf("這行不會被執行");
	}
	//求算IRR
	float c,x,Discount;
	float Low=0, High=1;
	int n;
	printf("請輸入每期可回收的金額:");
	scanf("%f",&c);
	printf("請輸入期初投資金額:");
	scanf("%f",&x);
	printf("請輸入期數");
	scanf("%d",&n);
	while(High-Low>=0.0001)
	{
		float  Middle=(Low+High)/2;
		float Value=0;
		for(int i=1;i<=n;i=i+1)  //用計算債券的公式計算
		{
			Discount=1;
			for(int j=1;j<=i;j++)
			{
				Discount=Discount/(1+Middle); 	 
			}
			Value=Value+Discount*c;
		}
		Value=Value-x;
		if(Value>0)             //縮小根的範圍 
		{ Low=Middle;}
		else
		{High=Middle;}
	} 
	printf("Yield rate=%f\n",High);

	system("pause");
	return 0;

}
