#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, M;
	cin >> N >> M;
	vector<string> S(N);
	for (auto& Si : S) cin >> Si;

	vector<vector<string>> visited;
	for (uint i = 0; i + M <= N; i++) {
		for (uint j = 0; j + M <= N; j++) {
			bool has_same_area = false;
			for (const auto& vi : visited) {
				bool is_same_area = true;
				for (uint k = 0; k < M; k++) {
					if (S[i + k].substr(j, M) != vi[k]) {
						is_same_area = false;
						break;
					}
				}
				if (is_same_area) {
					has_same_area = true;
					break;
				}
			}
			if (!has_same_area) {
				vector<string> v;
				for (uint l = 0; l < M; l++) {
					v.push_back(S[i + l].substr(j, M));
				}
				visited.push_back(v);
			}
		}
	}

	cout << visited.size() << "\n";

	return 0;
}
