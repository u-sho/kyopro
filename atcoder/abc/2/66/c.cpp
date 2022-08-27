#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

[[nodiscard]] int outer_product(const pii &v1, const pii &v2) {
    return v1.first * v2.second - v1.second * v2.first;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<pii> ABCD(4);
    for (auto &i : ABCD) {
        cin >> i.first >> i.second;
    }

    bool is_convex = true;
    for (int i = 0; i < 4; i++) {
        int j = (i + 1) % 4;
        int k = (i + 2) % 4;
        pii v1 = {ABCD[j].first - ABCD[i].first,
                  ABCD[j].second - ABCD[i].second};
        pii v2 = {ABCD[k].first - ABCD[j].first,
                  ABCD[k].second - ABCD[j].second};
        if (outer_product(v1, v2) < 0) {
            is_convex = false;
            break;
        }
    }

    cout << (is_convex ? "YES\n" : "NO\n");
    return 0;
}
