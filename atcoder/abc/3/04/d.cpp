#include <bits/stdc++.h>

using Coordinates = std::pair<int, int>;

/* 重複要素を削除する */
template <class Container>
void deduplicate(Container &v) {
    std::sort(begin(v), end(v));
    v.erase(std::unique(begin(v), end(v)), end(v));
    return;
}

int main() {
    using namespace std;
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    /* inputs */
    unsigned W, H, N, A, B;
    cin >> W >> H;              // ケーキのサイズ <= 1e9
    cin >> N;                   // 苺の数 <= 2e5
    vector<Coordinates> pq(N);  // 苺の位置: (x, y)
    for (Coordinates &pqi : pq) cin >> pqi.first >> pqi.second;
    cin >> A;               // y軸に並行なカットの数
    vector<unsigned> a(A);  // y軸に並行なカット
    for (unsigned &ai : a) cin >> ai;
    cin >> B;               // x軸に並行なカットの数
    vector<unsigned> b(B);  // x軸に並行なカット
    for (unsigned &bi : b) cin >> bi;

    /* solve */
    // x-y座標系をa-b座標系に圧縮する（どのピースに乗っているか）
    multiset<Coordinates> ab_coordinates;
    a.push_back(W);
    b.push_back(H);
    for (Coordinates &pqi : pq) {
        pqi.first  = *upper_bound(a.begin(), a.end(), pqi.first);
        pqi.second = *upper_bound(b.begin(), b.end(), pqi.second);
        ab_coordinates.insert(pqi);
    }
    deduplicate(pq);  // 同じピースに乗っている苺を同一視

    // 数える．
    unsigned m = N;  // ピースに載っているイチゴの個数としてあり得る最小値
    unsigned M = 0U;  // ピースに載っているイチゴの個数としてあり得る最大値
    if (pq.size() < (A + 1ULL) * (B + 1ULL)) m = 0U;  // why: 鳩の巣原理的なやつ
    for (const Coordinates &pqi : pq) {
        unsigned count = ab_coordinates.count(pqi);
        m              = min(m, count);
        M              = max(M, count);
    }

    /* output */
    cout << m << ' ' << M << '\n';
    return 0;
}
