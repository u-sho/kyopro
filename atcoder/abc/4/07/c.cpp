#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    const uint len = S.length();

    uint64_t ans = 0ULL;
    for (int i = len - 1u; i >= 0; i--) {
        uint Si  = S[i] - '0';
        Si      += 10 - ((ans - (len - 1u - i)) % 10ull);
        ans     += (Si % 10u) + 1u;
    }

    cout << ans << '\n';

    return 0;
}
