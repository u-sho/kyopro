#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, Q;
	cin >> N >> Q;
	vector<uint> A(N);
	for (uint& Ai : A) cin >> Ai;
	vector<uint> sA = A;
	ranges::sort(sA);

	uint K;
	vector<uint> B;
	for (uint i = 1; i <= Q; i++) {
		cin >> K;
		B.resize(K);
		for (uint& Bi : B) {
			cin >> Bi;
			Bi = A[Bi - 1];
		}
		ranges::sort(B);

		uint argmin_sA = 0;
		for (const auto Bi : B) {
			if (sA[argmin_sA] == Bi) {
				++argmin_sA;
			} else {
				break;
			}
		}
		cout << sA[argmin_sA] << '\n';
	}

	return 0;
}
