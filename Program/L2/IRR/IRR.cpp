#include<stdio.h>
#include<stdlib.h>

int main()
{
	//while�j�骺�[�c
	int i;
	scanf("%d",&i);
	while(i<5)
	{
		printf("Input:%d\n",i);
		scanf("%d",&i);
		if(i==3) break;     //²��  break�Mcontinue���\��
		continue;
		printf("�o�椣�|�Q����");
	}
	//�D��IRR
	float c,x,Discount;
	float Low=0, High=1;
	int n;
	printf("�п�J�C���i�^�������B:");
	scanf("%f",&c);
	printf("�п�J��������B:");
	scanf("%f",&x);
	printf("�п�J����");
	scanf("%d",&n);
	while(High-Low>=0.0001)
	{
		float  Middle=(Low+High)/2;
		float Value=0;
		for(int i=1;i<=n;i=i+1)  //�έp��Ũ骺�����p��
		{
			Discount=1;
			for(int j=1;j<=i;j++)
			{
				Discount=Discount/(1+Middle); 	 
			}
			Value=Value+Discount*c;
		}
		Value=Value-x;
		if(Value>0)             //�Y�p�ڪ��d�� 
		{ Low=Middle;}
		else
		{High=Middle;}
	} 
	printf("Yield rate=%f\n",High);

	system("pause");
	return 0;

}
