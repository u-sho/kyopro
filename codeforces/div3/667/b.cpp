#include <iostream>
using namespace std;
using lli = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        lli a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;

        int a_sub = min(a - x, n);
        int b_sub = min(b - y, n);
        if (a - a_sub < b - b_sub) {
            n -= a_sub;
            a -= a_sub;
        } else {
            n -= b_sub;
            b -= b_sub;
        }

        if (n == 0) {
            cout << a * b << "\n";
            continue;
        }

        if (a == x) {
            b = max(b - n, y);
        } else {
            a = max(a - n, x);
        }

        cout << a * b << "\n";
    }

    return 0;
}
