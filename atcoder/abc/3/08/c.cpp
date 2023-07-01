#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned N;
    cin >> N;

    /* first: 確率の逆数, second: 添字 */
    vector<pair<long double, unsigned>> ipr(N);
    int i = 0;
    for (auto& [ipri, id] : ipr) {
        unsigned A, B, g;
        cin >> A >> B;
        g = gcd(A, B);

        ipri = ((long double)((A + B) / g)) / (long double)(A / g);
        id   = ++i;
    }

    sort(ipr.begin(), ipr.end());

    for (const auto& [pri, id] : ipr) {
        cout << id << ' ';
    }

    return 0;
}
