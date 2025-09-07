#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint H, W;
	cin >> H >> W;
	vector<string> S(H);
	for (auto& Si : S) cin >> Si;

	bool ok = true;
	for (uint i = 0; i < H; i++) {
		for (uint j = 0; j < W; j++) {
			if (S[i][j] == '.') continue;

			uint count = 0;
			if (i > 0 && S[i - 1][j] == '#') count++;
			if (i < H - 1 && S[i + 1][j] == '#') count++;
			if (j > 0 && S[i][j - 1] == '#') count++;
			if (j < W - 1 && S[i][j + 1] == '#') count++;

			if (count != 2 && count != 4) ok = false;
		}
	}

	cout << (ok ? "Yes\n" : "No\n");

	return 0;
}
