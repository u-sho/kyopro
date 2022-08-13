#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        unsigned n, x, y;
        cin >> n >> x >> y;

        vector<int> a(n);
        // 公差が最小のもの（最大50 > y-x)
        // minimum adjacent
        for (unsigned i = 1; i <= y - x; i++) {
            if ((y - x) % i) continue;
            if (x + i * (n - 1) < y) continue;

            unsigned j = 0;
            for (; j < n - (y - x) / i; j++) {
                if (x <= j * i) break;
                a.at(j) = x - j * i;
            }
            for (unsigned k = 1; j < n; j++) {
                a.at(j) = x + k * i;
                k++;
            }

            break;
        }

        for (unsigned i = 0; i < n; i++) {
            cout << a.at(i) << ((i < n - 1) ? " " : "\n");
        }
    }

    return 0;
}
