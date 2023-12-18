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
  //輸入資料
  float S,T,X,L,r,Sigma; 
  printf("輸入標的物價格:");
  scanf("%f",&S);
  printf("輸入到期日:");
  scanf("%f",&T);
  printf("輸入履約價格:");
  scanf("%f",&X);
  printf("輸入障礙價格:");
  scanf("%f",&L);
  printf("輸入無風險利率:");
  scanf("%f",&r);
  printf("輸入標的物價格波動率:");
  scanf("%f",&Sigma);


    //計算AMM樹的相關參數
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

	//配置所需陣列空間
	double CArr[30000];
	double tempArr[3];

	//計算最後一期的payoff
	double CurrentS=S*exp(n*h);//計算粗三元樹在起始價之上之節點值(不含lnS')
	for(int i=0;i<n;i++){ 
		CArr[i]=Max(0,CurrentS-X);
		CurrentS = CurrentS*exp(-h);
	}

	CurrentS = S;//計算細三元樹的節點值(含lnS')
	for(i=n;i<n+2;i++){ 
		CArr[i] = Max(0,CurrentS-X);
		CurrentS = CurrentS*exp(-h/pow(2.0,i-n+1));
	}


	double pu2,pd2,pm2;
	for(j=n-1;j>=0;j--){
		//計算粗三元樹(包含lnS')的節點值
		for(i=0;i<j;i++){
			CArr[i]=(pu*CArr[i]+pm*CArr[i+1]+pd*CArr[i+2])/R;
		}

		//暫存計算細三元樹節點所需資訊
		for( i=0;i<3;i++){ 
			tempArr[i] = CArr[j+i];
		}
		
		//利用appraochArr來計算粗三元樹在lnS'之下(不含lnS')的節點值
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

		//複製細三元樹的計算結果至粗三元樹的相對應節點
		for( i=1;i<3;i++){ //tempArr[0]不需複製
			CArr[j+(i-1)] = tempArr[i];
		}		
	}

	 //輸出評價結果
	 printf("下障礙出局選擇權價格=%f\n",CArr[1]);
	 //scanf("%d",&n);

	system("pause");
	return 0;
}
