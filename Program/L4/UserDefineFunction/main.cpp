#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float Max( float a, float b)
{
   if (a>b)
     {  
       return a;
     }
   else
   {
    return b;
   }
} 

int main(int argc, char *argv[]) {
 float a,b,c;
 scanf("%f",&a);
 scanf("%f",&b);
 c=Max(a,b);
 printf("%f�M%f�����j���O%f\n",a,b,c);
 printf("%f�M%f�����j���O%f\n",-a,-b,Max(-a,-b));

 system("pause");
 return 0;
}
