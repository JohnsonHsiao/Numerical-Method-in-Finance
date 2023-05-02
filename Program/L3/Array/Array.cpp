#include<stdio.h>
#include<stdlib.h>

int main()
{
   
   //變數宣告
	int l,m;
	float a;
    float IntFix[7];
    //資料存取:
    a=0.01;
    IntFix[0]=a;
    IntFix[1]=a+IntFix[0];
    //資料的輸入輸出
    scanf("%f",&IntFix[2]);
    printf("%f",IntFix[2]);
    


	//利率的輸入及定存的FV的計算
   printf("利率的輸入及定存的FV的計算\n");
	for(int i=0;i<7;i=i+1)
	{//利率資料輸入到陣列中,使用控制變數 i決定資料擺放位置
	 printf("IntFix[%d]=",i);
	 scanf("%f",&IntFix[i]);
	}
    a=1*(1+IntFix[0]/12);
	printf("一個月定存FV:%f\n",a);
	a=1*(1+IntFix[1]/4);
	printf("三個月定存FV:%f\n",a);
	a=1*(1+IntFix[2]/2);
	printf("六個月定存FV:%f\n",a);
	a=1*(1+IntFix[4]/2)*(1+IntFix[4]/2);
	printf("一年定存FV:%f\n",a);
	
    //二維陣列資料的使用
	
	printf("二維陣列資料的使用\n");
	 //變數宣告:
	
     float b[3][4];
      //資料存取:
     a=0.01;
     b[0][0]=a;
     b[0][1]=a+b[0][0];
     //資料的輸入輸出
     scanf("%f",&b[0][2]);
     printf("%f",b[0][2]);
        
	
     //使用巢狀迴圈輸入利率資料
	 printf("使用巢狀迴圈輸入利率資料\n");
	 float Int[2][7];
	 //利率輸入
	 for(l=0;l<7;l++)
	 {
	  for(m=0;m<2;m++)
	  {
	    printf("Int[%d][%d]=",m,l);
		scanf("%f",&Int[m][l]);
	  }
	 }
	 //利率列印
     printf("固定利率\n");
	 for(l=0;l<7;l++)
	 {
	  printf("Int[0][%d]=%f\n",l, Int[0][l]);
	 }
	 printf("機動利率\n");
	 for(l=0;l<7;l++)
	 {
	  printf("Int[1][%d]=%f\n",l, Int[1][l]);
	 }   
return 0;

}
