#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N;
	cin >> N;
	vector<uint> A(N);
	for (uint& Ai : A) cin >> Ai;
	ranges::sort(A);

	vector<bool> warikireru(1000006, false);
	for (uint j = 0; j < N; j++) {  // N <= 2e5
		if (j != 0 && A[j] == A[j - 1]) continue;
		if (j != N - 1 && A[j] == A[j + 1]) warikireru[A[j]] = true;
		if (A[j] == 1) {
			std::fill(warikireru.begin() + 2, warikireru.end(), true);
			break;
		}
		for (uint i = 2u; i * A[j] <= 1000000; i++) {
			warikireru[i * A[j]] = true;
		}
	}

	uint ans = 0;
	for (const uint Ai : A) {
		if (!warikireru[Ai]) ++ans;
	}

	cout << ans << '\n';
	return 0;
}
