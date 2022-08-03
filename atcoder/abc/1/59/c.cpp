#include <bits/stdc++.h>

int main() {
    using namespace std;

    int L;
    cin >> L;

    double v   = L / 3.0;
    double ans = v * v * v;
    cout << std::fixed << std::setprecision(15) << ans << endl;

    return 0;
}

/*
    3 * 3 * 3 = 27
    4 * 3 * 2 = 24
    5 * 2 * 2 = 20

    5 * 3 * 3 = 45
    4 * 4 * 3 = 48
*/