#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main( void )
{
   int i;
   //使用系統時間產生亂數序列
   srand( (unsigned)time( NULL ) );
   for( i = 0;   i < 10;i++ )
   {
	   printf( "  %d\n", rand() );
   }
   //產生常態隨機變數 
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
