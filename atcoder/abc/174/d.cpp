#include <bits/stdc++.h>
using namespace std;
using lli  = long long;
using ulli = unsigned long long;

int main() {
    // sort : R < W
    int N;
    cin >> N;
    string c;
    cin >> c;

    int w = 0;
    for (auto ci : c)
        if (ci == 'W') ++w;
    int r = N - w;

    if (w == 0 || r == 0) {
        cout << "0\n";
        return 0;
    }

    int ans = 0;
    for (int i = 0ul; i < r; ++i) {
        if (c.at(i) == 'W') {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
