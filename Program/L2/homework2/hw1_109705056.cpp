#include <iostream>
#include <stdio.h>


int main(int argc, char** argv){
	double a,b,c; //宣告rate1,rate2,rate3的儲存變數

    printf("請輸入rate1:");
    scanf("%lf" , &a);
    printf("請輸入rate2:");
    scanf("%lf" , &b);
    printf("請輸入rate3:");
    scanf("%lf" , &c);

    double q = (a > 0.01) + (b > 0.01) + (c > 0.01); //q為題目所說大於0.01的rate數量
    double Payoff; // 宣告Payoff
    if(q >= 2) 
        Payoff = q/2 * 100.5;
    else
        Payoff = 70;
    printf("%lf\n",Payoff);
}