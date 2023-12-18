#include <stdio.h>
#include <stdlib.h>

int main()
{
	
   
	//Bond value的計算
	int n;
	float c, r, Value=0,Discount;
	printf("請輸入期數:");
    scanf("%d",&n);
	printf("請輸入債息:");
	scanf("%f",&c);
	printf("請輸入利率(用百分比)");
	scanf("%f",&r);
	r=r/100;
    for(int i=1;i<=n;i=i+1)
	{
	 Discount=1;
	 for(int j=1;j<=i;j++)
	 {
	  Discount=Discount/(1+r); 	 
	 }
     Value=Value+Discount*c;
	 if(i==n)
	 {
	  Value=Value+Discount*100;
	 }
	}
    printf("BondValue=%f\n",Value);

	system("pause");
	return 0;
}
