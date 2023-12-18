#include <stdio.h>
#include <stdlib.h>
#include "halton.h"
//#include "Moro.h"
#include "PJA.h"
#include <math.h>
#define MAX_DIM_NUM 20
int main()
{
 double ma[MAX_DIM_NUM][1000];     //�s��üƪ��e��
 int     dim_times=1000;  //�C��dimension�ݭn1000�Ӷü�
 int     dim_num=20;      //�ݭn20 dimensions
 int     step=10;         //�C��dimension�q��10�ӭȶ}�l
 double  r[MAX_DIM_NUM];      //�p��üƪ��e��
 FILE* Write=fopen("T.txt","w"); 
 halton_ndim_set ( dim_num );//�]�w dimension numbers
 halton_step_set ( step );//�]�w�ĴX�ӭȶ}�l 
 

 for (int i = 0; i <dim_times; i++ )
 {      
	 halton( r );                 //����1~20 dimension ����10�ӭ�
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
