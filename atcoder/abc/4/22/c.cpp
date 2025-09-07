#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	for (cin >> T; T--;) {
		uint nA, nB, nC;
		cin >> nA >> nB >> nC;

		uint ans = min(nA, min(nC, (nA + nB + nC) / 3));
		cout << ans << "\n";
	}

	return 0;
}
