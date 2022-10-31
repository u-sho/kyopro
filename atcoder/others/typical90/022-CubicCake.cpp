#include <bits/stdc++.h>
using namespace std;

using ullong = unsigned long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ullong A, B, C;
    cin >> A >> B >> C;

    const ullong gcd_ABC = gcd(gcd(A, B), C);
    const ullong ans = A / gcd_ABC + B / gcd_ABC + C / gcd_ABC - 3;
    cout << ans << '\n';

    return 0;
}
