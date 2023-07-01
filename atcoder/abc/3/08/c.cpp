#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned N;
    cin >> N;
    vector<pair<long double, unsigned>> pr(N);
    int i = 0;
    for (auto& [pri, id] : pr) {
        id = ++i;
        unsigned A, B, g;
        cin >> A >> B;
        g    = gcd(A, B);
        A   /= g;
        B   /= g;
        pri  = (long double)A / ((long double)A + (long double)B);
    }

    sort(pr.begin(), pr.end(), [](auto const& x, auto const& y) {
        return ((x.first == y.first) ? (x.second < y.second)  // iの昇順
                                     : (x.first > y.first));  // 確率の降順
    });

    for (const auto& [pri, id] : pr) {
        cout << id << ' ';
    }

    return 0;
}
