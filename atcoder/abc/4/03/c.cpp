#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, M, Q;
	cin >> N >> M >> Q;

	set<pair<uint, uint>> can_view;
	for (uint q = 0; q < Q; q++) {
		uint query_type, X, Y;
		cin >> query_type;
		if (query_type == 1) {
			cin >> X >> Y;
			can_view.emplace(X, Y);
		}
		if (query_type == 2) {
			cin >> X;
			can_view.emplace(X, 0);
		}
		if (query_type == 3) {
			cin >> X >> Y;
			if (can_view.contains({X, 0}) || can_view.contains({X, Y})) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	}

	return 0;
}
