#include <iostream>
#include <stdio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a=2;
void f(int b)
{  
    double a=3;
    cout<<a+b<<endl;
}

int main(int argc, char *argv[]) {
  cout<<a<<endl;
  for(int a=1;a<3;a++)
  {
     f(a); 
  }
    system("pause");
	return 0;
}
