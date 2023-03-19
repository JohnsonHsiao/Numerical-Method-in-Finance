#include<stdio.h>
#include<stdlib.h>

int main()
{
    // if ����c
	int grade;
	float d,e,f,r,s;
	printf("輸入信用評等:");
 	scanf("%d",&grade);
 	printf("輸入第一期現金流:");
 	scanf("%f",&d);
    printf("輸入第二期現金流:");
 	scanf("%f",&e);
 	printf("輸入利率:");
 	scanf("%f",&r);
 	printf("輸入風險貼水:");
 	scanf("%f",&s);;
	if(grade>=60)
    {  
	   f= d/(r+s);
	   f= f+e/((1+r)*(1+r));
	}
	else
	{
	   f=d/(1+r+2*s);
	   f=f+e/((1+r+2*s)*((1+r+2*s));
	}
	printf("Present value=%f\n",f);

system("pause");
return 0;
}
