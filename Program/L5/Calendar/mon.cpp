#include <stdio.h>
#include<iostream>
#include <string.h>
#include <stdlib.h>
int count_days(int year,int month)
{
		int days;

		if(year<=1752 && year%4==0 && month==2)
		days=29;
		else if(year>1752 && ((year%4==0 && year%100!=0) ||
		year%400==0) && month==2)
		days=29;
		else if(month==1||month==3||month==5||month==7||
		month==8||month==10||month==12)
		days = 31;
		else if(month==4||month==6||month==9||month==11)
		days = 30;
		else
		days = 28;

		return(days);
}
int count_t(int year1,int month1, int day1,int year2,int month2, int day2)
{
	int t=0;
	int i;
	if (year1==year2)
	{
		if(month1==month2)
			return day2-day1;
		else
		{
			for(i=month1+1;i<month2;i++)
			{
				t=t+count_days(year1,i);
			}
			t=(t+count_days(year1,month1)-day1+day2);
			return t;
		}
	}
	else
	{
        for(i=year1+1;i<year2;i++)
			{
			   if((i%4==0 && i%100!=0) ||i%400==0)
				   t=t+366;
			   else 
				   t=t+365;
			}
		 //t=t+count_day2(yea1,month1)-day1;
		for(i=month1+1;i<=12;i++)
			{
				t=t+count_days(year1,i);
			}
        for(i=1;i<month2;i++)
			{
				t=t+count_days(year2,i);
			}
			t=(t+count_days(year1,month1)-day1+day2);
			return t;

	}
}
int main()
{
	
	int year1,year2,month1,month2,day1,day2;
	printf("year1:");
	scanf("%d",&year1);
	printf("month1:");
	scanf("%d",&month1);
    printf("day1:");
	scanf("%d",&day1);
    printf("year2:");
	scanf("%d",&year2);
    printf("month2:");
	scanf("%d",&month2);
    printf("day2:");
	scanf("%d",&day2);
     printf("%d days\n",count_t(year1,month1,day1,year2,month2,day2));

	 char c[15];
	char Year[5]; int Y;
	printf("Input a date");
	scanf("%s",c);
    int p0=0,p1=0;
    while(c[p0]!='/')
	{
	 Year[p1]=c[p0];
	 p0=p0+1;
	 p1=p1+1;
	}
	Year[p1]=0;
	Y=atoi(Year);
	printf("Year %d",Y);
   
	 /*
	char Start[20],End[20];
	printf("Input date 1");
    scanf("%s",Start);
    printf("Input date 2");
    scanf("%s",End);
   	char Year[5];
    int p0=0,p1=0;
    while(Start[p0]!='/')
	{
	 Year[p1]=Start[p0];
	 p0=p0+1;
	 p1=p1+1;
	}
	Year[p1]=0;
	year1=atoi(Year);
	p0=p0+1;
	p1=0;
	while(Start[p0]!='/')
	{
	 Year[p1]=Start[p0];
	 p0=p0+1;
	 p1=p1+1;
	}
	Year[p1]=0;
	month1=atoi(Year);
    p0=p0+1;
	p1=0;
    while(Start[p0]!=0)
	{
	 Year[p1]=Start[p0];
	 p0=p0+1;
	 p1=p1+1;
	}
	Year[p1]=0;
	day1=atoi(Year);
    
*/  
   system("pause");
   return 0;
    
 
}
