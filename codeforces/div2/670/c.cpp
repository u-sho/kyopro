#include <bits/stdc++.h>
using namespace std;
using lli = long long;

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> tree(n + 1);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            tree.at(x).push_back(y);
            tree.at(y).push_back(x);
        }
    }

    return 0;
}
