#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N;
	cin >> N;
	vector<bool> is_opened(102, true);
	for (uint i = 1; i <= N; i++) {
		uint Li;
		cin >> Li;
		is_opened[i] = (Li == 0);
	}

	vector<bool> reached(102, false);
	reached[0] = true;
	reached[N] = true;

	for (uint i = 0; i <= N; i++) {
		if (!is_opened[i + 1]) break;
		reached[i + 1] = true;
	}
	for (uint i = N; i > 0; i--) {
		if (!is_opened[i]) break;
		reached[i - 1] = true;
	}

	uint ans = 0;
	for (uint i = 1; i < N; i++)
		if (!reached[i]) ans++;

	cout << ans << "\n";

	return 0;
}
