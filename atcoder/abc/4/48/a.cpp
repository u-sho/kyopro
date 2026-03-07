#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, X;
	cin >> N >> X;
	vector<uint> A(N);
	for (uint& Ai : A) cin >> Ai;

	for (const auto Ai : A) {
		if (Ai < X) {
			X = Ai;
			cout << "1\n";
		} else {
			cout << "0\n";
		}
	}

	return 0;
}
