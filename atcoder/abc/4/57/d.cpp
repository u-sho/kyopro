#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	// min Ai のありうる値の最大値を [0, UINT64_MAX] で二分探索

	uint N;
	uint64_t K;
	cin >> N >> K;
	vector<uint64_t> A(N);
	for (uint64_t& Ai : A) cin >> Ai;

	uint64_t left = 0, right = UINT64_MAX, min_Ai = UINT16_MAX / 2ull;
	// cout << "left\tright\tmin_Ai\tk\n";
	do {
		uint64_t k = 0;
		for (uint64_t i = 1; i <= N; i++) {
			if (min_Ai <= A[i - 1]) continue;
			k += (min_Ai - A[i - 1] + i - 1) / i;
			if (k > K) break;
		}
		// cout << left << "\t" << right << "\t" << min_Ai << "\t" << k << "\n";
		if (k == K) break;

		if (k < K) left = min_Ai;
		else right = min_Ai;

		min_Ai = left + (right - left) / 2ull;
	} while (left < min_Ai);

	cout << min_Ai << endl;

	return 0;
}
