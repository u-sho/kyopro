#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N;
	cin >> N;

	vector<vector<uint>> a(N, vector<uint>(N, 0));
	for (uint i = 0, r = 0, c = N / 2u, k = 0; i < N * N; i++) {
		a[r % N][c % N] = ++k;
		if (a[(r + N - 1) % N][(c + 1) % N]) r++;
		else r = (r + N - 1) % N, c++;
	}

	for (const auto& ai : a) {
		for (uint j = 0; j < N; j++) {
			cout << ai[j] << (j + 1 != N ? ' ' : '\n');
		}
	}

	return 0;
}
