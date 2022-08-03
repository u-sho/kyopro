#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> P(n);
    for (int &Pi : P) cin >> Pi;
    vector<int> C(n);
    for (int &Ci : C) cin >> Ci;

    lli ans = 0LL;
    for (int start = 0; start < n; ++start) {
        int position = start;
        lli ansstart = 0LL;

        vector<lli> sum(n + 1);
        sum.at(0) = 0LL;
        vector<lli> maxans(n);
        maxans.at(0) = 0LL;

        for (int i = 1; i <= n; ++i) {
            position  = P.at(position) - 1;
            sum.at(i) = sum.at(i - 1) + (lli)C.at(position);

            if (i != 0) {
                maxans.at(i) = max(sum.at(i), maxans.at(i - 1));
            }

            if (i == k) {
                ansstart = maxans.at(i);
                break;
            }

            if (P.at(position) - 1 == start) {
                ansstart =
                    max(maxans.at(i),
                        (sum.at(i) + (lli)C.at(P.at(position) - 1)) * (n / i) +
                            maxans.at(n % i));
                break;
            }
        }
        ans = max(ans, ansstart);
    }

    cout << ans << '\n';

    return 0;
}
