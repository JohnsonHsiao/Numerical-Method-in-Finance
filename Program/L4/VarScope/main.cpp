#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a=2;   //  global variable
void f ()
 {
   int b=3;    //  Local to function f
   printf("%d",a);
}


int main(int argc, char *argv[]) {
 printf("%d",b);  //illegal use
 int a=3;            // local to function main  
 printf("%d",a);

 system("pause");
	return 0;
}
