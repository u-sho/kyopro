#include <bits/stdc++.h>
using namespace std;
using lli  = long long;
using ulli = unsigned long long;

int main() {
    int n, d;
    cin >> n >> d;

    lli D   = (lli)d * (lli)d;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        lli x, y;
        cin >> x >> y;
        if (x * x + y * y <= D) ++ans;
    }

    cout << ans << '\n';

    return 0;
}
