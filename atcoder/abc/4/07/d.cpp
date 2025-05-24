#include <bits/stdc++.h>
using namespace std;

uint H, W;
vector<uint64_t> A(30);
uint64_t solve(const uint k, uint64_t sum,
               vector<bool> d = vector<bool>(30, false), const uint ij = 0) {
    if (ij >= H * W - 1) return sum;

    const uint i = ij / W;
    const uint j = ij % W;

    // 横置き（右端にいないかつマスが埋まっていないとき）
    if (k == 1 && j < W - 1 && !d[ij] && !d[ij + 1]) {
        d[ij]      = true;
        d[ij + 1]  = true;
        sum       ^= A[ij] ^ A[ij + 1];
        return max(solve(0, sum, d, ij + 2),
                   max(solve(1, sum, d, ij + 2), solve(2, sum, d, ij + 2)));
    }

    // 縦置き
    if (k == 2 && ij + W <= H * W - 1 && !d[ij] && !d[ij + W]) {
        d[ij]      = true;
        d[ij + W]  = true;
        sum       ^= A[ij] ^ A[ij + W];
        return max(solve(0, sum, d, ij + 1),
                   max(solve(1, sum, d, ij + 1), solve(2, sum, d, ij + 1)));
    }

    // その他
    return max(solve(0, sum, d, ij + 1),
               max(solve(1, sum, d, ij + 1), solve(2, sum, d, ij + 1)));
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint64_t sum = 0;

    cin >> H >> W;
    for (uint ij = 0; ij < H * W; ij++) {
        cin >> A[ij];
        sum ^= A[ij];
    }

    // bit-DP は間に合わない<-嘘．間に合う
    // DP でいい感じに範囲を絞ってドミノを置く
    // （ドミノで (i,j) が埋まると sum ^= A[i][j] になる）

    uint64_t ans = max(solve(0, sum), max(solve(1, sum), solve(2, sum)));
    cout << ans << '\n';

    return 0;
}
