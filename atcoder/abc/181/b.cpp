#include <bits/stdc++.h>
using namespace std;
using ulli = unsigned long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned N;
    cin >> N;

    ulli ans = 0ULL;
    for (unsigned i = 0U; i < N; i++) {
        ulli A, B;
        cin >> A >> B;
        ans += (B * (B + 1ULL) - A * (A - 1ULL)) / 2ULL;
    }

    cout << ans << "\n";

    return 0;
}
