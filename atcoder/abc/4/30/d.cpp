#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

#define REP(i, n)  for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N;
	cin >> N;
	vector<uint> X(N);
	for (auto& Xi : X) cin >> Xi;
	ranges::sort(X);

	if (N == 1) {
		cout << "0\n";
		return 0;
	}

	uint64_t sum = 0;
	for (uint i = 0; i < N; i++) {
		if (i == 0) sum += X[i + 1] - X[i];
		else if (i == N - 1) sum += X[i] - X[i - 1];
		else sum += min(X[i] - X[i - 1], X[i + 1] - X[i - 1]);
	}
	cout << sum << "\n";

	return 0;
}
