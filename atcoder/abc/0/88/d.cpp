#include <bits/stdc++.h>
constexpr int INF = 1e9;
using namespace std;
using YX = pair<int, int>;

istream &operator>>(istream &is, YX &p) {
    is >> p.first >> p.second;
    return is;
}

int dist[51][51];

int bfs(vector<string> maize, int r, int c, YX start, YX goal) {
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
    dist[start.first][start.second] = 0;  // start地点は0

    queue<YX> que;
    que.push(start);

    while (!que.empty()) {
        YX prev = que.front();
        que.pop();

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
            if (y == goal.first && x == goal.second) {
                return dist[y][x];
            }
            // このノードから距離1で到達できるところを探したいのでqueueに突っ込む
            que.push(make_pair(y, x));
        }
    }
    return -1;
}

int main() {
    int H, W;
    cin >> H >> W;

    YX start = make_pair(0, 0);
    YX goal  = make_pair(H - 1, W - 1);

    vector<string> s(H);
    for (int i = 0; i < H; ++i) {
        cin >> s.at(i);
    }

    int dst = bfs(s, H, W, start, goal);
    if (dst == -1)
        cout << "-1\n";
    else {
        int whites = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (s.at(i).at(j) == '.') whites++;
            }
        }
        cout << whites - (dst + 1) << endl;
    }

    return 0;
}
