#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, M;
	cin >> N >> M;
	set<pair<uint, uint>> regular_boat_service;
	for (uint i = 0; i < M; i++) {
		uint a, b;
		cin >> a >> b;
		regular_boat_service.insert({a, b});
	}

	// 1経由で行けるか
	for (uint i = 2; i < N; i++) {
		auto go   = regular_boat_service.find({1, i});
		auto back = regular_boat_service.find({i, N});
		if (go != regular_boat_service.end() &&
		    back != regular_boat_service.end()) {
			cout << "POSSIBLE\n";
			return 0;
		}
	}

	cout << "IMPOSSIBLE\n";

	return 0;
}
