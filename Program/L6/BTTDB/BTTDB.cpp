#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
//#include<sys/time.h>
#include<sys/timeb.h>
#include<math.h>
#include<time.h>
#define MAX_PERIOD 100000
#define SugPeriod 60
double r,T,n,v,S,X,H,L,q,x,val,h,l,p,u,d,t;
double pow(double,double);
double ceil(double);
double floor(double);
double log(double);
double exp(double);
double sqrt(double);
double C(double,double,double);
double N(double,double,double,double);
double CArray[MAX_PERIOD+1];

void CArrayInit() //////Compute Log(Combination)
{
 double mul,test;
 int k;
 CArray[0]=0;
 mul=0;
 for(k=1;k<=n;k++)
 {
  mul+=log(n+1-k);
  mul-=log(k*1.0);
  CArray[k]=mul;
  test=exp(mul);
 }
}
double C(double a1,double a2,double j)
{
  double mul,k;
  if(a1 < a2)
    mul=0; 
  else
    {
      mul=log(1.0);
      for(k=a2+1;k<=a1;k++)
         mul+=log(k);
      for(k=1;k<=a1-a2;k++)
         mul-=log(k);
      mul+=j*log(p)+(n-j)*log(1-p);
      mul=exp(mul);
    }
  return mul;
}
int NearInt(double a)
{
  int b;
  b=(int)a;
  if((a-b)>0.5)
	  b++;
  return b;
}
double N(double a,double b,double s,double j)
{
  int i,k;
  double nn,path,value;
  path=0;
  nn=n/(2*(h-l))+1;
  for(i=1;i<=nn;i++)
     {
       if(i%2==1)
         //path+=C(n,(n+a+b+(i-1)*s)/2,j)+C(n,(n-a-b+(i+1)*s)/2,j);
	   {
	    k=NearInt((n+a+b+(i-1)*s)/2);
		if(k<=n)
		{           ///////Compute Ai i=>odd
		 value=CArray[k];
		 value=value+j*log(p)+(n-j)*log(1-p);
         value=exp(value);
		 //test=C(n,(n+a+b+(i-1)*s)/2,j);
		 path+=value;
        }  
		k=NearInt((n-a-b+(i+1)*s)/2);
		if(k<=n)
        {     ///Compute Bi i=>odd
         value=CArray[k];
		 value=value+j*log(p)+(n-j)*log(1-p);
         value=exp(value);
		 //test=C(n,(n-a-b+(i+1)*s)/2,j);
	     path+=value;
		}
	   }
       else
        // path-=C(n,(n+a-b+i*s)/2,j)+C(n,(n-a+b+i*s)/2,j);
	   {
	    k=NearInt((n+a-b+i*s)/2);
		if(k<=n)
        {  //////Compute Ai i=>even
		 value=CArray[k];
		 value=value+j*log(p)+(n-j)*log(1-p);
         value=exp(value);
		 //test=C(n,(n+a-b+i*s)/2,j);
		 path-=value;
		}
		k=NearInt((n-a+b+i*s)/2);
		if(k<=n)
		{  /////Compute Bi i=>even
         value=CArray[k];
		 value=value+j*log(p)+(n-j)*log(1-p);
         value=exp(value);
		 //test=C(n,(n-a+b+i*s)/2,j);
	     path-=value;
		}
	   }
     }
  return path;
}
double CombinatorialVanillaCall()
{   //Time to maturity= T-TriDeltaT
   int Period;
   double OptionValue=0;
   double temp,Stock;
   for(Period=(int)n;Period>=0;Period--)
   {
	    Stock=S*pow(u,Period)*pow(d,n-Period);
        temp=CArray[Period];
		temp=temp+Period*log(p)+(n-Period)*log(1-p);
		if(Stock>=X)
		OptionValue+=exp(temp)*(Stock-X);
   }
   return OptionValue/exp(r*t*n);
}
int main()
{
  FILE *fp;
  double j,times,temp,Stock,Up,LogH,LogL;
  double OptionValue[3];   //memorize the three option values of the first period
  double OutOptionValue[3]; //Compute knock out option
  int xx;
  struct timeb start,end;
  fp=fopen("Result.txt","w");

  printf("Please input the annual interest rate in decimal = r.\nr==>");
  scanf("%lf",&r);
  fprintf(fp,"r=%f\n",r);
  printf("Please input the volatility = v.\nv==>");
  scanf("%lf",&v);
  fprintf(fp,"v=%f\n",v);
  printf("Please input the maturity in years = T.\nT==>");
  scanf("%lf",&T);
  fprintf(fp,"T=%f\n",T);
  printf("Please input the current stock price = S.\nS==>");
  scanf("%lf",&S);
  fprintf(fp,"S=%f\n",S);
  printf("Please input the strike price = X.\nX==>");
  scanf("%lf",&X);
  fprintf(fp,"X=%f\n",X);
  printf("Please input the high barrier = H.\nH==>");
  scanf("%lf",&H);
  LogH=log(H);
  fprintf(fp,"H=%f\n",H);
  printf("Please input the low barrier = L.\nL==>");
  scanf("%lf",&L);
  LogL=log(L);
  fprintf(fp,"L=%f\n",L);
  printf("Please input the continuous dividend yield in decimal = q.\nq==>");
  scanf("%lf",&q);
  fprintf(fp,"q=%f\n",q);
  double OriginalS=S;  //S  put to OriginalS
  ////   For Loop for number of time steps goes here
 for(int NN=25;NN<=10000;NN+=25)
 {
  n=NN;
  S=OriginalS;
  t=T/n;
  double C=ceil((LogH-LogL)/(2*v*sqrt(t)));
  t=pow((LogH-LogL)/(2*v*C),2);
  n=floor(T/t)-1;
  double TriDeltaT=T-t*n;
  double Mean=log(S)+(r-0.5*v*v)*TriDeltaT;
  double LogDistance=(LogH-Mean)/(v*sqrt(t));
  int NStep;  // represent the number of steps in integers.
  if(n-int(n)>0.5)  
	  NStep=int(n)+1;
  else NStep=int(n);
  double Shift;
  double LogSPrice; // Compute the relative log stock price for the following binomial tree
  if(NStep%2==0)
  {  //even step
    if(fmod(LogDistance,2.0)>1)
		Shift=1;
	 else Shift=0;
    LogSPrice=int(LogDistance)+Shift-2;
  }
  else
  {   // odd steps
     if(fmod(LogDistance-1,2)>1)
		Shift=1;
	 else Shift=0;
    LogSPrice=int(LogDistance)+Shift-2;
  }
  S=H/exp(v*sqrt(t)*LogSPrice);
  ftime(&start);
  //使用組合數學求 upper middle and lower node option value 存到 OptionValue[]中 
  for(int m=0;m<=2;m++)
  {
   u=exp(v*sqrt(t));
   d=exp(-v*sqrt(t));
   xx=(int)ceil(log(X/S)/(2*v*sqrt(t))+n/2);
   x=xx;
   h=ceil(log(H/S)/(2*v*sqrt(t))+n/2);
   l=floor(log(L/S)/(2*v*sqrt(t))+n/2);
   p=(exp((r-q)*t)-d)/(u-d);
   val=0;
   CArrayInit();
   Stock=S*pow(u,x)*pow(d,n-x);
   Up=pow(u,2.0);
   for(j=x;j<=n;j++)
   {
      if((j<=l)||(j>=h))
	  {  
        temp=CArray[NearInt(j)];
		temp=temp+j*log(p)+(n-j)*log(1-p);
		val+=exp(temp)*(Stock-X);
	  } 
      else  
        val+=N(2*h-n,2*(h-j),2*(h-l),j)*(Stock-X);
    Stock*=Up;   
   }
   val=val/exp(r*t*n);
 
  //fprintf(fp,"%4.0lf     %lf  %lf \n",n,val,CombinatorialVanillaCall());
  //fprintf(fp,"%4.0lf     %lf \n",n,val);
  OptionValue[m]=val;   
  OutOptionValue[m]=CombinatorialVanillaCall()-val;
  S=S*pow(d,2.0);
 }
  // Compute the discounted expected option value for the first step
  Mean=(r-0.5*v*v)*TriDeltaT;
  double Var=v*v*TriDeltaT;
  //Compute Alpha, beta, gamma  and the branching probabilities
  S=H/exp(v*sqrt(t)*LogSPrice);
  double Alpha=log(S/OriginalS)-Mean;
  S=S*pow(d,2.0);
  double Beta=log(S/OriginalS)-Mean;
  S=S*pow(d,2.0);
  double Gamma=log(S/OriginalS)-Mean;
  //Compute branching probabilities
  double Det=(Beta-Alpha)*(Gamma-Alpha)*(Gamma-Beta);
  double Pu=(Beta*Gamma+Var)*(Gamma-Beta)/Det;
  double Pm=(Alpha*Gamma+Var)*(Alpha-Gamma)/Det;
  double Pd=(Alpha*Beta+Var)*(Beta-Alpha)/Det;
  double DBOptionValue=exp(-r*TriDeltaT)*(Pu*OptionValue[0]+Pm*OptionValue[1]+Pd*OptionValue[2]);
  double DBOutOptionValue=exp(-r*TriDeltaT)*(Pu*OutOptionValue[0]+Pm*OutOptionValue[1]+Pd*OutOptionValue[2]);
  ftime(&end);
  if(start.millitm>end.millitm)
    times=(end.time-start.time-1)+(1000.0+end.millitm-start.millitm)/1000;
  else
    times=(end.time-start.time)+(double)(end.millitm-start.millitm)/1000; 
  fprintf(fp,"%lf\t %d\t %lf\t %lf\t %lf\t %lf\t %lf\t %3.9lf\n",times,NN,n,OptionValue[0],OptionValue[1],OptionValue[2],DBOptionValue,DBOutOptionValue);
  printf("%lf\t %d\t %lf\t %lf\t %lf\t %lf\t %lf\t\n",times,NN,n,OptionValue[0],OptionValue[1],OptionValue[2],DBOptionValue);
 }
  fclose(fp);

  system("pause");
  return 0;
}
