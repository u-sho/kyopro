#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, K;
	cin >> N >> K;

	vector<tuple<uint64_t, uint, uint>> ABC(N);
	for (auto &[Ai, Bi, Ci] : ABC) {
		cin >> Ai >> Bi >> Ci;
	}

	vector<uint64_t> 入店時刻(N);
	using P = pair<uint64_t, uint>;
	priority_queue<P, vector<P>, greater<P>> 退店時刻人数;

	const auto &[A0, B0, C0] = ABC[0];
	退店時刻人数.push({A0 + B0, C0});
	入店時刻[0]   = A0;
	uint 店内人数 = C0;

	for (uint i = 1; i < N; i++) {
		const auto &[Ai, Bi, Ci] = ABC[i];
		auto 入店時刻i           = max(Ai, 入店時刻[i - 1]);
		while (!退店時刻人数.empty() && 店内人数 + Ci > K) {
			const auto [t, n] = 退店時刻人数.top();
			退店時刻人数.pop();
			入店時刻i  = max(t, 入店時刻i);
			店内人数  -= n;
		}
		店内人数 += Ci;
		退店時刻人数.push({入店時刻i + Bi, Ci});
		入店時刻[i] = 入店時刻i;
	}

	for (const auto &t : 入店時刻) {
		cout << t << "\n";
	}

	return 0;
}
