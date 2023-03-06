#include <iostream>
#include <stdio.h>
#include <iostream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]){
	 // ��{�ȭp��
    int d,e;    
	float r,f;
	scanf("%d",&d);
	scanf("%d",&e);
	scanf("%f",&r);
    f=d/(1+r);
	f=f+e/((1+r)*(1+r));
	printf("Present value=%f\n",f);

	std::cout << "Press any key to continue...";
    std::cin.get();
    // 或者使用下面的代码：
    std::getchar();
    std::cout << "Continuing...";
	return 0;
}
