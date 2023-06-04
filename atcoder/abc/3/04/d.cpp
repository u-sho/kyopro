#include <bits/stdc++.h>
using namespace std;

using Coordinates = pair<int, int>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

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

    unsigned m = N;  // ピースに載っているイチゴの個数としてあり得る最小値
    unsigned M = 0U;  // ピースに載っているイチゴの個数としてあり得る最大値
    if (N < (A + 1ULL) * (B + 1ULL)) m = 0U;  // why: 鳩の巣原理的なやつ

    // x-y座標系をa-b座標系に圧縮する（どのピースに乗っているか）
    multiset<const Coordinates> ab_coordinates;
    a.push_back(W);
    b.push_back(H);
    for (const Coordinates &pqi : pq) {
        pqi.first  = *upper_bound(a.begin(), a.end(), pqi.first);
        pqi.second = *upper_bound(b.begin(), b.end(), pqi.second);
        ab_coordinates.insert(pqi);
    }
}
