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
  //��J���
  float S,T,X,r,Sigma; 
  int n;  //����           
  printf("��J�Ъ�������:");
  scanf("%f",&S);
  printf("��J�����:");
  scanf("%f",&T);
  printf("��J�i������:");
  scanf("%f",&X);
  printf("��J�L���I�Q�v:");
  scanf("%f",&r);
  printf("��J�Ъ�������i�ʲv:");
  scanf("%f",&Sigma);
  printf("��J����:");
  scanf("%d",&n);
  //�p��CRR�G���𪺬����Ѽ�
  double U, D, Pu,Pd,DeltaT;
  DeltaT=T/n;
  U=exp(Sigma*sqrt(DeltaT));
  D=exp(-Sigma*sqrt(DeltaT));
  Pu=(exp(r*DeltaT)-D)/(U-D);
  Pd=1-Pu;
  //�p��payoff����{�����
  double CurrentS=S*pow(U,n);
  double CurrentProb=pow(Pu,n);
  double OptionValue=0;
  for(int i=0;i<=n;i=i+1)
  {
   OptionValue=OptionValue+exp(-r*T)*CurrentProb*Max(CurrentS-X,0);
   CurrentS=CurrentS*D/U;
   CurrentProb=CurrentProb*(n-i)/(i+1)*Pd/Pu;
  }
  //��X�������G
  printf("����v����=%f\n",OptionValue);

  system("pause");
  return 0;
}
