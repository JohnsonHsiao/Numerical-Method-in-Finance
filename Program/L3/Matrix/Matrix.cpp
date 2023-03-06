#include<stdio.h>
#include<stdlib.h>
const int MATRIX_SIZE=3;

int main()
{
  int i,j,k;
  double A[MATRIX_SIZE][MATRIX_SIZE],B[MATRIX_SIZE][MATRIX_SIZE],C[MATRIX_SIZE][MATRIX_SIZE];
  //矩陣的輸入
  printf("Input Matrix A\n");
  for(i=0;i<MATRIX_SIZE;i++)
  {
    for(j=0;j<MATRIX_SIZE;j++)
	{
	  printf("A[%d,%d]=",i,j);
	  scanf("%lf",&A[i][j]);
	}
  }
  printf("Input Matrix B\n");
  for(i=0;i<MATRIX_SIZE;i++)
  {
    for(j=0;j<MATRIX_SIZE;j++)
	{
	  printf("B[%d,%d]=",i,j);
	  scanf("%lf",&B[i][j]);
	}
  }
  //矩陣的加法

  for(i=0;i<MATRIX_SIZE;i++)
  {
    for( j=0;j<MATRIX_SIZE;j++)
	{
	  C[i][j]=A[i][j]+B[i][j];
	}
  }
  ///  輸出結果
  printf("A+B=\n");
  for(i=0;i<MATRIX_SIZE;i++)
  {
    for( j=0;j<MATRIX_SIZE;j++)
	{
	  printf("%lf\t",C[i][j]);
	}
	printf("\n");
  }
  //矩陣的乘法
  for(i=0;i<MATRIX_SIZE;i++)
  {
    for( j=0;j<MATRIX_SIZE;j++)
	{
	  C[i][j]=0;
	   for( k=0;k<MATRIX_SIZE;k++)
	   {
		   C[i][j]+=A[i][k]*B[k][j];
	   }
	}
  }
  ///  輸出結果
  printf("A*B=\n");
  for(i=0;i<MATRIX_SIZE;i++)
  {
    for( j=0;j<MATRIX_SIZE;j++)
	{
	  printf("%lf\t",C[i][j]);
	}
	printf("\n");
  }
  //向量和矩陣相乘

  double D[MATRIX_SIZE],E[MATRIX_SIZE];
  printf("輸入向量D\n");
  for(i=0;i<MATRIX_SIZE;i++)
  {
	printf("D[%d]=",i);
    scanf("%lf",&D[i]);
  }

  for(i=0;i<MATRIX_SIZE;i++)
  {
    E[i]=0;
	for(j=0;j<MATRIX_SIZE;j++)
	{
	 E[i]+=D[j]*B[j][i]; 
	}
  }
   //輸出結果
  printf("D*B=\n");
  for(i=0;i<MATRIX_SIZE;i++)
  {
    printf("%lf\t",E[i]);
  }

system("pause");
return 0;
}
