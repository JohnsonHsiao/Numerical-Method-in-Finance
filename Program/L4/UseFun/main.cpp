#include <iostream>
#include <math.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double A=-1.0,B=2,C=10;
  double Result; 
  Result=fabs(A);   //荡癸ㄧΑ
  printf("%f\n",Result);
  Result=exp(A);    //计ㄧΑ 
  printf("%f\n",Result);
  Result=pow(B,B);   //Power function
  printf("%f\n",Result);
  Result=sqrt(B);  //秨腹
  printf("%f\n",Result);
  Result=log(exp(B));  //癸计ㄧ计=>┏计 e
  printf("%f\n",Result);
  Result=log10(C);   //癸计ㄧ计=>┏计 10
  printf("%f\n",Result);
  Result=pow(C,A)*pow(C,B);
  double Result1=exp(A*log(C)+B*log(C));
  if(Result==Result1)
	  printf("Y");

  system("pause");
  return 0;
}
