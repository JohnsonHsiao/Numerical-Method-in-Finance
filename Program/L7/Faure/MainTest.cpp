#include <stdio.h>
#include <stdlib.h>
#include "faure.h"
#include "Moro.h"
#include "PJA.h"
#define MAX_DIM_NUM 20
int main()
{
 double ma[20][1000];     //�s��üƪ��e��
 int     dim_times=1000;  //�C��dimension�ݭn1000�Ӷü�
 int     dim_num=20;      //�ݭn20 dimensions
 int     seed=-1;            //�C��dimension�q��seed�ȶ}�l
                            //if  Seed<0.....start (qs)^(4)-1 -->qs   means base
                            //if  Seed>0.....start seed
 double  r[MAX_DIM_NUM];      //�p��üƪ��e��
 FILE* Write=fopen("T.txt","w"); 
  for (int i = 0; i <dim_times; i++ )
  {      
	   faure ( dim_num, &seed, r ); //����1~20 dimension ����seed�ӭ�
       for(int k=0;k<dim_num;k++)   //�N���ͪ��üƦV�q�s�J �ۤv���e��    
	   {
		 r[k]=ltqnorm(r[k]);
		 ma[k][i]=r[k];              
		 fprintf(Write,"%lf\t",r[k]);
	   }
      fprintf(Write,"\n");
  }   

 fclose(Write);

 system("pause");
 return 0;
}
