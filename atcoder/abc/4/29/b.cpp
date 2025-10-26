#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, M;
	cin >> N >> M;
	vector<uint> A(N);
	for (uint& Ai : A) cin >> Ai;

	const auto sum = reduce(A.begin(), A.end(), 0u);
	for (const auto Ai : A) {
		if (M + Ai == sum) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";

	return 0;
}
