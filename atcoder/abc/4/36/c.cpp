#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, M;
	cin >> N >> M;
	vector<pair<uint, uint>> RC(M);
	for (auto& RCi : RC) cin >> RCi.first >> RCi.second;

	set<pair<uint, uint>> is_covered;

	uint counter = 0;
	for (const auto& [Ri, Ci] : RC) {
		if (is_covered.find({Ri, Ci}) == is_covered.end() &&
		    is_covered.find({Ri + 1, Ci}) == is_covered.end() &&
		    is_covered.find({Ri, Ci + 1}) == is_covered.end() &&
		    is_covered.find({Ri + 1, Ci + 1}) == is_covered.end()) {
			is_covered.insert({Ri, Ci});
			is_covered.insert({Ri + 1, Ci});
			is_covered.insert({Ri, Ci + 1});
			is_covered.insert({Ri + 1, Ci + 1});
			++counter;
		}
	}

	cout << counter << '\n';

	return 0;
}
