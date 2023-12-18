#include<sys/types.h>  //Pricing Vanilla option by Eliminating nonlinear error
//#include<sys/time.h>
#include<sys/timeb.h>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_PERIOD 100000
double r,T,n,v,S,X,q,x,val,p,u,d,t;
double pow(double,double);
double ceil(double);
double floor(double);
double log(double);
double exp(double);
double sqrt(double);
double C(double,double,double);
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

inline double MAX(double x, double y)
{
  if( x>y) 
	  return x;
  else return y;
}

inline double DET(double x1,double x2,double x3,double x4,double x5,double x6,double x7,double x8,double x9)
{
    /*    x1   x2 x3
	      x4   x5 x6
		  x7   x8 x9   */
	
	return x1*x5*x9+x2*x6*x7+x3*x4*x8-x3*x5*x7-x1*x6*x8-x2*x4*x9;
}

int main()
{
  FILE *fp;
  double times,LogX;
  //double OptionValue[3];   //memorize the three option values of the first period
  double OutOptionValue[3]; //Compute knock out option
  struct timeb start,end;
  int IsCall;
  fp=fopen("Result.txt","w");
  printf("0 for put, Others for call==>");
  scanf("%d",&IsCall);
  fprintf(fp,"Option Type=%d",IsCall);
  printf("\nPlease input the annual interest rate in decimal = r.\nr==>");
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
  LogX=log(X);
  //printf("Please input the high barrier = H.\nH==>");
  //scanf("%lf",&H);
  //LogH=log(H);
  //fprintf(fp,"H=%f\n",H);
  //printf("Please input the low barrier = L.\nL==>");
  //scanf("%lf",&L);
  //LogL=log(L);
  //fprintf(fp,"L=%f\n",L);
  printf("Please input the continuous dividend yield in decimal = q.\nq==>");
  scanf("%lf",&q);
  fprintf(fp,"q=%f\n",q);
  double OriginalS=S;  //S  put to OriginalS
  ////   For Loop for number of time steps goes here
  for( n=150;n<=400;n+=1)
  {
    S=OriginalS;
    t=T/n;
    double Mean=log(S)+(r-q-0.5*v*v)*t;
    double LogDistance=(Mean-LogX)/(v*sqrt(t));
    double LogSPrice; // Compute the relative log stock price for the following binomial tree
    int NStep=int(n+0.00000001)-1;
	int Shift;
	if(NStep%2==0)
	{  //even step
     /*if(fmod(LogDistance,2.0)>1)
		   Shift=0;  
	  else if (fmod(LogDistance,2.0)<-1)
		   Shift=0; 
	  else if(LogDistance>0) Shift=1;  
	     else Shift=-1;
	   */ 
	 //The latter makes X exactly hit the node
	  if(fmod(LogDistance,2.0)>1)
		   Shift=1;
	  else if (fmod(LogDistance,2.0)<-1)
		 Shift=-1;
	  else 
	   Shift=0;
		 
	
     LogSPrice=int(LogDistance)+Shift+2;
	}
    else
	{   // odd steps
        /*if(fmod(LogDistance,2.0)>1)
		   Shift=1;
	     else if (fmod(LogDistance,2.0)<-1)
		   Shift=-1;
	     else  
		  Shift=0;*/
	 if((0<LogDistance)&&(LogDistance<1))   //The latter makes X exactly hit the node
		  Shift=1;
     else if(fmod(LogDistance-1,2)>1)
		  Shift=1;
	 else if (fmod(LogDistance-1,2.0)<-1)
		  Shift=-1; 
	 else Shift=0;
     LogSPrice=int(LogDistance)+Shift+2;
	}
	//int Tempn=int(n+0.00000001);
	//n--;
	//CArrayInit();
	S=X*exp(v*sqrt(t)*LogSPrice);
	ftime(&start);
    for(int m=0;m<=2;m++)
	{
      u=exp(v*sqrt(t));
	  double Up=pow(u,2.0);
      d=exp(-v*sqrt(t));
      //x=ceil(log(X/S)/(2*v*sqrt(t))+n/2);
      //l=floor(log(L/S)/(2*v*sqrt(t))+n/2);
      p=(exp((r-q)*t)-d)/(u-d);
      val=0;
	  double Stock=S*pow(u,NStep);
	  double LogProb=NStep*log(p);
      for(int j=int(NStep);j>=0;j--)
	  {
		if(IsCall)
		{
		  if(fabs(Stock-X)>0.0000001)
			val+=exp(LogProb)*MAX(Stock-X,0);
		   else
		   { /// Adjust the nonlinear error: First order
             //double Alpha=Stock*d;
			 //double Mu=(r-q-0.5*v*v)*NStep*t;
			 //double XX=log(Alpha/S)-Mu;
			 //double Sigma=v*sqrt(NStep*t);
			 //double PPrime=1/(sqrt(2*3.1415926)*Sigma)*exp(-pow(XX-Mu,2.0)/(2*Sigma*Sigma))*(XX-Mu)/(-Sigma*Sigma);
			 //double Slope=PPrime/Alpha;
			 //double L=Stock*u-Stock*d;
			 //double temp=exp(LogProb);
			 //double H=(exp(LogProb)-L*L*Slope/2)/(L);
			 //val+=(Slope*pow(Stock*u,3.0)/3+(H-Slope*X-Slope*X*d)*pow(Stock*u,2.0)/2+(Slope*X*X*d-H*X)*Stock*u);
			 //val-=(Slope*pow(Stock,3.0)/3+(H-Slope*X-Slope*X*d)*pow(Stock,2.0)/2+(Slope*X*X*d-H*X)*Stock);
             //////////Adjust nonlinear error: Second order
			 //double Mu=(r-q-0.5*v*v)*NStep*t;
			 //double Sigma=v*sqrt(NStep*t);
			 //double PXu =1/(sqrt(2*3.1415926)*Sigma)*exp(-pow(X*u      -Mu,2.0)/(2*Sigma*Sigma))/(X*u);
			 //double PXSU=1/(sqrt(2*3.1415926)*Sigma)*exp(-pow(X*sqrt(u)-Mu,2.0)/(2*Sigma*Sigma))/(X*sqrt(u));
			 //double PX  =1/(sqrt(2*3.1415926)*Sigma)*exp(-pow(X        -Mu,2.0)/(2*Sigma*Sigma))/(X);
			 //double Det =DET(pow(X*u      ,2.0),X*u        ,1,
			//	             pow(X*sqrt(u),2.0),X*sqrt(u)  ,1,
			//				 pow(X        ,2.0),X          ,1);
			// double DetA=DET(PXu               ,X*u        ,1,
			//	             PXSU              ,X*sqrt(u)  ,1,
			//				 PX                ,X          ,1);
			// double DetB=DET(pow(X*u      ,2.0),PXu        ,1,
			//	             pow(X*sqrt(u),2.0),PXSU       ,1,
			//				 pow(X        ,2.0),PX         ,1);
			// double DetC=DET(pow(X*u      ,2.0),X*u        ,PXu,
			//	             pow(X*sqrt(u),2.0),X*sqrt(u)  ,PXSU,
			//				 pow(X        ,2.0),X          ,PX);
            // double A=DetA/Det;
			// double B=DetB/Det;
			// double C=DetC/Det;
            // val+=A*pow(X*u,4.0)/4+(B-A*X)*pow(X*u,3.0)/3+(C-B*X)*pow(X*u,2.0)/2-C*X*X*u;
			// val-=A*pow(X  ,4.0)/4+(B-A*X)*pow(X  ,3.0)/3+(C-B*X)*pow(X  ,2.0)/2-C*X*X  ;

			  val+=exp(LogProb)/4*MAX((Stock*u+Stock)/2-X,0); 
		   }
		}
		else
		{
		  if(fabs(X-Stock)>0.0000001)
			val+=exp(LogProb)*MAX(X-Stock,0);
		  else
		  {
            val+=exp(LogProb)/4*MAX(X-(Stock*d+Stock)/2,0); 
		  }
		}
        LogProb=LogProb-log(p)+log(1-p)+log(j*1.0)-log((NStep+1-j)*1.0);  
		Stock/=Up;
	  }
      val/=exp(r*NStep*t);		
	  OutOptionValue[m]=val;
	  S=S*pow(d,2.0);
	}
      // Compute the discounted expected option value for the first step
      Mean=(r-q-0.5*v*v)*t;
      double Var=v*v*t;
      //Compute Alpha, beta, gamma  Use the same definition as in the stair tree paper
      S=X*exp(v*sqrt(t)*LogSPrice);
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
      //double DBOptionValue=exp(-r*TriDeltaT)*(Pu*OptionValue[0]+Pm*OptionValue[1]+Pd*OptionValue[2]);
      double DBOutOptionValue=exp(-r*t)*(Pu*OutOptionValue[0]+Pm*OutOptionValue[1]+Pd*OutOptionValue[2]);
      ftime(&end);
      if(start.millitm>end.millitm)
       times=(end.time-start.time-1)+(1000.0+end.millitm-start.millitm)/1000;
      else
       times=(end.time-start.time)+(double)(end.millitm-start.millitm)/1000; 
      fprintf(fp,"%lf\t %lf\t %lf\t %lf\t %lf\t  %3.9lf\n",times,n,OutOptionValue[0],OutOptionValue[1],OutOptionValue[2],DBOutOptionValue);
      printf("%lf\t %lf\t %lf\t %lf\t %lf\t %lf\t\n",times,n,OutOptionValue[0],OutOptionValue[1],OutOptionValue[2],DBOutOptionValue);
   //n=Tempn;
  }
  fclose(fp);

  system("pause");
  return 0;
}
