#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

using Edge = pair<unsigned, unsigned>;

typedef enum {
    注文票,
    運行情報,
} Kind;

constexpr unsigned n_max = 1'000u;
constexpr unsigned k_max = 5'000u;
constexpr unsigned e_max = 1'000'000u;
constexpr unsigned INF = e_max * n_max + 10u;

unsigned n, k;

vector<vector<unsigned>> 運賃表(n_max + 1u, vector<unsigned>(k_max + 1u, INF));
set<Edge> graph;

int 運賃計算(const unsigned &a, const unsigned &b) {
    if (運賃表.at(a).at(b) < INF) return int(運賃表[a][b]);
    return -1;
}

void 運賃表更新(const unsigned &c, const unsigned &d, const unsigned &e) {
    if (運賃表.at(c).at(d) <= e) return;
    // dijkstra で c
    // から全点へのコストを更新する。このとき、逆向きの辺も更新する.
}

int main(void) {
    // 初期化.
    for (unsigned i = 0u; i <= n_max; ++i) 運賃表.at(i).at(i) = 0u;

    for (cin >> n >> k; k; --k) {
        unsigned kind;
        cin >> kind;
        if (kind == 注文票) {
            unsigned a, b;
            cin >> a >> b;
            cout << 運賃計算(a, b) << "\n";
        }
        if (kind == 運行情報) {
            unsigned c, d, e;
            cin >> c >> d >> e;
            graph.insert(Edge(c, d));
            graph.insert(Edge(d, c));
            運賃表.at(c).at(d) = min(運賃表.at(c).at(d), e);
            if (運賃表[c][d] != 運賃表.at(d).at(c)) {
                運賃表[d][c] = 運賃表[c][d];
                運賃表更新(c, d, e);
            }
        }
    }
    return 0;
}