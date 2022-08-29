#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using lli = long long;
using ulli = unsigned long long;

#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define REP(i, n) for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ulli N, M, T;
    cin >> N >> M >> T;
    vector<ulli> A(N);
    REP1(i, N) cin >> A[i];
    vector<pair<ulli, ulli>> XY(M);
    for (auto &[Xi, Yi] : XY) cin >> Xi >> Yi;

    SORT(XY);
    ulli x = 0;
    REP1(i, N) {
        if (x < M && XY[x].first == i) {
            T += XY[x].second;
            ++x;
        }
        if (T > A[i])
            T -= A[i];
        else {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

    return 0;
}
