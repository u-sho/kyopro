#include <bits/stdc++.h>
using namespace std;

const pair<int, int> d[4] = {
    make_pair(-1, 0),  // ↑
    make_pair(0, 1),   // →
    make_pair(1, 0),   // ↓
    make_pair(0, -1)   // ←
};

int main() {
    int H, W, N;
    cin >> H >> W >> N;

    vector<string> grid(H);
    for (auto &i : grid) {
        i.resize(W, '.');
    }

    pair<int, int> curr = make_pair(0, 0);
    int irect           = 0;
    for (int i = 0; i < N; i++) {
        if (grid[curr.first][curr.second] == '.') {  // 白のとき
            grid[curr.first][curr.second] = '#';     // 黒に塗り替え
            irect                         = (irect + 1) % 4;  // 時計回り
        } else {                                              // 黒のとき
            grid[curr.first][curr.second] = '.';  // 白に塗り替え
            irect                         = (irect + 3) % 4;  // 反時計周り
        }
        // 1マス進む
        curr.first  = (H + curr.first + d[irect].first) % H;
        curr.second = (W + curr.second + d[irect].second) % W;
    }

    for (const string &i : grid) {
        cout << i << endl;
    }
    return 0;
}