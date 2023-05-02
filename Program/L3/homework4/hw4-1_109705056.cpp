#include <iostream>
#include <cmath>

double calculateBondPrice(double FV, double c, int n, double ytm) {
    double bondPrice = 0.0;
    for (int i = 1; i <= n; ++i) {
        bondPrice += c / std::pow(1 + ytm, i);  //將利息折現
    }
    bondPrice += FV / std::pow(1 + ytm, n);  //將面額折現
    return bondPrice;
}

double newYTM(double FV, double c, int n, double p) {
    double epsilon = 0.0001;
    double lower = 0.0;
    double upper = 1.0;
    double ytm = (lower + upper) / 2.0;
    double diff = calculateBondPrice(FV, c, n, ytm) - p;
    
    while (std::abs(diff) > epsilon) {
        if (diff < 0) {
            upper = ytm;
        } 
        else {
            lower = ytm;
        }
        ytm = (lower + upper) / 2.0;
        diff = calculateBondPrice(FV, c, n, ytm) - p;
    }
    return ytm;
}

int main() {
    double FV; // Face value
    double c ; // 利息
    int n ; // 期數
    double p ; // 價格
    double r ; // Risk-free interest rate
    scanf("%lf",FV);
    scanf("%lf",c);
    scanf("%d",n);
    scanf("%lf",p);
    scanf("%lf",r);

    double ytm = newYTM(FV, c, n, p);
    double yieldSpread = ytm - r;

    std::cout << "Yield Spread (S): " << yieldSpread << std::endl;

    return 0;
}
