#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double Max(double a,double b)
{
  if(a>b)  return a;
  else return b;
}
int main()
{
  int i,j;
  //��J���
  float S,T,X,H,r,Sigma; 
  int n;  //����           
  printf("��J�Ъ�������:");
  scanf("%f",&S);
  printf("��J�����:");
  scanf("%f",&T);
  printf("��J�i������:");
  scanf("%f",&X);
  printf("��J��ê����:");
  scanf("%f",&H);
  printf("��J�L���I�Q�v:");
  scanf("%f",&r);
  printf("��J�Ъ�������i�ʲv:");
  scanf("%f",&Sigma);
  printf("��J����:");
  scanf("%d",&n);
  double Array[5000];


  //�p��CRR�G���𪺬����Ѽ�
  double U, D, Pu,Pd,DeltaT;
  DeltaT=T/n;
  U=exp(Sigma*sqrt(DeltaT));
  D=exp(-Sigma*sqrt(DeltaT));
  Pu=(exp(r*DeltaT)-D)/(U-D);
  Pd=1-Pu;
  //�p�⦳�Ļ�ê�B��
  int u_power;
  u_power= (int)floor(log(H/S)/log(U));
  
  //�p��̫�@����payoff
  //double Array[500];
  double CurrentS=S*pow(U,n);
  for(i=0;i<=n;i=i+1)
  {
   Array[i]=Max(CurrentS-X,0);
  
   CurrentS=CurrentS*D*D;
  }
  if ( (((n-u_power)%2)==0) && (u_power>=-n) && (u_power<=n)) {
			Array[(n-u_power)/2]=0;
  }
  //Backward Induction
  for(i=n-1;i>=0;i=i-1)
  {
   for(j=0;j<=i;j++)
   {
    Array[j]=exp(-r*DeltaT)*(Array[j]*Pu+Array[j+1]*Pd);
   }  
   if ( (((i-u_power)%2)==0) && (u_power>=-i) && (u_power<=i)) {
	Array[(i-u_power)/2]=0;
   } 
  }
  //��X�������G
  printf("��ê����v����=%f\n",Array[0]);
 //scanf("%d",n);

	return 0;
}