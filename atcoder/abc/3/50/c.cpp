#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    vector<uint> A(N + 1);
    for (uint i = 1U; i <= N; i++) cin >> A[i];

    vector<uint> inv_A(N + 1);
    for (uint i = 1; i <= N; i++) {
        inv_A[A[i]] = i;
    }

    vector<pair<uint, uint>> ans;
    for (uint i = 1; i <= N; i++) {
        if (i != inv_A[i]) {
            ans.push_back({i, inv_A[i]});
            swap(A[i], A[inv_A[i]]);
            swap(inv_A[A[i]], inv_A[A[inv_A[i]]]);
        }
    }

    cout << ans.size() << '\n';
    for (const auto &ai : ans) {
        cout << ai.first << ' ' << ai.second << '\n';
    }

    return 0;
}
