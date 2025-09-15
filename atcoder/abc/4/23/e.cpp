#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	size_t N, Q;
	cin >> N >> Q;
	vector<uint64_t> A(N), L(Q), R(Q);
	for (auto &Aj : A) cin >> Aj;
	for (uint i = 0; i < Q; i++) cin >> L[i] >> R[i];

	// TLE
	vector<vector<uint64_t>> sum_sum_A_from(N, vector<uint64_t>(N, 0));
	for (uint l = 0; l < N; l++) {
		for (uint r = l; r < N; r++) {
			if (r) sum_sum_A_from[l][r] = sum_sum_A_from[l][r - 1];
			for (uint j = l; j <= r; j++) {
				sum_sum_A_from[l][r] += A[j] * (j - l + 1ull);
			}
		}
	}

	for (uint i = 0; i < Q; i++) {
		cout << sum_sum_A_from[L[i] - 1][R[i] - 1] << "\n";
	}

	return 0;
}
