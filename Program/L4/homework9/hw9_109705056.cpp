#include <iostream>
#include "WriteHeader.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double BlackScholes(double S, double K, double r, double sigma, double T, char type)
{
    double d1 = (log(S/K) + (r + pow(sigma, 2) / 2) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);
    double Nd1 = Standard_Normal_Distribution(d1);
    double Nd2 = Standard_Normal_Distribution(d2);
    double result;
    
    if (type == 'C')
    {
        result = S * Nd1 - K * exp(-r * T) * Nd2;
    }
    else if (type == 'P')
    {
        result = K * exp(-r * T) * (1 - Nd2) - S * (1 - Nd1);
    }
    else
    {
        printf("Invalid option type.");
        result = 0;
    }
    
    return result;
}


int main()
{
    double S = 100;         // 現貨價格
    double K = 110;         // 行使價格
    double r = 0.05;        // 無風險利率
    double sigma = 0.2;     // 波動率
    double T = 1;           // 到期時間（以年為單位）
    char type = 'C';        // 買權
    
    double option_price = BlackScholes(S, K, r, sigma, T, type);
    
    printf("Option price: %lf", option_price);
    
    return 0;
}
