#include <iostream>
#include <cmath>

//計算債券價格，用for迴圈折現
double calculate_bond_price(int n, double c, double r) {
    double bond_price = 0.0;
    for (int t = 1; t <= n; ++t) {
        bond_price += (100 * c) / pow(1 + r, t);
    }
    bond_price += 100 / pow(1 + r, n);
    return bond_price;
}

//計算marcaulay duration用r折現每一期的利息並加權
double calculate_macaulay_duration(int n, double c, double r) {
    double macaulay_duration = 0.0;
    double bond_price = calculate_bond_price(n, c, r);

    for (int t = 1; t <= n; ++t) {
        macaulay_duration += (t * (100 * c)) / pow(1 + r, t);
    }
    macaulay_duration += n * 100 / pow(1 + r, n);
    macaulay_duration /= bond_price;

    return macaulay_duration;
}

int main() {
    int n;
    double c, r;

    std::cout << "請輸入期數 (n): ";
    std::cin >> n;

    std::cout << "請輸入票面利率 (c): ";
    std::cin >> c;

    std::cout << "請輸入折現率 (r): ";
    std::cin >> r;

    double macaulay_duration = calculate_macaulay_duration(n, c, r);
    std::cout << "債券的 Macaulay Duration: " << macaulay_duration << std::endl;

    return 0;
}
