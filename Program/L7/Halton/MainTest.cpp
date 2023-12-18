#include <stdio.h>
#include <stdlib.h>
#include "halton.h"
//#include "Moro.h"
#include "PJA.h"
#include <math.h>
#define MAX_DIM_NUM 20
int main()
{
 double ma[MAX_DIM_NUM][1000];     //存放亂數的容器
 int     dim_times=1000;  //每個dimension需要1000個亂數
 int     dim_num=20;      //需要20 dimensions
 int     step=10;         //每個dimension從第10個值開始
 double  r[MAX_DIM_NUM];      //計算亂數的容器
 FILE* Write=fopen("T.txt","w"); 
 halton_ndim_set ( dim_num );//設定 dimension numbers
 halton_step_set ( step );//設定第幾個值開始 
 

 for (int i = 0; i <dim_times; i++ )
 {      
	 halton( r );                 //產生1~20 dimension 的第10個值
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
