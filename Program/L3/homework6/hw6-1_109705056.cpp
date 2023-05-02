#include<stdio.h>
#include<stdlib.h>
#include <cmath>
const int MATRIX_SIZE=3;

int main()
{
    int i,j;
    double X[MATRIX_SIZE];
    double y[MATRIX_SIZE] = { 0 };
    printf("輸入資產配置\n");
    for(i=0;i<MATRIX_SIZE;i++)
    {
	    printf("第%d個資產:",i+1);
        scanf("%lf",&X[i]);
    }
    ///共變異數矩陣
    double S[MATRIX_SIZE][MATRIX_SIZE];
    printf("輸入共變異數矩陣\n");
    for(i=0;i<MATRIX_SIZE;i++)
    {
        for(j=0;j<=i;j++)
	    {
	        printf("第%d和第%d個資產的共變異度=",i+1,j+1);
	        scanf("%lf",&S[i][j]);
	        S[j][i]=S[i][j];
	    }
    }
    // 計算 y = S*X
    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            y[i] += S[i][j] * X[j];
        }
    }
    // 計算 Var(R_p) = X^T * y
    double Var_Rp = 0;
    for (i = 0; i < MATRIX_SIZE; i++)
    {
        Var_Rp += X[i] * y[i];
    }
    printf("投資組合的變異度為 %lf \n", Var_Rp);
    printf("95%信心水準下的VaR %lf", -1.645 * sqrt(Var_Rp));
    return 0;
}