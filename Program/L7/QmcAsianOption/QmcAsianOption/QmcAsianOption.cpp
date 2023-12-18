// QmcAssianOption.cpp : Defines the entry point for the console application.
//
//#include <iostream.h>
#include "Stdafx.h"
#include "sobol.h"

#include <stdlib.h>
#include  <conio.h>
#include  <math.h>

double Moro(double);       //盢Uniform dist. 锣传Θ Standard Normal dist.
double Max(double,double); 


double sobol[52][1000];    
int    m=52,n=1000;
float  sobolrow[52];
int    seed=16;

int main()
{ 

  
   //玻ネsobol计 
   for (int i = 0; i <n; i++ )
   {      
	i4_sobol (m, &seed,sobolrow ); 
    for(int j=0;j<m;j++)     
      sobol[j][i]=sobolrow[j];      
   } 

//trans to normal
    for(int  i=0;i<n;i++)
	{
	  for(int j=0;j<m;j++)
	  {
		sobol[j][i]=Moro(sobol[j][i]);//盢sobol计锣传Θstandard normal dist.
	  }
	}
//籜霉家览

   double S=100,T=1,X=100,r=0.1,Sigma=0.3; 
   double OptionValue=0;
   double SquareSum=0;
   double DT=T/m;
   for(int i=0;i<n;i++)
   {
	double ST=S;
	double Sum=ST;
	for(int j=1;j<=m;j++)
	{		
		ST=ST*exp((r-Sigma*Sigma/2)*DT+Sigma*sqrt(DT)*sobol[j][i]);
	    Sum=Sum+ST; 
	}
	double Avg=Sum/(m+1); 
	double Payoff=exp(-r*T)*Max(Avg-X,0);
    OptionValue=OptionValue+Payoff;
	SquareSum=SquareSum+pow(Payoff,2);
   }
   OptionValue=OptionValue/n;
   double STDERR=sqrt((SquareSum/n-pow(OptionValue,2))/n);
   printf("Value=%f, Standard Err~%f\n",OptionValue,STDERR);

   system("pause");
   return 0; 
}


//---------------------------Max----------------------//  
double Max(double a,double b)
{
 if(a>b) return a;
 else return b;
}
//--------------------------endMax--------------------//
//--------------------------moro----------------------//
static double A[4]={
          2.50662823884,
       -18.61500062529,
        41.39119773534,
       -25.44106049637
  };
static double B[4]={
       -8.47351093090,
       23.08336743743,
     -21.06224101826,
        3.13082909833
    };
static double C[9]={
   0.3374754822726147,
   0.9761690190917186,
   0.1607979714918209,
   0.0276438810333863,
   0.0038405729373609,
   0.0003951896511919,
   0.0000321767881768,
   0.0000002888167364,
   0.0000003960315187
   };
double Moro(double U)
{
// Returns the inverse of the cumulative normal distribution

double X,R;

X=U-0.5;
if (fabs(X)<0.42)
   {
      R=X*X;
      R=X*(((A[3]*R+A[2])*R+A[1])*R+A[0])/
          ((((B[3]*R+B[2])*R+B[1])*R+B[0])*R+1.0);
     return(R);
   }

R=U;
if (X>0.) R=1.0-U;
   
   R=log(-log(R));
   R=C[0]+R*(C[1]+R*(C[2]+R*(C[3]+R*(C[4]+
       R*(C[5]+R*(C[6]+R*(C[7]+R*C[8])))))));
   if (X<0.0) R=-R;
return(R);
 }            
//--------------------------endmoro----------------------//
