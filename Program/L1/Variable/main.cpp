#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]){
	//Part 1  
	//double xx;
	//scanf("%f",&xx);
	//printf("%lf",xx);
	int a,b;
    char c;
	scanf("%d",&a);
	printf("a=%d\n",a);
	// printf("b=%d\n",b);
	// Part 2   �ܼƳ]�w
	
	b=2;
    printf("b=%d\n",b);
    c=10;
    printf("c=%d\n",c);
	
	//Part 3 ��N�⦡���p��
    double d,e;
	d=1+a*b%2;
	printf("d=%lf\n",d);
	e=2/3;
    printf("e=%lf\n",e);
	e=2.0/3;
    printf("e=%lf\n",e);
	e=a/b;
    printf("e=%lf\n",e);
	e=double(a)/b;
    printf("e=%lf\n",e);
    
   //Part 4 �⦡��²�g
   
	a+=b;
    printf("a=%d\n",a);
	a+=(b-a);
    printf("a=%d\n",a);
	a++;
    printf("a=%d\n",a);
	a--;
    printf("a=%d\n",a);  
	
    //Part 5 �޿�⦡���p��
	
	double rate1=0.011, rate2=0.007;
	a=(rate1<0.01)&&(rate1>0.005);
    printf("a=%d\n",a); 
	a=(rate1<0.01)||(rate2<0.01);
    printf("a=%d\n",a);
	
	//  Part 6  �V�X�p��   
	int x=6, y=5;
    a=(x>=5)&&y<10;
    printf("a=%d\n",a);
    // a=!(x>10)+(!y);
	// printf("a=%d\n",a);
    // a=!x>10+!y;
    // printf("a=%d\n",a);

	// system("pause");
	return 0;
}
