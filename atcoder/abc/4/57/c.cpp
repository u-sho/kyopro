#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N;
	uint64_t K;
	cin >> N >> K;
	vector<vector<uint>> A(N);
	for (auto& Ai : A) {
		uint Li;
		cin >> Li;
		Ai.resize(Li);
		for (uint& Aij : Ai) cin >> Aij;
	}
	vector<uint> C(N);
	for (uint& Ci : C) cin >> Ci;

	for (uint i = 0; i < N; i++) {
		if (uint64_t(C[i]) * A[i].size() < K) K -= uint64_t(C[i]) * A[i].size();
		else {
			K += A[i].size() - 1ull;
			K %= A[i].size();
			cout << A[i][K] << "\n";
			return 0;
		}
	}
	return 0;
}
