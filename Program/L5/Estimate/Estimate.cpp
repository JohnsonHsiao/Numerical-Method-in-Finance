#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
  FILE* Read=fopen("Read.txt","r");
  char Name[4][20], Date[20];
  float Index[3];
  fscanf(Read,"%s %s %s", Name[0],Name[1],Name[2]); 
  fscanf(Read,"%s %s %s %s", Name[0],Name[1],Name[2],Name[3]);
  double Mu1,Mu2,Sigma1Square,Sigma2Square,Sigma12;
  double S1,S2,r1,r2;
  double r1Sum=0,r2Sum=0,r1Square=0,r2Square=0,r1r2Sum=0;
  double Tau=1/250.0;
  int m=0,First=1;
  
  while(fscanf(Read,"%s %f %f %f",Date,&Index[0],&Index[1],&Index[2])!=EOF)
  {
    if(First)
	{
     S1=Index[0];
	 S2=Index[1];
	 First=0;
	 continue;
	}
	///連續報酬率
    r1=log(Index[0]/S1);
	r2=log(Index[1]/S2);
	///離散報酬率
    // r1=(Index[0]-S1)/S1;
	// r2=(Index[1]-S2)/S2;
	r1Sum=r1Sum+r1;
	r1Square=r1Square+r1*r1;
	r2Sum=r2Sum+r2;
	r2Square=r2Square+r2*r2;
	r1r2Sum=r1r2Sum+r1*r2;
    S1=Index[0];
	S2=Index[1];
    m=m+1;
  }
  Mu1=r1Sum/(m*Tau);
  Mu2=r2Sum/(m*Tau);
  Sigma1Square=(r1Square/(m-1)-r1Sum*r1Sum/(m*(m-1)))/Tau;
  Sigma2Square=(r2Square/(m-1)-r2Sum*r2Sum/(m*(m-1)))/Tau;
  Sigma12=r1r2Sum/((m-1)*Tau)-r1Sum*r2Sum/(m*(m-1)*Tau);
  printf("平均報酬率向量= (%lf,%lf)\n",Mu1,Mu2);
  printf("共變異數矩陣:\n%lf\t%lf\n%lf\t%lf\n",Sigma1Square,Sigma12,Sigma12,Sigma2Square);
  fclose(Read);

system("pause");
return 0;
}
