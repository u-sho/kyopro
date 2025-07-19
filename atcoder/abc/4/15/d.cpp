#include <bits/stdc++.h>
using namespace std;

bool op(const pair<uint64_t, uint64_t>& ab1,
        const pair<uint64_t, uint64_t>& ab2) {
	const uint64_t s1 = ab1.first - ab1.second;
	const uint64_t s2 = ab2.first - ab2.second;
	if (s1 == s2) return ab1.first < ab2.first;
	return s1 < s2;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint64_t N;
	uint M;
	cin >> N >> M;
	vector<pair<uint64_t, uint64_t>> AB(M);
	for (auto& [Ai, Bi] : AB) cin >> Ai >> Bi;
	ranges::sort(AB, op);

	uint64_t sum = 0;
	for (const auto& [A, B] : AB) {
		if (N < A) continue;
		uint64_t s  = (N - A) / (A - B) + 1;
		N          -= s * (A - B);
		sum        += s;
	}

	cout << sum << '\n';

	return 0;
}
