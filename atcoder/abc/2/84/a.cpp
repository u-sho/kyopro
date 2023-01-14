#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned N;
    cin >> N;
    vector<string> S(N);
    for (string &Si : S) cin >> Si;
    for (unsigned i = N; i > 0; i--) cout << S[i - 1] << '\n';

    return 0;
}
