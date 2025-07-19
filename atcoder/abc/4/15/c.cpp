#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint T;  // <= 40000
	cin >> T;
	for (uint t = 0; t < T; t++) {
		uint N;  // <= 18
		cin >> N;
		string S;  // |S| < 2^N
		cin >> S;

		vector<uint> p;
		for (uint i = 1; i <= N; i++) p.push_back(i);

		bool yes = false;
		do {
			uint64_t sum = 0;
			for (const uint pi : p) {
				uint64_t pib = 1ull << (pi - 1ull);
				if (S[sum + pib - 1] == '1') break;
				sum += pib;
			}
			if (sum == (1ull << N) - 1u) {
				yes = true;
				break;
			}
		} while (ranges::next_permutation(p).found);
		cout << (yes ? "Yes\n" : "No\n");
	}

	return 0;
}
