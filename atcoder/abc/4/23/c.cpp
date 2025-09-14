#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, R;
	cin >> N >> R;
	vector<bool> is_opened(102, false);
	for (uint i = 1; i <= N; i++) {
		uint Li;
		cin >> Li;
		is_opened[i] = (Li == 0);
	}

	uint left = R + 1, right = R;
	for (uint i = 1; i <= R; i++) {
		if (is_opened[i]) {
			left = i;
			break;
		}
	}
	for (uint i = N; i > R; i--) {
		if (is_opened[i]) {
			right = i;
			break;
		}
	}

	uint r_open = 0, l_open = 0, r_close = 0, l_close = 0;
	for (uint i = left; i <= R; i++) {
		if (is_opened[i]) l_open++;
		else l_close++;
	}
	for (uint i = R + 1; i <= right; i++) {
		if (is_opened[i]) r_open++;
		else r_close++;
	}

	cout << (2u * (l_close + r_close) + l_open + r_open) << "\n";

	return 0;
}
