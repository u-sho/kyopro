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
            dist[i][j] = INF;
        }
    }
    dist[start.first][start.second] = 0;

    queue<YX> que;
    que.push(start);

    while (!que.empty()) {
        YX prev = que.front();
        que.pop();

        for (YX p : MOVES) {
            int y = prev.first + p.first;
            int x = prev.second + p.second;
            // 壁ならskip
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
    int R, C;
    cin >> R >> C;

    YX s, g;
    cin >> s;
    cin >> g;
    // 0-indexed
    s.first--;
    s.second--;
    g.first--;
    g.second--;

    vector<string> c(R);
    for (int i = 0; i < R; ++i) {
        cin >> c.at(i);
    }

    cout << bfs(c, R, C, s, g) << endl;

    return 0;
}
