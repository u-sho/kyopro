#include <bits/stdc++.h>
using ll = long long;

int main() {
    using namespace std;
    ll h;
    cin >> h;
    ll ans     = 0LL;
    ll nanntai = 1LL;
    while (h > 0LL) {
        ans += nanntai;
        h = h / 2LL;
        nanntai *= 2LL;
    }
    cout << ans << endl;
    return 0;
}