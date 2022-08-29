#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using lli = long long;
using ulli = unsigned long long;

vector<vector<bool>> is_visited(500, vector<bool>(500, false));

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ui H, W;
    cin >> H >> W;
    vector<string> G(H);
    for (string &Gi : G) cin >> Gi;

    ui i = 0, j = 0;
    while (!is_visited[i][j]) {
        is_visited[i][j] = true;
        if (G[i][j] == 'U') {
            if (i == 0) {
                cout << i + 1 << ' ' << j + 1 << '\n';
                return 0;
            }
            --i;
        }
        if (G[i][j] == 'D') {
            if (i == H - 1) {
                cout << i + 1 << ' ' << j + 1 << '\n';
                return 0;
            }
            ++i;
        }
        if (G[i][j] == 'L') {
            if (j == 0) {
                cout << i + 1 << ' ' << j + 1 << '\n';
                return 0;
            }
            --j;
        }
        if (G[i][j] == 'R') {
            if (j == W - 1) {
                cout << i + 1 << ' ' << j + 1 << '\n';
                return 0;
            }
            ++j;
        }
    }
    cout << "-1\n";

    return 0;
}
