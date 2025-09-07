#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string S;
	cin >> S;
	uint i = S[0] - '0';
	char h = S[1];
	uint j = S[2] - '0';
	if (j < 8) {
		cout << i << h << (j + 1) << "\n";
	} else if (i < 8) {
		cout << (i + 1) << h << "1\n";
	}

	return 0;
}
