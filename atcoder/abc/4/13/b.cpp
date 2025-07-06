#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    vector<string> S(N);
    for (string &Si : S) cin >> Si;

    set<string> SS;
    for (uint i = 0; i < N; i++) {
        for (uint j = 0; j < N; j++) {
            if (i == j) continue;

            SS.insert(S[i] + S[j]);
        }
    }

    cout << SS.size() << '\n';

    return 0;
}
