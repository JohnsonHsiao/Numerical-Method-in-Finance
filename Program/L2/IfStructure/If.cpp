#include<stdio.h>
#include<stdlib.h>

int main()
{
	int grade;
	printf("Input the grade:");
	scanf("%d",&grade);
	if ( grade >= 60 ) 
	{ 
		printf( "Passed\n" );
		printf( "Passed\n" );
	}
	else
	{
		printf("Failed\n");
	}

	system("pause");
	return 0;

}
