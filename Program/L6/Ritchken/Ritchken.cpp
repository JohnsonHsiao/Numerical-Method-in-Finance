#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Max(double a,double b)
{
  if(a>b)  return a;
  else return b;
}

double Min(double a,double b)
{
  if(a>b)  return b;
  else return a;
}

int main(){

  int i,j;
  //��J���
  float S,T,X,L,r,Sigma; 
  int n;  //����           
  printf("��J�Ъ�������:");
  scanf("%f",&S);
  printf("��J�����:");
  scanf("%f",&T);
  printf("��J�i������:");
  scanf("%f",&X);
  printf("��J��ê����:");
  scanf("%f",&L);
  printf("��J�L���I�Q�v:");
  scanf("%f",&r);
  printf("��J�Ъ�������i�ʲv:");
  scanf("%f",&Sigma);
  printf("��J����:");
  scanf("%d",&n);



	double dt=T/n;

	double tmp = log(S/L)/(Sigma*sqrt(dt));
	int Lindex = (int)floor(tmp);
	double lambda=tmp/Lindex;

	double R=exp(r*dt);
	double pu=1/(2*lambda*lambda)+(r-Sigma*Sigma/2.0)*sqrt(dt)/(2*lambda*Sigma);
	double pd=1/(2*lambda*lambda)-(r-Sigma*Sigma/2.0)*sqrt(dt)/(2*lambda*Sigma);
	double pm=1.0-pu-pd;
	double U=exp(lambda*Sigma*sqrt(dt));
	double D=1/U;

	//�p��̫�@����payoff
    double Array[1000];
	double CurrentS=S*pow(U,n);
	for(i=0;i<n+Lindex;i++)
	{
		Array[i]=Max(CurrentS-X,0);
		CurrentS=CurrentS*D;
	}
	Array[n+Lindex]=0;

	//Backward Induction
	for(j=n-1;j>=0;j--)
	{
		int i=0;
		for(i=0;i<Min(j+Lindex,2*j+1);i++)
		{
			Array[i]=(pu*Array[i]+pm*Array[i+1]+pd*Array[i+2])/R;
		}
		if(i==j+Lindex)	Array[i] = 0;
	}

	 //��X�������G
	 printf("�U��ê�X������v����=%f\n",Array[0]);
	// scanf("%d",&n);

  system("pause");
  return 0;
}
