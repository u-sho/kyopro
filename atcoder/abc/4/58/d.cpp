#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint X, Q;
	cin >> X >> Q;

	set<uint> written_on_bb;
	written_on_bb.insert(X);
	vector<uint> ans;
	for (uint i = 1; i <= Q; i++) {
		uint Ai, Bi;
		cin >> Ai >> Bi;
		written_on_bb.insert(Ai);
		written_on_bb.insert(Bi);

		ans.push_back(*next(written_on_bb.begin(), i));
	}

	for (const uint& a : ans) cout << a << '\n';

	return 0;
}
