#include<stdio.h>
#include<stdlib.h>

int main()
{
	int Z;   
	printf("�п�JZ:");
	scanf("%d",&Z);
	if(Z)
	{
		int a=1; 
		for(;Z>0;Z=Z-1)
		{
			int b=a+1;
			a=b;
		}
	printf("a=%d\n",a);
	//printf("b=%d",b);  // ���X�k�ޥ�
	}
	else
	{ 
	//printf("a=%d",a);  // ���X�k�ޥ�	  
		int a=1; 
		while(Z==0)
		{
			int a=2;  
			while(Z==0)
			{
				Z=Z-a;  	 
			}
			printf("Z=%d\n",Z); 
		}
		Z=Z-a; 
		printf("Z=%d\n",Z); 
	}

system("pause");
return 0;
}
