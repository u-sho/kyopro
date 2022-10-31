#include <bits/stdc++.h>
using namespace std;

#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    vector<pair<string, uint>> S(N);
    uint id = 1U;
    for (auto& [Si, i] : S) {
        cin >> Si;
        i = id++;
    }

    vector<uint> ans;
    sort(S.begin(), S.end());
    ans.push_back(S[0].second);
    REP1(i, N) {
        if (S[i].first == S[i - 1].first) {
            if (ans.back() > S[i].second) ans.back() = S[i].second;
        } else {
            ans.push_back(S[i].second);
        }
    }

    sort(ans.begin(), ans.end());
    for (const uint& i : ans) {
        cout << i << '\n';
    }

    return 0;
}
