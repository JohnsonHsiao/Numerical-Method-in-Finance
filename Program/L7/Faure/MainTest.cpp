#include <stdio.h>
#include <stdlib.h>
#include "faure.h"
#include "Moro.h"
#include "PJA.h"
#define MAX_DIM_NUM 20
int main()
{
 double ma[20][1000];     //存放亂數的容器
 int     dim_times=1000;  //每個dimension需要1000個亂數
 int     dim_num=20;      //需要20 dimensions
 int     seed=-1;            //每個dimension從第seed值開始
                            //if  Seed<0.....start (qs)^(4)-1 -->qs   means base
                            //if  Seed>0.....start seed
 double  r[MAX_DIM_NUM];      //計算亂數的容器
 FILE* Write=fopen("T.txt","w"); 
  for (int i = 0; i <dim_times; i++ )
  {      
	   faure ( dim_num, &seed, r ); //產生1~20 dimension 的第seed個值
       for(int k=0;k<dim_num;k++)   //將產生的亂數向量存入 自己的容器    
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
