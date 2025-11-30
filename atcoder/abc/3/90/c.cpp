#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint H, W;
	cin >> H >> W;
	vector<string> S(H);
	for (string& Si : S) cin >> Si;

	// 黒マスは1つ以上存在する
	uint t = H, r = 0, b = 0, l = W;
	for (uint i = 0; i < H; i++) {
		for (uint j = 0; j < W; j++) {
			if (S[i][j] != '#') continue;

			t = min(t, i);
			r = max(r, j);
			b = max(b, i);
			l = min(l, j);
		}
	}

	// 黒マスの内側に白マスがあると不可能
	for (uint i = t; i <= b; i++) {
		for (uint j = l; j <= r; j++) {
			if (S[i][j] == '.') {
				cout << "No\n";
				return 0;
			}
		}
	}

	cout << "Yes\n";

	return 0;
}
