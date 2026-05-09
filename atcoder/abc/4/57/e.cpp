#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, M;
	cin >> N >> M;
	vector<pair<uint, uint>> LR(M), RL;
	for (pair<uint, uint>& LRi : LR) {
		cin >> LRi.first >> LRi.second;
		RL.push_back({LRi.second, LRi.first});
	}
	ranges::sort(LR);  // Lでソート
	ranges::sort(RL);  // Rでソート

	uint Q;
	cin >> Q;
	for (uint q = 1; q <= Q; q++) {
		uint Sq, Tq;
		cin >> Sq >> Tq;

		auto itL = ranges::upper_bound(LR, make_pair(Sq, Tq));
		if (itL == LR.begin() || (--itL)->first != Sq) {
			cout << "No\n";
			continue;
		}
		auto itR = ranges::lower_bound(RL, make_pair(Tq, Sq));
		if (itR == RL.end() || itR->first > Tq) {
			cout << "No\n";
			continue;
		}

		cout << Sq << "\t" << Tq << "\t" << (itL->first) << "\t" << (itL->second) << "\t"
			 << (itR->second) << "\t" << (itR->first) << "\n";

		if (itL->second + 1 < itR->second) {
			cout << "No\n";
			continue;
		}

		// 同じ布？
		if (itL == itR) {
			if (itL == LR.begin() || (--itL)->first != Sq) {
				cout << "No\n";
				continue;
			}
			if (itL->second + 1 < itR->second) {
				cout << "No\n";
				continue;
			}
		}

		cout << "Yes\n";
	}

	return 0;
}
