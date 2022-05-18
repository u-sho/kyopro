#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
int main(void) {
    using std::cos;
    using std::cout;
    using std::sin;
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(10);

    double a, b;
    int h, m;
    std::cin >> a >> b >> h >> m;

    double aRad = M_PI * (double)h / 6.0 + M_PI * (double)m / 360.0;
    double ax   = a * cos(aRad);
    double ay   = a * sin(aRad);

    double bRad = M_PI * (double)m / 30.0;
    double bx   = b * cos(bRad);
    double by   = b * sin(bRad);
    // cout << aRad << ", " << bRad << std::endl;
    // cout << ax << ", " << ay << std::endl;
    // cout << bx << ", " << by << std::endl;

    double dist2 = pow(ax - bx, 2.0) + pow(ay - by, 2.0);
    double dist  = sqrt(dist2);

    std::cout << dist << std::endl;
    return 0;
}
