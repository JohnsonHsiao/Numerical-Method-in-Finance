#include <stdio.h>
#include <stdlib.h>

int main()
{
	
   
	//Bond value���p��
	int n;
	float c, r, Value=0,Discount;
	printf("�п�J����:");
    scanf("%d",&n);
	printf("�п�J�Ů�:");
	scanf("%f",&c);
	printf("�п�J�Q�v(�Φʤ���)");
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
