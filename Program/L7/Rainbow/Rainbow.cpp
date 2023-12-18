#include<math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX_UNDERLYING 10
double InitPrice[MAX_UNDERLYING];
double Vol[MAX_UNDERLYING];
double B[MAX_UNDERLYING][MAX_UNDERLYING];
//從向量w變成向量a的所乘的矩陣
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
 //計算矩陣B 
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
  //輸入資料
  float T,X,r; 
  int n,k;
  printf("輸入標的物的個數:");
  scanf("%d",&k);
  printf("輸入到期日:");
  scanf("%f",&T);
  printf("輸入履約價格:");
  scanf("%f",&X);
  printf("輸入無風險利率:");
  scanf("%f",&r);
  printf("輸入模擬的次數:");
  scanf("%d",&n); 
  ComputeB(k);
  //蒙地卡羅模擬
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
