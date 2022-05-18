#include <bits/stdc++.h>
using std::make_pair;
using std::pair;
using std::queue;
using std::vector;

constexpr int N_MAX = 1e5;
constexpr int INF   = 2e5;

// std::vectorの出力
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << "\n";
    }
    return os;
}

vector<int> solve(int n, vector<vector<int>> g) {
    // (道しるべ，部屋1までの回数)
    // second は到達したかどうかのフラグでも可
    vector<pair<int, int>> dist(n + 1, make_pair(0, INF));
    dist.at(1) = make_pair(1, 0);

    queue<int> que;
    que.push(1);  // start room

    // bfs
    while (!que.empty()) {
        int prev = que.front();
        que.pop();

        for (int ge : g.at(prev)) {
            if (dist.at(ge).second != INF) continue;

            dist.at(ge) = make_pair(prev, dist.at(prev).second + 1);
            que.push(ge);
        }
    }

    // outputs
    vector<int> res;
    for (int i = 2; i <= n; ++i) {
        res.push_back(dist.at(i).first);
    }
    return res;
}

int main() {
    using std::cin;
    using std::cout;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
    }

    cout << "Yes\n" << solve(n, graph);

    return 0;
}