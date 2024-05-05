#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    vector<string> s(N);
    for (string &si : s) cin >> si;
    uint M;
    cin >> M;
    vector<string> t(M);
    for (string &ti : t) cin >> ti;

    int ans = 0;
    for (uint i = 0; i < N; i++) {
        int point = 0;
        for (uint j = i; j < N; j++) point += (s[i] == s[j]);
        for (const auto &ti : t) point -= (s[i] == ti);
        ans = max(ans, point);
    }

    cout << ans;
    return 0;
}
