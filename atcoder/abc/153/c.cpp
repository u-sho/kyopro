#include <bits/stdc++.h>
using ll = long long;

int main() {
    using namespace std;
    int n, k;
    cin >> n >> k;
    int H[n];
    for (int i = 0; i < n; i++) cin >> H[i];
    sort(H, H + n);
    ll ans = 0LL;
    for (int i = 0; i < n - k; i++) ans += H[i];
    cout << ans << endl;
    return 0;
}