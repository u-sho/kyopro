#include <bits/stdc++.h>
using namespace std;

int main() {
	uint N;
	cin >> N;

	string S;
	for (uint i = 0; i < N; i++) {
		char Xi;
		uint64_t Yi;
		cin >> Xi;
		cin >> Yi;
		if (Yi > 100) {
			cout << "Too Long" << endl;
			return 0;
		}
		string Xi_str(Yi, Xi);
		S += Xi_str;
	}

	if (S.length() > 100) {
		cout << "Too Long" << endl;
		return 0;
	}

	cout << S << endl;

	return 0;
}
