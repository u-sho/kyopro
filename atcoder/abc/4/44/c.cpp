#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N;
	cin >> N;
	vector<uint> A(N);
	for (uint& Ai : A) cin >> Ai;
	ranges::sort(A);

	// 少なくとも1本は折れてない
	uint mam_A = ranges::distance(A.begin(), ranges::lower_bound(A, A.back()));
	if (mam_A % 2 == 0) {
		bool isL = true;
		for (uint i = 0; i < mam_A / 2; i++) {
			isL &= (A[i] + A[mam_A - i - 1] == A.back());
		}
		if (isL) cout << A.back() << ' ';
	}

	// 全部折れてる
	if (N % 2 == 0) {
		bool isL = true;
		for (uint i = 1; i < N / 2; i++) {
			isL &= (A[i] + A[N - i - 1] == A.back() + A.front());
		}
		if (isL) cout << A.back() + A.front();
	}

	return 0;
}
