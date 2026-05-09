#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N;
	cin >> N;
	vector<uint> A(N);
	for (uint& Ai : A) cin >> Ai;
	uint X;
	cin >> X;

	cout << A.at(X - 1) << endl;

	return 0;
}
