#include<stdio.h>
#include<stdlib.h>

int main()
{
  int grade;
  printf("Input the grade:");
  scanf("%d",&grade);
  //Nest if
  if ( grade >= 60 ) 
  {
   printf( "Passed\n" );
  }
   else
   {
    if ( grade>=50 )
	{
     printf ("Makeup exam\n");
	}
    else
	{
     printf ("Failed\n");
	}
   }
   //  else if
   if ( grade >= 60 )      
	     printf("Passed\n");
    else if(grade>=50)
		printf("Makeup exam\n");
    else
         printf("Failed\n");

    // Dangling else problem
	///  Case1:  else �Y��M�ĤG��if���
   if ( grade >=60)
	  if (grade >=80)
		printf("Good job\n");
      else
		printf("???");
   ///  Case2:  else �Y��M�Ĥ@��if���
   if ( grade >=60)
      if (grade >=80)
		printf("Good job\n");
   else
		printf("???");
  /////�ɦ^�j�A��   �קKDandling else �ҳy�����y�N���M�����D
   if ( grade >=60)
   {
	if (grade >=80)
	{
		printf("Good job\n");
	}
    else
	{
      printf("Passed");
	}
   }

system("pause");
return 0;

}
