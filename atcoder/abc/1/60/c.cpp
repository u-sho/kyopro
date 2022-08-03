#include <bits/stdc++.h>
using ll = long long;

const std::string ans[2] = {"No\n", "Yes\n"};
// constexpr ll MOD         = 1'000'000'007;
// constexpr ll MOD         = 998'244'353;

int main() {
    using namespace std;
    int k, n;
    cin >> k >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, greater<>());
    int max_dis = k - a[n - 1] + a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] > max_dis) {
            max_dis = a[i] - a[i - 1];
        }
    }
    cout << k - max_dis << endl;
    return 0;
}