#include <iostream>
#include <stdio.h>
#include <cmath>

int main(int argc, char* argv[]){
	int a,b;
    double r; 
    printf("第一期本金(元):");
	scanf("%d",&a);
	printf("第二期本金(元):");
    scanf("%d",&b);
	printf("利息(%%):");
	scanf("%lf",&r);
    double result = a * pow(1+r/100, 2) + b * (1+r/100);
    printf("第二期末獲利=%lf元", result);
}