#include <bits/stdc++.h>
using namespace std;

uint H, W;
vector<uint64_t> A(30);
uint64_t solve(const uint k, uint64_t sum, uint32_t covered = 0u,
               const uint ij = 0) {
    auto is_covered = [&](const uint ij) { return !!(covered & (0b1 << ij)); };

    // 範囲外
    if (ij >= H * W - 1) return sum;

    // 置きたいけど置けない
    if (k && is_covered(ij)) return sum;
    if (k == 1 && (W == 1 || ij % W == W - 1 || is_covered(ij + 1))) return sum;
    if (k == 2 && (H == 1 || ij + W >= H * W || is_covered(ij + W))) return sum;

    // 横置き
    if (k == 1) {
        covered ^= 0b11 << ij;
        sum     ^= A[ij] ^ A[ij + 1];
        return max(solve(0, sum, covered, ij + 2),
                   max(solve(1, sum, covered, ij + 2),
                       solve(2, sum, covered, ij + 2)));
    }

    // 縦置き
    if (k == 2) {
        covered ^= 0b1 << ij;
        covered ^= 0b1 << (ij + W);
        sum     ^= A[ij] ^ A[ij + W];
        return max(solve(0, sum, covered, ij + 1),
                   max(solve(1, sum, covered, ij + 1),
                       solve(2, sum, covered, ij + 1)));
    }

    // 置かない
    return max(
        solve(0, sum, covered, ij + 1),
        max(solve(1, sum, covered, ij + 1), solve(2, sum, covered, ij + 1)));
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
    // （ドミノで (i,j) が埋まると sum ^= A[i][j] になる）

    uint64_t ans = max(solve(0, sum), max(solve(1, sum), solve(2, sum)));
    cout << ans << '\n';

    return 0;
}
