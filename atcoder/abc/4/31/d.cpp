#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	// まず全部体に取り付けると，sum(W)の重さとsum(Bi)のうれしさになる．
	// 体から頭に取り付けかえることを考えると，
	// 容量 sum(W), 重さ 2Wi, 価値 Hi-Bi のナップサック問題．

	// dp[i+1][w] := i番目までの品物の中から重さがwを超えないように選んだ時の，価値の総和の最大値
	// dp[i+1][w] :=  max(dp[i][w-2Wi] + Hi-Bi, dp[i][w]) if w >= 2Wi,
	//                dp[i][w]                           if w < 2Wi.
	// 答え dp[N][sum(W)] + sum(B)

	uint N;
	cin >> N;
	vector<int64_t> W(N), H(N), B(N);
	for (uint i = 0; i < N; i++) cin >> W[i] >> H[i] >> B[i];

	int64_t sumW = reduce(W.begin(), W.end(), 0ll);
	int64_t sumB = reduce(B.begin(), B.end(), 0ll);

	vector<vector<int64_t>> dp(N + 1u, vector<int64_t>(sumW + 1ull, 0ll));

	for (uint i = 0; i < N; i++) {
		for (uint w = 0; w <= sumW; w++) {
			if (w >= 2ll * W[i]) dp[i + 1][w] = max(dp[i][w - 2ll * W[i]] + H[i] - B[i], dp[i][w]);
			else dp[i + 1][w] = dp[i][w];

			// cout << i + 1 << "," << w << "," << dp[i + 1][w] << "\n";
		}
	}

	cout << dp[N][sumW] + sumB << endl;

	return 0;
}
