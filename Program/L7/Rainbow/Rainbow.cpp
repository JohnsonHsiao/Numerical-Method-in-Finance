#include<math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX_UNDERLYING 10
double InitPrice[MAX_UNDERLYING];
double Vol[MAX_UNDERLYING];
double B[MAX_UNDERLYING][MAX_UNDERLYING];
//�q�V�qw�ܦ��V�qa���ҭ����x�}
double a[MAX_UNDERLYING];

double Max(double a,double b)
{
 if(a>b) return a;
 else return b;
}
double Normal()
{
     double N=0;
	 for(int j=0;j<12;j++)
	 {
	   N=N+double(rand())/RAND_MAX;
	 }
     N=N-6;
	return N;
}
void ComputeB(int k)
{
  int i,j,l;
  FILE* READ=fopen("TestData.txt","r");
  for(i=0;i<k;i++)
   fscanf(READ,"%lf",&InitPrice[i]);
  for(i=0;i<k;i++)
   fscanf(READ,"%lf",&Vol[i]);
 //�p��x�}B 
  double RhoSum,Rho;
  B[0][0]=1;
  for(i=1;i<k;i++)
  {
   fscanf(READ,"%lf",&B[i][0]);  
   for(j=1;j<i;j++)
   {
    RhoSum=0; 
    for(l=0;l<j;l++)
		RhoSum+=B[i][l]*B[j][l];	
	fscanf(READ,"%lf",&Rho);    
	B[i][j]=(Rho-RhoSum)/B[j][j];
   }
   RhoSum=0;
   for(j=0;j<i;j++)
    RhoSum+=pow(B[i][j],2); 
   B[i][i]=sqrt(1-RhoSum);
  }
  fclose(READ);
}
void GenNormalVector(int k)
{
 int i,j;
 double Vector[MAX_UNDERLYING];
 for(i=0;i<k;i++)
 {
   Vector[i]=Normal();
 }
 for(i=0;i<k;i++)
 {
  double Element=0;
  for(j=0;j<=i;j++)
   Element+=Vector[j]*B[i][j];
  a[i]=Element;
 }
}
int main()
{  
  //��J���
  float T,X,r; 
  int n,k;
  printf("��J�Ъ������Ӽ�:");
  scanf("%d",&k);
  printf("��J�����:");
  scanf("%f",&T);
  printf("��J�i������:");
  scanf("%f",&X);
  printf("��J�L���I�Q�v:");
  scanf("%f",&r);
  printf("��J����������:");
  scanf("%d",&n); 
  ComputeB(k);
  //�X�a�dù����
   srand( (unsigned)time( NULL ) );
   double SumU=0;
   double SquareSum=0;
   for( int i=0;i<n;i++)
   {
    GenNormalVector(k);
	double MaxST=0,ST;
	for(int j=0;j<k;j++)
	{
	  ST=InitPrice[j]*
      exp((r-Vol[j]*Vol[j]/2)*T+Vol[j]*sqrt(T)*a[j]);
	  MaxST=Max(MaxST,ST);
	}
	double V=exp(-r*T)*Max(MaxST-X,0);
    SumU=SumU+V;
   }
   double U=SumU/n;
   printf("Value=%f\n",U);

   system("pause");
   return 0;
}
