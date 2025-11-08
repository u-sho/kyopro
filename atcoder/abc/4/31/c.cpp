#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, M, K;
	cin >> N >> M >> K;
	vector<uint> H(N);
	for (uint& Hi : H) cin >> Hi;
	multiset<uint> B;
	for (uint i = 0; i < M; i++) {
		uint Bi;
		cin >> Bi;
		B.insert(Bi);
	};

	ranges::sort(H);

	uint robot_buildable = 0;
	for (const uint Hi : H) {
		const auto it = B.lower_bound(Hi);
		if (it == B.end()) break;
		B.erase(it);
		++robot_buildable;
	}

	if (robot_buildable >= K) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	return 0;
}
