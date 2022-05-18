#include <bits/stdc++.h>
#define H_MAX 100
#define W_MAX 100
#define WALL '#'

constexpr int INF = 1e9;

using std::make_pair;
using std::pair;
using std::queue;
using std::vector;

// grid
using Grid = vector<std::string>;
// gridの左上を(0,0)として(↓,→)の座標
using YX = pair<int, int>;

const vector<YX> MOVES = {
    make_pair(1, 0),  // 下へ
    make_pair(0, 1)   // 右へ
};

// (H_MAX+2) * (W_MAX+2) のvectorで距離を表す。INFで初期化
// 2に意味はない。0でも良い
vector<vector<int>> d(H_MAX + 2, vector<int>(W_MAX + 2, INF));

using BfsRes = pair<int, queue<YX>>;
/**
 * h: グリッドの高さ
 * w: グリッドの幅
 * m: グリッド
 * starts: 始点リスト
 * goal: 終点
 * c: 始点でのコスト(=0)
 *
 * BfsRes: pair<int, queue<YX>>
 *      (コスト(到達不可能時は-1)，壁リスト)
 */
BfsRes bfs(int h, int w, Grid m, queue<YX> starts, YX goal, int c = 0) {
    // 壁リスト
    queue<YX> next;

    // TODO: ここ定数倍重い
    queue<YX> que;
    while (!starts.empty()) {
        YX s = starts.front();
        starts.pop();

        que.push(s);
        // 始点のコストは c(=0)
        if (d.at(s.first).at(s.second) > c) {
            d.at(s.first).at(s.second) = c;
        }
    }

    while (!que.empty()) {
        YX prev = que.front();
        que.pop();
        int py            = prev.first;
        int px            = prev.second;
        bool prev_is_wall = m.at(py).at(px) == WALL;
        int prev_cost     = d.at(py).at(px);  // == c

        // 下右で，通路->壁をせずに行けるところを見ていく
        for (const YX &dm : MOVES) {  // dm: 微小なmove
            int y = py + dm.first;
            int x = px + dm.second;
            if (y >= h || x >= w) continue;

            YX curr           = make_pair(y, x);
            bool curr_is_wall = m.at(y).at(x) == WALL;
            bool pass_to_wall = (!prev_is_wall && curr_is_wall);
            int curr_cost     = prev_cost + (pass_to_wall ? 1 : 0);

            if (curr == goal) return make_pair(curr_cost, next);

            // 最短距離を更新できないなら訪問しない
            if (d.at(y).at(x) <= curr_cost) continue;

            // 通路→壁ならcost++
            if (pass_to_wall) {
                d.at(y).at(x) = curr_cost;  // == c+1
                next.push(curr);
                continue;
            }

            // 最短距離を更新してqueに突っ込む
            d.at(y).at(x) = curr_cost;  // == c
            que.push(curr);
        }
    }

    return bfs(h, w, m, next, goal, c + 1);
}

void agc043_a();

//-----------------------------------------------------------------------main()-----------
int main(void) {
    agc043_a();
    return 0;
}

void agc043_a() {
    int h, w;
    std::cin >> h >> w;

    Grid s(h);
    for (int i = 0; i < h; ++i) std::cin >> s.at(i);

    queue<YX> starts;
    starts.push(make_pair(0, 0));

    int c   = (s.at(0).at(0) == WALL);
    int ans = bfs(h, w, s, starts, make_pair(h - 1, w - 1), c).first;

    std::cout << ans << std::endl;
    return;
}