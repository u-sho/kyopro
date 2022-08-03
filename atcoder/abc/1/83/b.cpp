#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    long double Sx, Sy, Gx, Gy;
    cin >> Sx >> Sy >> Gx >> Gy;

    cout << Sx + (Gx - Sx) / (Gy + Sy) * Sy << "\n";

    return 0;
}
