#include <iostream>
#include <cmath>
#include <boost/math/distributions/normal.hpp>

using namespace std;

int main() {
    double V0, D, T, r, rh, C, t, a;
    cout << "請輸入 V0、D、T、r、rh、C、t、a 的值：" << endl;
    cin >> V0 >> D >> T >> r >> rh >> C >> t >> a;

    // 計算無違約概率和距離違約（distance-to-default）
    double A = exp(-t * r);
    double B = (log(V0 / D) + (r + pow(rh, 2) / 2) * T) / (rh * sqrt(T));
    double PD = 1 - boost::math::cdf(boost::math::normal(), -B + rh * sqrt(T));
    double DTD = -B + rh * sqrt(T) * boost::math::quantile(boost::math::normal(), 1 - PD);

    // 計算公司股權期出價值（E0）
    double E0 = V0 * exp((-t * r - 0.5 * pow(rh, 2)) * T + rh * sqrt(T) * boost::math::quantile(boost::math::normal(), 1 - PD));

    // 計算公司期出負債價值（D0）
    double D0 = D * exp(-r * T) * (1 - PD);

    // 計算稅盾期出價值（TB）
    double TB = C * T * (1 - t) * exp(-t * r);

    // 計算破產成本期出價值（BC）
    double BC = D * a;

    // 驗證 E0 + D0 是否等於 V0 + TB - BC
    if (abs(E0 + D0 - (V0 + TB - BC)) < 1e-6) {
        cout << "E0 + D0 = V0 + TB - BC" << endl;
    } else {
        cout << "E0 + D0 != V0 + TB - BC" << endl;
    }

    // 輸出結果
    cout << "股東權益期出價值 E0 = " << E0 << endl;
    cout << "公司期出負債價值 D0 = " << D0 << endl;
    cout << "稅盾期出價值 TB = " << TB << endl;
    cout << "破產成本期出價值 BC = " << BC << endl;
    return 0;
}
