#include<stdio.h>
#include<stdlib.h>
const int MATRIX_SIZE=3;

int main()
{
   int i,j;
//////////////////////////�p����զX���ܲ���
  /////���զX��J
   
   double X[MATRIX_SIZE];
   printf("��J�겣�t�m\n");
  for(i=0;i<MATRIX_SIZE;i++)
  {
	printf("��%d�Ӹ겣:",i+1);
    scanf("%lf",&X[i]);
  }
  ///�@�ܲ��Ưx�}
   double S[MATRIX_SIZE][MATRIX_SIZE];
  printf("��J�@�ܲ��Ưx�}\n");
  for(i=0;i<MATRIX_SIZE;i++)
  {
    for(j=0;j<=i;j++)
	{
	  printf("��%d�M��%d�Ӹ겣���@�ܲ���=",i+1,j+1);
	  scanf("%lf",&S[i][j]);
	  S[j][i]=S[i][j];
	}
  }
  ///////    �Эp��  (X^T)SX  
system("pause");
return 0;
}
