#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint X, C;
	cin >> X >> C;

	cout << X / (1000 + C) * 1000 << "\n";

	return 0;
}
