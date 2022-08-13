#include <bits/stdc++.h>

using namespace std;
using ui   = unsigned;
using lli  = long long;
using ulli = unsigned long long;

#define ALL(v) v.begin(), v.end()
#define SORT(v) sort((v).begin(), (v).end())
#define REP(i, n) for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ui t;
    cin >> t;
    while (t--) {
        size_t n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;

        if (n == 1) {
            cout << "1\n";
            continue;
        }

        SORT(a);

        multiset<ui> b;
        REP(i, n) {
            if (i == n - 1) {
                b.insert(1);
                break;
            }
            if (a[i] != a[i + 1]) {
                b.insert(1);
                continue;
            }
            auto it = upper_bound(ALL(a), a[i]);
            b.insert((it - a.begin()) - i);
            i = (it - a.begin()) - 1UL;
        }

        while (b.size() > 1UL) {
            auto last = b.end();
            --last;
            ui b_max  = *last--;
            ui b_max2 = *last;
            b.erase(last, b.end());
            b_max -= b_max2;
            if (b_max > 0U) b.insert(b_max);
        }
        if (b.empty())
            cout << "0\n";
        else
            cout << *(b.begin()) << "\n";
    }

    return 0;
}
