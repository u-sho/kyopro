#include <bits/stdc++.h>
using ll = long long;

const std::string ans[2] = {"No\n", "Yes\n"};
constexpr ll MOD         = 1'000'000'007;

int main() {
    using namespace std;
    int h, n;
    cin >> h >> n;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        h -= a;
    }
    cout << ans[(h <= 0) ? 1 : 0];
    return 0;
}