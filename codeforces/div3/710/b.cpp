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
        ui n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        ui first_ast_i = n;
        ui last_ast_i  = 0U;
        REP(i, n) {
            if (s[i] == '*') {
                first_ast_i = min(first_ast_i, i);
                last_ast_i  = max(last_ast_i, i);
            }
        }

        if (first_ast_i == n) {
            cout << "0" << endl;
            continue;
        }
        if (first_ast_i == last_ast_i) {
            cout << "1" << endl;
            continue;
        }

        ui count = 2U;
        for (ui i = first_ast_i + k; i < last_ast_i; i += k) {
            if (s[i] == '*') {
                count++;
                continue;
            }
            for (ui j = i - 1; i - k <= j; j--) {
                if (s[i] == '*') {
                    count++;
                    i = j;
                    break;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
