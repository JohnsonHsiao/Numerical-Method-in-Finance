#include<stdio.h>
#include<stdlib.h>

int main()
{
    // if ����c
	int grade;
	float d,e,f,r,s;
	printf("��J�H�ε���:");
	scanf("%d",&grade);
	printf("��J�Ĥ@���{���y:");
	scanf("%f",&d);
    printf("��J�ĤG���{���y:");
	scanf("%f",&e);
	printf("��J�Q�v:");
	scanf("%f",&r);
	printf("��J���I�K��:");
	scanf("%f",&s);
	if(grade>=60)
    {  
	   f=d/(1+r);
	   f=f+e/((1+r)*(1+r));
	}
	else
	{
	   f=d/(1+r+s);
	   f=f+e/((1+r+s)*(1+r+s));
	}
	printf("Present value=%f\n",f);

system("pause");
return 0;
}
