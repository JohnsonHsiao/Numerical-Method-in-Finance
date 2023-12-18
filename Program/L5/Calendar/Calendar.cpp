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

/* �D�{�� */
int main()
{		int error,year,month,the_first_day,end;
/*�@�H�U�����ܿ�J�~�뤧�{���A��while�j��Ӱ��h���X�z���~���Τ���C  */
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
		
		pri_title(year,month);  /* �I�s�L�X�~����Y���Ƶ{�� */

/* �H�U�O�ΨӧP�w�O�_��1752�~9��A�Y�O�A�h���S�ҡA�I�s�S�O�{���B�z�F�Y�_�A�h���@�뱡�ΡC */
		if(year==1752 && month==9)
		special_case();  /* �I�s�S�O�{���B�z1752�~9�� */

		else
		{	/*�H�U�@��O�I�s�Ƶ{���p��Ӧ~�Ӥ�Ĥ@�ѬO�P���X*/
			the_first_day=count_first_day(year,month);
			end=count_days(year,month); /* �I�s�Ƶ{���H�p��Ӧ~�Ӥ릳�X�� */
			pri_cal(the_first_day,end); /* �I�s�C�L��䤧�Ƶ{�� */
		}
		printf("\n");
		system("pause");
		return(0);
}

/* �H�U�O�L�X�~����Y���Ƶ{�� */
void pri_title(int year,int month)
{       	const char *a_month[12]={"Jan.","Feb.","Mar.","Apr.","May",
		"Jun.","Jul.","Aug.","Sept.","Oct.","Nov.","Dec."};

		printf("      %s  %d",a_month[month-1],year);
}

/* �H�U���p��Ӧ~�Ӥ릳�X�Ѥ��Ƶ{���G�]��1752�~���e���|�~�@�|�A1752�~�H���|�~�@�|�A
 * �{�ʤ��|�A�ӥ|�ʤS�n�|�A�G�����H�U���p�C 
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

/* �H�U���C�L��䤧�Ƶ{���G�ǥѸӤ�Ĥ@�ѬO�P���X�θӤ뤧�Ѽƨ�
 * �M�w�p��C�L�C
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
/* �H�U���p��Ĥ@�Ѭ��P���X���Ƶ{���G�����T�����G
 * (1)1752�~8��H�e�A�Q�Φ褸1�~1��1�鬰�P�����A�ΰ����D�l���覡�A
 *�@�@�ӭp��ҨD�~��Ĥ@�Ѭ��P���X�C
 * (2)1752�~10���12��A�Q��1752�~10��1�鬰�P����A�ΰ����D�l���覡�A 
 *�@�@�ӭp��ҨD�~��Ĥ@�Ѭ��P���X�C
 * (3)1753�~�H��A�Q��1753�~1��1�鬰�P���@�A�ΰ����D�l���覡�A�@
 *�@�@�ӭp��ҨD�~��Ĥ@�Ѭ��P���X�C
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

/* �����S�Ҥ��Ƶ{���A�ѩ�1752�~9��L3��13��A�G�g�@�M���B�z�Ӧ~�뤧�Ƶ{���C */
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
