#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string S;
	cin >> S;

	bool is_first = true;
	for (uint i = 0; i < S.length(); i++) {
		if (S[i] == '#') {
			cout << i + 1 << (is_first ? "," : "\n");
			is_first = !is_first;
		}
	}

	return 0;
}
