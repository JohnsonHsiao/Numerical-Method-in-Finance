#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main( void )
{
   int i;
   //�ϥΨt�ήɶ����ͶüƧǦC
   srand( (unsigned)time( NULL ) );
   for( i = 0;   i < 10;i++ )
   {
	   printf( "  %d\n", rand() );
   }
   //���ͱ`�A�H���ܼ� 
     double Normal=0;
	 for(int j=0;j<12;j++)
	 {
	   Normal=Normal+double(rand())/RAND_MAX;
	 }
    Normal=Normal-6;
	printf("Normal = %lf\n",Normal);

	system("pause");
	return 0;
}
