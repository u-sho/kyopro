#include <bits/stdc++.h>

int main() {
    using namespace std;
    const int INF = 1'000'000;

    int n, x, y;
    cin >> n >> x >> y;

    int d[n + 1][n + 1];
    fill(d[0], d[n + 1], INF);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            d[i][j] = j - i;
            d[i][j] = min(d[i][j], abs(x - i) + 1 + abs(y - j));
        }
    }
    // for (int i = 1; i <= x; i++) {
    //     for (int j = y; j <= n; j++) {  // i<=x,y<=j
    //         d[i][j] -= y - x - 1;
    //     }
    //     for (int j = 1; j < y - x; j++) {  // i<=x<j<y
    //         d[i][y - j] = min(d[i][y] + j, d[i][y - j]);
    //     }
    // }
    // for (int i = x + 1; i < y; i++) {
    //     for (int j = y; j <= n; j++) {  // x<i<y<=j
    //         d[i][j] = min(i - x + 1 + j - y, d[i][j]);
    //     }
    // }

    long long ans[n + 1];
    fill(ans, ans + n + 1, 0LL);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans[d[i][j]]++;
            //----------------------------------------
            // cout << d[i][j] << ' ';
        }
        //--------------------------------------------
        // cout << endl;
    }

    for (int k = 1; k < n; k++) {
        cout << ans[k] << endl;
    }

    // n
    return 0;
}