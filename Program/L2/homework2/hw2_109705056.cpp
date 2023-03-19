#include <iostream>
#include <stdio.h>

bool first_part(){
    bool first;
    std::cout << "先修學分是否通過:" ;
    std::cin >> first;
    return first;
}

bool second_part(){
    bool a,b,c,d,e,f,g,h,i,j,flag;

    std::cout <<"財務管理是否通過（必修）:";
    std::cin >> a;
    std::cout <<"投資學是否通過（必修）:" ;
    std::cin >> b;
    std::cout <<"期貨選擇權是否通過（必修）:";
    std::cin >> c;
    std::cout <<"財務計量經濟學是否通過（必修）:";
    std::cin >> d;
    std::cout <<"金融機構與市場是否通過（必修）:";
    std::cin >> e;
    std::cout <<"財務數學是否通過（必修）:";
    std::cin >> f;
    std::cout <<"衍生性商品理論是否通過（必修）:";
    std::cin >> g;
    std::cout <<"財務理論與實務是否通過（必修）:";
    std::cin >> h;
    std::cout <<"碩士論文研究是否通過（必修）:";
    std::cin >> i;
    std::cout <<"選修課程15學分是否通過(選修):";;
    std::cin >> j;

    flag = a && b && c && d && c && d && e && f && g && h && i && j;
    return flag;
}

bool third_part(){
    bool essay;
    std::cout <<"碩士論文是否通過：";
    std::cin >> essay;
    return essay;
}
int main(int argc, char** argv){
    std::cout <<"請輸入布林值(1 or 0)" << std::endl;
    bool x,y,z;
    x = first_part();
	y = second_part();
    z = third_part();
    if(x && y && z)
    {
        printf(" ----------------\n");
        std::cout <<"|  滿足畢業條件  |" << std::endl;
        printf(" ----------------");
    }
    else
    {
        if(x && y){
            printf(" --------------------\n");
            printf("|  碩士論文未通過  |\n");
            printf(" --------------------");
        }
        else if(x && z){
            printf(" ---------------------\n");
            printf("|  必選修課程未通過  |\n");
            printf(" ---------------------");
        }
        else if(y && z){
            printf(" --------------------\n");
            printf("|   先修課程未通過  |\n");
            printf(" --------------------");
        }
        else if(x){
            printf(" -----------------------------\n");
            printf("|  必選修課程和碩士論文未通過  |\n");
            printf(" -----------------------------");   
        }
        else if(y){
            printf(" ----------------------------\n");
            printf("|  先修課程和碩士論文未通過  |\n");
            printf(" ----------------------------");
        }
        else if(z){
            printf(" -----------------------------\n"); 
            printf("|  先修課程和必選修課程未通過  |\n");
            printf(" -----------------------------");
        }
        else{
            printf(" -------------------------\n"); 
            printf("|  全！部！都！沒！過！  |\n");
            printf(" -------------------------");
        }
    }

}