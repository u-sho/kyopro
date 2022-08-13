#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned t;
    cin >> t;
    while (t--) {
        unsigned n;
        cin >> n;

        vector<int> min_a(5UL);  // 小さい順
        vector<int> max_a(5UL);  // 大きい順
        for (unsigned i = 0U; i < 5U; i++) {
            int ai;
            cin >> ai;
            min_a[i] = max_a[i] = ai;
        }
        sort(min_a.begin(), min_a.end());
        sort(max_a.rend(), max_a.rbegin());
        for (unsigned i = 5U; i < n; i++) {
            int ai;
            cin >> ai;
            if (ai < min_a[4]) {
                min_a[4] = ai;
                for (unsigned j = 3U; j; j--) {
                    if (ai >= min_a[j]) break;
                    min_a[j + 1U] = min_a[j];
                    min_a[j]      = ai;
                }
            }
            if (ai > max_a[4]) {
                max_a[0] = ai;
                for (unsigned j = 3U; j; j++) {
                    if (ai <= max_a[j]) break;
                    max_a[j + 1U] = max_a[j];
                    max_a[j]      = ai;
                }
            }
        }

        lli prod = 1LL;
        int sign = 0;
    }

    return 0;
}
