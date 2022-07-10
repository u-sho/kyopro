#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, d;
    cin >> a >> b >> d;

    complex<double> ab(a, b);
    complex<double> rot_d(cos(d * M_PI / 180.0), sin(d * M_PI / 180.0));

    complex<double> ans = ab * rot_d;

    cout << fixed << setprecision(10) << ans.real() << " " << ans.imag()
         << endl;

    return 0;
}
