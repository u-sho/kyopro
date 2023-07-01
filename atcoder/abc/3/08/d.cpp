#include <bits/stdc++.h>
using namespace std;

using p             = pair<int, int>;
const string snuke  = "snuke";
const vector<p> dhw = {
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

    vector is_checked(H, vector<bool>(W, false));

    // dfs
    stack<p> snuke_next;
    snuke_next.push({0, 0});  // start: (1,1)
    while (!snuke_next.empty()) {
        const auto [h, w] = snuke_next.top();
        snuke_next.pop();

        const char prev_char = S[h][w];
        char next_char;
        for (unsigned t = 0; t < 5; t++) {
            if (snuke[t] == prev_char) next_char = snuke[(t + 1) % 5];
        }

        for (const auto &[dh, dw] : dhw) {
            const int nh = h + dh, nw = w + dw;
            if (nh < 0 || H <= nh) continue;
            if (nw < 0 || W <= nw) continue;
            if (is_checked[nh][nw]) continue;
            if (S[nh][nw] != next_char) continue;
            snuke_next.push({nh, nw});
        }
        is_checked[h][w] = true;
    }

    cout << (is_checked[H - 1][W - 1] ? "Yes\n" : "No\n");

    return 0;
}
