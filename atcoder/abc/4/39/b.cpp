#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N;
	cin >> N;

	set<uint> rec = {0};
	while (rec.find(N) == rec.end()) {
		if (N == 1u) {
			cout << "Yes\n";
			return 0;
		}

		uint s = 0;
		for (rec.insert(N); N; N /= 10u) {
			s += (N % 10) * (N % 10);
		}
		// cout << s << "\n";
		N = s;
	}

	cout << "No\n";

	return 0;
}
