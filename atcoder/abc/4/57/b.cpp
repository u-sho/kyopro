#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N;
	cin >> N;
	vector<vector<uint>> A(N);
	for (auto& Ai : A) {
		uint Li;
		cin >> Li;
		Ai.resize(Li);
		for (uint& Aij : Ai) cin >> Aij;
	}
	uint X, Y;
	cin >> X >> Y;

	cout << A.at(X - 1).at(Y - 1) << endl;

	return 0;
}
