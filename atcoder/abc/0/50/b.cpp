#include <bits/stdc++.h>
using namespace std;
using ui = unsigned;
#define ALL(v) (v).begin(), (v).end()
#define REP(i, n) for (unsigned short i = 0; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned short N;
    cin >> N;
    vector<ui> T(N);
    for (ui &Ti : T) cin >> Ti;
    int sum = accumulate(ALL(T), 0);
    unsigned short M;
    cin >> M;
    REP(i, M) {
        unsigned short P;
        ui X;
        cin >> P >> X;
        cout << sum - T[P] + X << "\n";
    }

    return 0;
}
