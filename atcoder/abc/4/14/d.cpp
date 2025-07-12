#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, M;
	cin >> N >> M;
	vector<uint64_t> X(N);
	for (uint64_t &Xi : X) cin >> Xi;
	ranges::sort(X);

	// X[i]とX[i+1]の間に基地局を建てると，distance[i]の電波強度でなんとかなる
	// 3つの家をカバーする時も同様
	vector<uint64_t> distance;
	for (uint i = 1; i < N; i++) {
		distance.push_back(X[i] - X[i - 1]);
	}
	ranges::sort(distance);

	uint64_t sum = 0;
	for (uint i = 0; i < N - M; i++) {
		sum += distance[i];
	}

	cout << sum << '\n';

	return 0;
}
