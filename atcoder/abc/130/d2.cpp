#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main() {
    size_t N, K;
    cin >> N >> K;
    vector<lli> a(N);
    for (lli &ai : a) cin >> ai;
    vector<lli> b(N + 1uL);
    b.at(0) = 0;
    partial_sum(a.begin(), a.end(), b.begin() + 1);

    lli ans = 0LL;
    for (size_t li = 0uL; li <= N; ++li) {
        auto ri_l = lower_bound(b.begin(), b.end(), K + b.at(li));
        if (ri_l == b.end()) continue;
        ans += (lli)(N - (ri_l - b.begin()) + 1uL);
    }

    cout << ans << '\n';

    return 0;
}
