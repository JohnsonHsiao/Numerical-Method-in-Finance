/* Calendar Program.
 *                                 
 */
#include<stdio.h>
#include<stdlib.h>

/* Function prototypes */
void pri_cal(int first_day,int end);
void special_case(void);
int count_days(int year,int month);
int count_first_day(int year,int month);
void pri_title(int year,int month);

/* 主程式 */
int main()
{		int error,year,month,the_first_day,end;
/*　以下為提示輸入年月之程式，用while迴圈來除去不合理的年份或月份。  */
		do
		{
		printf("\nInsert the year>>");
		scanf("%d",&year);
		error=0;
		if(year<=0 || year >=30000)
		{       printf("Invalid year!!");
			error=1;
		}
		}while(error==1);
		do
		{
		printf("\nInsert the month>>");
		scanf("%d",&month);
		error=0;
		if(month<1 || month>12)
		{	printf("Invalid month!!");
			error=1;
		}
		}while(error==1);
		
		pri_title(year,month);  /* 呼叫印出年月抬頭之副程式 */

/* 以下是用來判定是否為1752年9月，若是，則為特例，呼叫特別程式處理；若否，則為一般情形。 */
		if(year==1752 && month==9)
		special_case();  /* 呼叫特別程式處理1752年9月 */

		else
		{	/*以下一行是呼叫副程式計算該年該月第一天是星期幾*/
			the_first_day=count_first_day(year,month);
			end=count_days(year,month); /* 呼叫副程式以計算該年該月有幾天 */
			pri_cal(the_first_day,end); /* 呼叫列印月曆之副程式 */
		}
		printf("\n");
		system("pause");
		return(0);
}

/* 以下是印出年月抬頭之副程式 */
void pri_title(int year,int month)
{       	const char *a_month[12]={"Jan.","Feb.","Mar.","Apr.","May",
		"Jun.","Jul.","Aug.","Sept.","Oct.","Nov.","Dec."};

		printf("      %s  %d",a_month[month-1],year);
}

/* 以下為計算該年該月有幾天之副程式：因為1752年之前為四年一閏，1752年以後位四年一閏，
 * 逢百不閏，而四百又要閏，故分為以下狀況。 
 */
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

/* 以下為列印月曆之副程式：藉由該月第一天是星期幾及該月之天數來
 * 決定如何列印。
 */
void pri_cal(int first_day,int end)
{
	int i,j;

	printf("\n Su Mo Tu We Th Fr Sa\n");
	for(i=0;i<first_day;++i)
	printf("   ");
	for(j=1;j<=end;++j)
	{       printf("%3d",j);
		if((first_day+j)%7==0)
		printf("\n");
	}
}
/* 以下為計算第一天為星期幾之副程式：分為三部分：
 * (1)1752年8月以前，利用西元1年1月1日為星期六，及除７求餘的方式，
 *　　來計算所求年月第一天為星期幾。
 * (2)1752年10月～12月，利用1752年10月1日為星期日，及除７求餘的方式， 
 *　　來計算所求年月第一天為星期幾。
 * (3)1753年以後，利用1753年1月1日為星期一，及除７求餘的方式，　
 *　　來計算所求年月第一天為星期幾。
 */
int count_first_day(int year,int month)
{
	int i,j,f_day;
	if(year<1752 || (year==1752 && month<=8))
	{       f_day=6;
		for(i=1;i<year;++i)
		{	if(i%4==0)
			f_day=(f_day+366%7)%7;
			else
			f_day=(f_day+365%7)%7;
		}
		for(j=1;j<month;++j)
		{	f_day=(f_day+count_days(year,j))%7;
		}
	}
	else if(year>1752)
	{       f_day=1;
		for(i=1753;i<year;++i)
		{    if((i%4==0&&i%100!=0)||i%400==0)
		     f_day=(f_day+366%7)%7;
		     else
		     f_day=(f_day+365%7)%7;
		}
		for(j=1;j<month;++j)
		f_day=(f_day+count_days(year,j))%7;
	}
	else if(year==1752 && month>=10)
	{	f_day=0;
		for(j=10;j<month;++j)
		f_day=(f_day+count_days(year,j))%7;
	}
	return(f_day);
}

/* 此為特例之副程式，由於1752年9月無3～13日，故寫一專門處理該年月之副程式。 */
void special_case(void)
{
	int counter,days,first_day,end;
	first_day=2;
	end=30;
	printf("\n Su Mo Tu We Th Fr Sa\n");
	for(counter=0;counter<first_day;++counter)
	printf("   ");
	for(days=1;days<=end;++days)
	{       printf("%3d",days);
		if((first_day+days)%7==4&&days!=2)
		printf("\n");
		if(days==2)
		days=13;
	}
}
