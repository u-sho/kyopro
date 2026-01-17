#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, K;
	uint64_t X;
	cin >> N >> K >> X;
	vector<uint> A(N);
	for (uint& Ai : A) cin >> Ai;

	ranges::sort(A);

	if (reduce(A.begin(), A.begin() + K, 0ull) < X) {
		cout << "-1\n";
		return 0;
	}

	uint ans     = N - K;
	uint64_t sum = 0;
	for (uint i = K - 1u; true; i--) {
		sum += A[i];
		ans++;
		if (sum >= X) {
			cout << ans << "\n";
			return 0;
		}
	}

	return 0;
}
