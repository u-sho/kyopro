#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint T;  // <= 40000
	cin >> T;
	for (uint t = 0; t < T; t++) {
		uint N;  // <= 18
		cin >> N;
		string S;
		cin >> S;
		S = "0" + S;  // |S| = 2^N

		for (uint i = 1; i < S.size(); i++) {
			if (S[i] == '1') continue;
			bool is_touchable = false;
			for (uint j = 1; j <= i && j <= N; j++) {
				if (i & (1u << (j - 1))) {
					if (S[i - (1u << (j - 1))] == '1') continue;
					is_touchable = true;
					break;
				}
			}
			if (!is_touchable) S[i] = '1';
		}
		cout << (S.back() == '0' ? "Yes\n" : "No\n");
	}

	return 0;
}
