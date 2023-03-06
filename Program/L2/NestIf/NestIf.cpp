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
	///  Case1:  else 縮行和第二個if對齊
   if ( grade >=60)
	  if (grade >=80)
		printf("Good job\n");
      else
		printf("???");
   ///  Case2:  else 縮行和第一個if對齊
   if ( grade >=60)
      if (grade >=80)
		printf("Good job\n");
   else
		printf("???");
  /////補回大括弧   避免Dandling else 所造成的語意不清的問題
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
