#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N;
	uint64_t M;
	uint C;
	cin >> N >> M >> C;
	vector<uint64_t> A(N);
	for (uint64_t& Ai : A) cin >> Ai;
	ranges::sort(A);

	// C<=Nより2周分あればよい
	for (uint i = 0; i < N; i++) A.push_back(A[i] + M);

	uint64_t sum_Xi = 0;
	for (uint64_t i = 0; i < M;) {
		// auto new_j  = A[i] + 1ull;

		auto 一人目    = ranges::lower_bound(A, i + 1) - A.begin();
		auto C人目     = 一人目 + C - 1;
		auto Xiと1人目 = ranges::upper_bound(A, A[C人目]) - A.begin();

		auto Xi = (Xiと1人目 - 一人目);
		if (A[一人目] < M) {
			sum_Xi += Xi * (A[一人目] - i);
			i       = A[一人目];
		} else if (i < M - 1) {
			sum_Xi += Xi * (M - 1 - i);
			i       = M - 1;
		} else {
			sum_Xi += Xi;
			i      += 1;
		};
	}

	cout << sum_Xi << "\n";

	return 0;
}
