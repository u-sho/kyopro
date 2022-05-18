#include <bits/stdc++.h>
constexpr int INF = 1e9;
using namespace std;
using YX = pair<int, int>;

istream &operator>>(istream &is, YX &p) {
    is >> p.first >> p.second;
    return is;
}

int dist[1003][1003];

int bfs(vector<string> maize, int r, int c, deque<YX> que) {
    const vector<YX> MOVES = {
        make_pair(-1, 0),  // up
        make_pair(0, 1),   // right
        make_pair(0, -1),  // left
        make_pair(1, 0)    // bottom
    };
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            dist[i][j] = INF;  // 未到達をINFで初期化
        }
    }
    for (YX p : que) {
        dist[p.first][p.second] = 0;
    }

    int res = 0;
    while (!que.empty()) {
        YX prev = que.front();
        que.pop_front();

        for (YX p : MOVES) {
            int y = prev.first + p.first;
            int x = prev.second + p.second;
            // maizeの外ならskip
            if (y < 0 || y >= r || x < 0 || x >= c) continue;
            // 黒ならskip
            if (maize[y][x] == '#') continue;
            // 通過済みならskip
            if (dist[y][x] != INF) continue;

            // 直前のノードまでの最短距離+1
            dist[y][x] = dist[prev.first][prev.second] + 1;
            res        = dist[y][x];
            // このノードから距離1で到達できるところを探したいのでqueueに突っ込む
            que.push_back(make_pair(y, x));
        }
    }
    return res;
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> A(H);
    for (int i = 0; i < H; ++i) {
        cin >> A.at(i);
    }

    deque<YX> blacks;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A.at(i).at(j) == '#') blacks.push_back(make_pair(i, j));
        }
    }

    cout << bfs(A, H, W, blacks) << endl;

    return 0;
}
