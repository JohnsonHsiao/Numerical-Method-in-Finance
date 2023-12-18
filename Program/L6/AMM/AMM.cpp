#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Max(double a,double b)
{
  if(a>b)  return a;
  else return b;
}


double Round(double a)
{
    if(a-floor(a)>=0.5)
		return ceil(a);
	else
		return floor(a);
}

double Pu(double h,double k,double Sigma,double r)
{
	double alpha = r - Sigma*Sigma/2;
	return (Sigma*Sigma*(k/(h*h))+alpha*alpha*(k*k/(h*h))+alpha*(k/h))/2;
}

double Pd(double h,double k,double Sigma,double r)
{
	double alpha = r - Sigma*Sigma/2;
	return (Sigma*Sigma*(k/(h*h))+alpha*alpha*(k*k/(h*h))-alpha*(k/h))/2;
}

int main()
{

  int i,j;
  //��J���
  float S,T,X,L,r,Sigma; 
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


    //�p��AMM�𪺬����Ѽ�
	double h = 2*(log(S/L));
	double lambda = 3.;
	int n= (int)Round((lambda*Sigma*Sigma*T)/(h*h)); //# time partitions
	double k = T/n;
	lambda = (h*h)/(Sigma*Sigma*k);
	S = L*exp(h);
	
	double R=exp(r*k);
	double pu=Pu(h,k,Sigma,r);
	double pd=Pd(h,k,Sigma,r);
	double pm=1.0-pu-pd;

	//�t�m�һݰ}�C�Ŷ�
	double CArr[30000];
	double tempArr[3];

	//�p��̫�@����payoff
	double CurrentS=S*exp(n*h);//�p��ʤT����b�_�l�����W���`�I��(���tlnS')
	for(int i=0;i<n;i++){ 
		CArr[i]=Max(0,CurrentS-X);
		CurrentS = CurrentS*exp(-h);
	}

	CurrentS = S;//�p��ӤT���𪺸`�I��(�tlnS')
	for(i=n;i<n+2;i++){ 
		CArr[i] = Max(0,CurrentS-X);
		CurrentS = CurrentS*exp(-h/pow(2.0,i-n+1));
	}


	double pu2,pd2,pm2;
	for(j=n-1;j>=0;j--){
		//�p��ʤT����(�]�tlnS')���`�I��
		for(i=0;i<j;i++){
			CArr[i]=(pu*CArr[i]+pm*CArr[i+1]+pd*CArr[i+2])/R;
		}

		//�Ȧs�p��ӤT����`�I�һݸ�T
		for( i=0;i<3;i++){ 
			tempArr[i] = CArr[j+i];
		}
		
		//�Q��appraochArr�ӭp��ʤT����blnS'���U(���tlnS')���`�I��
		for(int jj=0;jj<4;jj++){ 
			pu2 = Pu(h/2,k/4,Sigma,r);
			pd2 = Pd(h/2,k/4,Sigma,r);
			pm2 = 1.0 - pu2 - pd2;

			tempArr[2] = (pu2*tempArr[1]+pm2*tempArr[2]+pd2*0)/exp(r*k/4);
	
			pu2 = Pu(h,k*(jj+1)/4,Sigma,r);
			pd2 = Pd(h,k*(jj+1)/4,Sigma,r);
			pm2 = 1.0 - pu2 - pd2;
			tempArr[1] = (pu2*tempArr[0]+pm2*CArr[j+1]+pd2*0)/exp(r*k*(jj+1)/4);
			
		}

		//�ƻs�ӤT���𪺭p�⵲�G�ܲʤT���𪺬۹����`�I
		for( i=1;i<3;i++){ //tempArr[0]���ݽƻs
			CArr[j+(i-1)] = tempArr[i];
		}		
	}

	 //��X�������G
	 printf("�U��ê�X������v����=%f\n",CArr[1]);
	 //scanf("%d",&n);

	system("pause");
	return 0;
}
