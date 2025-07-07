#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N;
	cin >> N;
	vector<uint> X(N), Y(N);
	for (uint &Xi : X) cin >> Xi;
	Y = X;
	ranges::sort(Y);
	uint c = (Y[N / 2u - 1u] + Y[N / 2u]) / 2;

	for (const uint Xi : X) {
		if (Xi <= c) cout << Y[N / 2u] << '\n';
		else cout << Y[N / 2u - 1u] << '\n';
	}

	return 0;
}
