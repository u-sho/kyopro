#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, K;
	cin >> N >> K;

	uint ans = 0;
	for (uint i = 1; i <= N; i++) {
		uint 桁和 = i % 10;
		for (uint j = i; j /= 10u; 桁和 += j % 10);
		if (桁和 == K) ++ans;
	}

	cout << ans << "\n";

	return 0;
}
