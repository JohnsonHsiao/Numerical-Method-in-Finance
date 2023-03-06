#include <iostream>
#include <stdio.h>


int main(int argc, char** argv){
	int a;
    double b;
    char c; 

    // a = 2.4; 因為a在先前被指定為int
    a = int(2.4);//所以在這裡強行把2.4轉成int放在a中
    scanf("%lf" , &b);//原本後面只有b，需要將值用&傳到b的位址
    scanf("%c" , &c);//c是char但是%lf是來表示double
    printf("%lf" , b);//%d用來表int
    printf("%lf" , b);//&b用來表位址而不是值
}


