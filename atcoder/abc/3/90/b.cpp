// 23:44
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N;
	cin >> N;
	vector<uint> A(N);
	for (uint& Ai : A) cin >> Ai;

	for (uint i = 2; i < N; i++) {
		if ((uint64_t)A[i - 2] * (uint64_t)A[i] != (uint64_t)A[i - 1] * (uint64_t)A[i - 1]) {
			cout << "No\n";
			return 0;
		}
	}

	cout << "Yes\n";
	return 0;
}
