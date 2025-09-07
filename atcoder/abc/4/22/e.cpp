#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N;  // 3 <= N <=5e5
	cin >> N;
	vector<pair<int, int>> xy(N);
	for (pair<int, int> &xyi : xy) cin >> xyi.first >> xyi.second;

	uint 過半数 = (N + 1u) / 2u;
	// ここ(i,
	// j)じゃなくて乱択で選ぶといいらしい（コンテスト中に自信持てなかった）
	for (uint i = 0; i < 過半数; i++) {
		for (uint j = i + 1; j < min(i + 過半数, N); j++) {
			int64_t dx = xy[j].first - xy[i].first;
			int64_t dy = xy[j].second - xy[i].second;

			if (N == 3u) {
				cout << "Yes\n";
				cout << dy << ' ' << -dx << ' '
					 << dx * xy[i].second - dy * xy[i].first << '\n';
				return 0;
			}

			uint count = 2;
			for (uint k = j + 1; k < N; k++) {
				int64_t dx2 = xy[k].first - xy[i].first;
				int64_t dy2 = xy[k].second - xy[i].second;
				if (dx * dy2 == dy * dx2) {
					count++;
					if (count >= 過半数) {
						cout << "Yes\n";
						cout << dy << ' ' << -dx << ' '
							 << dx * xy[i].second - dy * xy[i].first << '\n';
						return 0;
					}
				}

				if (N - (k + 1u) + count < 過半数) break;
			}
		}
	}

	cout << "No\n";
	return 0;
}
