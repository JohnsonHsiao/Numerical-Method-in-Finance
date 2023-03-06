#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int main()
{
	printf("hello world\n");
	
	printf("my first program\n");
	// system("pause\n");
	std::cout << "Press any key to continue...";
    std::cin.get();
    // 或者使用下面的代码：
    // std::getchar();
    std::cout << "Continuing...";
    return 0;
}
