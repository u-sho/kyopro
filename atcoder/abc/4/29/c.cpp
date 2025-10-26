#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N;
	cin >> N;
	vector<uint> A(N);
	for (uint& Ai : A) cin >> Ai;

	map<uint, uint> count_Ai;
	for (const auto Ai : A) {
		auto it = count_Ai.find(Ai);
		if (it != count_Ai.end()) {
			it->second += 1;
		} else {
			count_Ai.emplace(Ai, 1u);
		}
	}

	uint64_t sum = 0;
	for (const auto& [Ai, count] : count_Ai) {
		if (count < 2) continue;
		sum += count * (count - 1ull) / 2ull * (N - count);
	}

	cout << sum << "\n";

	return 0;
}
