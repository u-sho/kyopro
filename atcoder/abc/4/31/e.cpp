/**
 * A: T-B, L-R
 * B: T-R, L-B
 * C: R-B, L-T
 * の無向グラフ．辺のコストを0とする．
 * なお，A,B,Cの付け替えコストを1とする．
 */

#include <bits/stdc++.h>
using namespace std;

int T, H, W;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	for (cin >> T; T--;) {
		cin >> H >> W;
		vector<string> S(H);
		for (auto& Si : S) cin >> Si;

		vector<vector<uint>> c(H + 1, vector<uint>(2u * (W + 1u), 0));
		// c[i][j]: i行目, j/2列目の j%2 ? T : L.
		// Start: c[0][0], Goal: c[H-1][2*W+1]
		for (uint i = 0; i < H; i++) {
			for (uint j = 0; j < 2u * (W + 1u); j++) {
				if (j % 2) {
					// T
				}
			}
		}
	}

	return 0;
}
