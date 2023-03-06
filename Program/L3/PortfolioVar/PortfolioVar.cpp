#include<stdio.h>
#include<stdlib.h>
const int MATRIX_SIZE=3;

int main()
{
   int i,j;
//////////////////////////計算投資組合的變異度
  /////投資組合輸入
   
   double X[MATRIX_SIZE];
   printf("輸入資產配置\n");
  for(i=0;i<MATRIX_SIZE;i++)
  {
	printf("第%d個資產:",i+1);
    scanf("%lf",&X[i]);
  }
  ///共變異數矩陣
   double S[MATRIX_SIZE][MATRIX_SIZE];
  printf("輸入共變異數矩陣\n");
  for(i=0;i<MATRIX_SIZE;i++)
  {
    for(j=0;j<=i;j++)
	{
	  printf("第%d和第%d個資產的共變異度=",i+1,j+1);
	  scanf("%lf",&S[i][j]);
	  S[j][i]=S[i][j];
	}
  }
  ///////    請計算  (X^T)SX  
system("pause");
return 0;
}
