#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    size_t N;
    long long W;
    cin >> N >> W;
    vector<unsigned int> S(N), T(N), P(N);
    for (size_t i = 0UL; i < N; i++) cin >> S.at(i) >> T.at(i) >> P.at(i);

    unsigned int time_min = 1'000'000U;
    unsigned int time_max = 0U;
    vector<long long> usage_at_t(200'005, 0);  //'
    for (size_t i = 0UL; i < N; i++) {
        time_min = min(time_min, S.at(i));
        time_max = max(time_max, T.at(i));
        usage_at_t[S.at(i)] += P.at(i);
        usage_at_t[T.at(i)] -= P.at(i);
    }

    for (unsigned int t = time_min; t < time_max; t++) {
        if (t != 0U) usage_at_t.at(t) += usage_at_t.at(t - 1U);
        if (usage_at_t.at(t) > W) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}
