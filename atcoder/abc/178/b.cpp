#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // inputs
    lli a, b, c, d;
    cin >> a >> b >> c >> d;

    // solve
    lli ans = max(max(a * c, a * d), max(b * c, b * d));

    // output
    cout << ans << "\n";

    return 0;
}
