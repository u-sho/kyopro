#include <bits/stdc++.h>
using namespace std;
using YX = pair<int, int>;

constexpr int INF      = 1e9;
const vector<YX> MOVES = {
    make_pair(-1, 0),  // up
    make_pair(0, 1),   // right
    make_pair(0, -1),  // left
    make_pair(1, 0)    // bottom
};

istream &operator>>(istream &is, YX &p) {
    is >> p.first >> p.second;
    return is;
}

int dist[502][502];
int overcome = 0;

pair<bool, queue<YX>> bfs(vector<string> maize, int h, int w, queue<YX> que,
                          YX goal) {
    queue<YX> next;
    while (!que.empty()) {
        YX prev = que.front();
        que.pop();

        for (YX p : MOVES) {
            int y = prev.first + p.first;
            int x = prev.second + p.second;

            // maizeの外ならskip
            if (y < 0 || y >= h || x < 0 || x >= w) continue;

            // 黒ならskip
            if (maize[y][x] == '#') {
                if (dist[y][x] > overcome + 1) {
                    dist[y][x] = overcome + 1;
                    next.push(make_pair(y, x));
                }
                continue;
            }

            // 終点なら到達できることを返す
            if (make_pair(y, x) == goal) return make_pair(true, next);

            // 通過済みならskip
            if (dist[y][x] != INF) continue;

            // 直前のノードまでの最短距離
            dist[y][x] = overcome;
            // このノードから到達できるところを探したいのでqueueに突っ込む
            que.push(make_pair(y, x));
        }
    }
    return make_pair(false, next);
}

string solve(vector<string> maize, int r, int c, YX start, YX goal) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            dist[i][j] = INF;  // 未到達をINFで初期化
        }
    }
    dist[start.first][start.second] = 0;  // start地点は0

    queue<YX> que;
    que.push(start);

    // 壁を乗り越えずにたどり着けるところを探索
    overcome                    = 0;
    pair<bool, queue<YX>> cost0 = bfs(maize, r, c, que, goal);
    if (cost0.first) return "YES\n";

    // 壁を１回だけ乗り越えてたどり着けるところを探索
    overcome++;
    pair<bool, queue<YX>> cost1 = bfs(maize, r, c, cost0.second, goal);
    if (cost1.first) return "YES\n";

    // 壁を２回だけ乗り越えてたどり着けるところを探索
    overcome++;
    pair<bool, queue<YX>> cost2 = bfs(maize, r, c, cost1.second, goal);
    if (cost2.first) return "YES\n";

    return "NO\n";
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> s(H);
    for (int i = 0; i < H; ++i) {
        cin >> s.at(i);
    }

    YX start, goal;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (s.at(i).at(j) == 's') start = make_pair(i, j);
            if (s.at(i).at(j) == 'g') goal = make_pair(i, j);
        }
    }

    cout << solve(s, H, W, start, goal);

    return 0;
}
