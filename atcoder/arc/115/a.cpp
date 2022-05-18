#include <bits/stdc++.h>

using namespace std;
using ui   = unsigned;
using lli  = long long;
using ulli = unsigned long long;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    unsigned short M;
    cin >> N >> M;
    vector<int> S(N);
    REP(i, N) {
        string si;
        cin >> si;
        S.at(i) = stoi(si, (size_t *)0, 2);
    }

    REP(i, (1 << M) + 1) {}

    cout << ans << endl;
    return 0;
}
