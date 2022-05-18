#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 998244353;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int ae : a) cin >> ae;
    sort(a.begin(), a.end());

    vector<int> toS(3003);
    fill(toS.begin(), toS.end(), 0);
    for (int i = 0; i < s; ++i) {
        auto lower = lower_bound(a.begin(), a.end(), s - i);
        auto upper = upper_bound(a.begin(), a.end(), s - i);
        if (upper > lower) toS.at(i) = upper - lower;
    }

    long long ans = 0LL;
    for (int i = 1; i <= n; ++i) {  // i:使う個数
        int j = i;
        if (j == 1) {
            ans += toS.at(0);
        }
        }

    return 0;
}