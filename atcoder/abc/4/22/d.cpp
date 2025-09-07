#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, K;  // N <= 20, K <= 1e9
	cin >> N >> K;

	const uint B_min       = K / (1u << N);  // 2^N <= 2^21 = 2,097,152
	const uint B_max_count = K - B_min * (1u << N);

	vector<uint> B = {K}, B2;
	for (uint i = 0; i < N; i++) {
		B2.clear();
		for (const uint b : B) {
			const uint b1 = b / 2u, b2 = (b + 1u) / 2u;
			B2.push_back(b1);
			B2.push_back(b2);
		}
		B = move(B2);
	}

	cout << (B_max_count ? "1\n" : "0\n");
	for (uint i = 0; i < B.size(); i++)
		cout << B[i] << (i + 1 < B.size() ? ' ' : '\n');

	return 0;
}
