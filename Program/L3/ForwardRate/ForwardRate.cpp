#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  int i,a,b,j;
  double ZeroRate[5]; 
  double Forward[6][6];
  for(i=0;i<5;i=i+1)  //��J�s���Q�v
  {
   printf("��J�� %d�����s���Q�v:",i+1);
   scanf("%lf",&ZeroRate[i]);
  }
  for(i=0;i<5;i=i+1)
  {
   Forward[0][i+1]=ZeroRate[i];
  }
  for(i=0;i<=5;i=i+1)
  {
   Forward[i][i]=0;
  }
  for(a=1;a<5;a=a+1)//�p�⻷���Q�v
  {
   for(b=a+1;b<=5;b=b+1)
   {
    Forward[a][b]=pow(pow(1+Forward[0][b],b)/pow(1+Forward[0][a],a),1.0/(b-a))-1; 
   }
  }
  for(i=0;i<6;i=i+1)//���G��X
  {
   for(j=i;j<6;j=j+1)
   {
    printf("f(%d,%d)=%lf\n",i,j,Forward[i][j]);
   }
  }

system("pause");
return 0;
}
