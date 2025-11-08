#include <bits/stdc++.h>
using namespace std;

vector<bool> usingW(102, false);

int main() {
	uint X, N;
	cin >> X;
	cin >> N;
	vector<uint> W(N);
	for (uint& Wi : W) cin >> Wi;

	int Q, Pi;
	for (cin >> Q; Q--;) {
		cin >> Pi;
		if (usingW[Pi - 1]) {
			X -= W[Pi - 1];
		} else {
			X += W[Pi - 1];
		}
		usingW[Pi - 1].flip();
		cout << X << "\n";
	}

	return 0;
}
