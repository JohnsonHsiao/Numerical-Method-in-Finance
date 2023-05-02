#include <iostream>
#include <cmath>
#include <stdlib.h>

double principal = 1000, S[] = {5, 10, 20, 20};
int n = sizeof(S) / sizeof(S[0]);
double lower = 0, upper = 1, tolerance = 0.00001; //將誤差縮至10^(-6)

double calc_price(double r) {
    double price = 0;

    for (int i = 1; i <= n; i++) {
        price += S[i-1] / pow(1 + r, i);
    }
    price += principal / pow(1 + r, n);
    return price;
}

double bisection(double lower, double upper, double tolerance) {
    double mid = (lower + upper) / 2;
    
    while (abs(upper - lower) > tolerance) {
        double tmp_a = calc_price(lower) - principal;
        double tmp_b = calc_price(upper) - principal;
        double tmp_c = calc_price(mid) - principal;
        if (tmp_c == 0) {
            return mid;
        } else if (tmp_a * tmp_c < 0) {
            upper = mid;
        } else if (tmp_b * tmp_c < 0) {
            lower = mid;
        }
        mid = (lower + upper) / 2;
    }
    return mid;
}

int main(int argc, char *argv[]){
    double r = bisection(lower, upper, tolerance);

    printf("The fix rate is: %lf\n", r);

    return 0;
}