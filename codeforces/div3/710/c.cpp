#include <bits/stdc++.h>

using namespace std;
using ui   = unsigned;
using lli  = long long;
using ulli = unsigned long long;

#define REP(i, n) for (ui i = 0U; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ui t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a;
        cin >> b;
        if (a.length() < b.length()) swap(a, b);

        ui max_match_length = 0U;
        ui al = a.length(), bl = b.length();
        REP(i, bl) {
            REP(j, al) {
                REP(k, bl - i) {
                    if (j + k >= al) break;
                    if (a[j + k] != b[i + k]) break;
                    max_match_length = max(max_match_length, k + 1U);
                }
            }
        }
        cout << max(0U, al + bl - 2 * max_match_length) << endl;
    }

    return 0;
}
