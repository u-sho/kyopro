#include <bits/stdc++.h>

using namespace std;
using ui   = unsigned;
using lli  = long long;
using ulli = unsigned long long;

#define ALL(v) v.begin(), v.end()
#define SORT(v) sort((v).begin(), (v).end())
#define REP(i, n) for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ulli N;
    cin >> N;

    ui ans = 0U;
    for (ulli i = 1UL; i < 1'000'000UL; ++i, ++ans) {
        if (i < 10UL) {  // 1桁
            if (10UL * i + i > N) break;
        } else if (i < 100UL) {  // 2桁
            if (100UL * i + i > N) break;
        } else if (i < 1'000UL) {  // 3桁
            if (1'000UL * i + i > N) break;
        } else if (i < 10'000UL) {  // 4桁
            if (10'000UL * i + i > N) break;
        } else if (i < 100'000UL) {  // 5桁
            if (100'000UL * i + i > N) break;
        } else {  // 6桁
            if (1'000'000UL * i + i > N) break;
        }
    }

    cout << ans << "\n";

    return 0;
}
