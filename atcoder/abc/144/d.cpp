#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
double a, b, x;

double solve(double max_d, double min_d) {
    double d = (max_d - min_d) / 2.0;
    if ((d - min_d) * 6.0 < 0.0000001) return d;
    if (tan(d)*a < b) {
        if (a * a * (b - a * tan(d) / 2.0) < x) return solve(max_d, d);
        return solve(d, min_d);
    }
    if(a * b * b / (2.0 * tan(d)) < x) return solve(max_d, d);
    return solve(d, min_d);
};

int main(){
    cin >> a >> b >> x;
    const double ans = solve(M_PI / 2.0, 0.0) * M_PI / 180.0;
    cout << ans << endl;
    return 0;
}