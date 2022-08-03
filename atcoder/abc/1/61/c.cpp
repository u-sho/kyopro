#include <bits/stdc++.h>
using ll = long long;
int main() {
    using namespace std;

    ll n, k;
    cin >> n >> k;
    ll ans = min(n%k, abs(n%k - k));
    cout << ans << endl;
    return 0;
}