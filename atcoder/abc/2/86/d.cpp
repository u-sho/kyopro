#include <bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, X;
    cin >> N >> X;
    vector<pair<uint, uint>> AB(N);
    for (pair<uint, uint> &ABi : AB) cin >> ABi;

    vector<bool> is_payable(X + 1U, false);
    is_payable[0] = true;
    // 50*10000*50=25'000'000
    for (const auto &[A, B] : AB) {  // <= 50個
        vector<bool> be_skip(X + 1U, false);
        for (uint i = 0; i <= X; i++) {  // X<=10000
            if (be_skip[i]) continue;
            if (is_payable[i]) {
                for (uint j = 1; j <= B && i + A * j <= X; j++) {  // B<=50
                    if (is_payable[i + A * j]) break;
                    is_payable[i + A * j] = true;
                    be_skip[i + A * j]    = true;
                }
            }
        }
    }

    cout << (is_payable[X] ? "Yes\n" : "No\n");

    return 0;
}
