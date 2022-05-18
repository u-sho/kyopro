#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
constexpr int H_MAX = 2'000;
constexpr int W_MAX = 1'000;

constexpr int INF       = 1e9;
constexpr int MOVE_COST = 1;  // 1回の移動でかかるコスト

using std::make_pair;
using std::pair;
using std::queue;
using std::vector;

// grid
using Grid = vector<vector<int>>;
// gridの左上を(0,0)として(↓,→)の座標
using YX = pair<int, int>;

const vector<YX> MOVES = {
    make_pair(-1, 0),  // 上へ
    make_pair(1, 0),   // 下へ
    make_pair(0, -1),  // 左へ
    make_pair(0, 1)    // 右へ
};

// (H_MAX+2) * (W_MAX+2) のvectorで距離を表す。INFで初期化
// 2に意味はない。0でも良い
Grid d(H_MAX + 2, vector<int>(W_MAX + 2, INF));

/**
 * h: グリッドの高さ
 * w: グリッドの幅
 * m: グリッド
 * d: 移動回数
 */
int bfs(int h, int w, Grid m, int D) {
    queue<YX> que;
    YX s = make_pair(0, 0);
    que.push(s);
    d.at(s.first).at(s.second) == 0;

    int res = 0;
    while (!que.empty()) {
        YX prev = que.front();
        que.pop();
        int py = prev.first;
        int px = prev.second;

        // 上下左右を見ていく
        for (const YX &dm : MOVES) {  // dm: 微小なmove
            int y = py + dm.first;
            int x = px + dm.second;

            // グリッドの外ならskip
            if (y < 0 || x < 0 || y >= h || x >= w) continue;

            // 距離を更新
            d.at(y).at(x) = d.at(py).at(px) + MOVE_COST;

            // ちょうどDなら比較する
            if (d.at(y).at(x) == D) {
                res = std::max(res, m.at(y).at(x));
                continue;
            }

            // まだDじゃないならpush
            YX curr = make_pair(y, x);
            que.push(curr);
        }
    }

    return res;
}

int main(void) {
    int r, c, d;
    Grid A;

    std::cin >> r >> c >> d;

    A.resize(r);
    for (int i = 0; i < r; ++i) {
        A.at(i).resize(c);
        for (int j = 0; j < c; ++j) {
            int a;
            std::cin >> a;
            A.at(i).at(j) = a;
        }
    }
    std::cout << A.at(0).at(0);

    std::cout << bfs(r, c, A, d) << std::endl;
    return 0;
}
