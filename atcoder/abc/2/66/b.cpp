#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using lli = long long;
constexpr lli mod = 998244353;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    lli N;
    cin >> N;
    lli m = N % mod;
    lli x = (m < 0) ? (mod + m) : m;
    cout << x << '\n';

    return 0;
}
