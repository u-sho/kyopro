#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, A, B;
	cin >> N >> A >> B;
	string S;
	cin >> S;

	vector<uint> count_a, count_b;
	count_a.push_back(0);
	count_b.push_back(0);
	for (uint i = 0; i < N; i++) {
		count_a.push_back(count_a[i] + (S[i] == 'a'));
		count_b.push_back(count_b[i] + (S[i] == 'b'));
	}

	uint64_t ans = 0;
	for (uint l = 0; l + A <= N; l++) {
		auto itr = lower_bound(count_a.begin(), count_a.end(), count_a[l] + A);
		if (itr == count_a.end()) break;

		uint r_l = itr - count_a.begin();
		auto it  = lower_bound(count_b.begin(), count_b.end(), count_b[l] + B);
		uint r_r = it - count_b.begin();
		if (r_l < r_r) ans += r_r - r_l;
	}

	cout << ans << "\n";

	return 0;
}
