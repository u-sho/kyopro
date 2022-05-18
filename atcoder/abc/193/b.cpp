#include <bits/stdc++.h>

using namespace std;
using ui   = unsigned;
using lli  = long long;
using ulli = unsigned long long;

#define ALL(v) v.begin(), v.end()
#define SORT(v) sort((v).begin(), (v).end())
#define REP(i, n) for (size_t i = 0UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
        int a, p, x;
        cin >> a >> p >> x;

        if (x - a > 0) ans = min(ans, p);
    }

    cout << (ans == INT_MAX ? -1 : ans) << "\n";

    return 0;
}
