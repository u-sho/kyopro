#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, M;
	cin >> N >> M;
	vector<uint> C(M);
	for (uint& Ci : C) cin >> Ci;
	vector<pair<uint, uint>> AB(N);
	for (pair<uint, uint>& ABi : AB) cin >> ABi.first >> ABi.second;

	uint64_t sum = 0;
	for (const auto& [Ai, Bi] : AB) {
		if (C[Ai - 1] > 0) {
			sum       += min(C[Ai - 1], Bi);
			C[Ai - 1] -= min(C[Ai - 1], Bi);
		}
	}

	cout << sum << '\n';

	return 0;
}
