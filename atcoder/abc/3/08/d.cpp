#include <bits/stdc++.h>
using namespace std;

using p            = pair<int, int>;
const string snuke = "snuke";
const p d[4]       = {
    {-1,  0},
    { 1,  0},
    { 0,  1},
    { 0, -1}
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (string &Si : S) cin >> Si;

    if (S[0][0] != 's') {
        cout << "No\n";
        return 0;
    }

    vector<vector<bool>> checked(H, vector<bool>(W, false));
    queue<p> snuke_next;
    snuke_next.push({0, 0});  // start: (1,1)

    while (!snuke_next.empty()) {
        const p prev = snuke_next.front();
        const int h = prev.first, w = prev.second;
        snuke_next.pop();

        const char prev_char = S[h][w];
        char next_char;
        for (unsigned t = 0; t < 5; t++) {
            if (snuke[t] == prev_char) next_char = snuke[(t + 1) % 5];
        }

        // 上下左右
        for (const auto &[dh, dw] : d) {
            const int nh = h + dh, nw = w + dw;
            if (0 > nh || nh >= H) continue;
            if (0 > nw || nw >= W) continue;
            if (checked[nh][nw]) continue;
            if (S[nh][nw] == next_char) {
                snuke_next.push({nh, nw});
            }
        }
        checked[h][w] = true;
    }

    cout << (checked[H - 1][W - 1] ? "Yes\n" : "No\n");

    return 0;
}
