#include <bits/stdc++.h>

using namespace std;
using ui   = unsigned;
using lli  = long long;
using ulli = unsigned long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ui t;
    cin >> t;
    while (t--) {
        ulli n, m, x;
        cin >> n >> m >> x;
        ulli row_by_columns    = (x - 1ULL) % n + 1ULL;
        ulli column_by_columns = (x - 1ULL) / n + 1ULL;
        cout << (row_by_columns - 1ULL) * m + column_by_columns << endl;
    }

    return 0;
}
