#include <iostream>
#include <vector>

int main() {
	using namespace std;
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, L, R;
	cin >> N >> L >> R;
	vector<pair<uint, uint>> XY(N);
	for (auto &[X, Y] : XY) cin >> X >> Y;

	uint listners = 0;
	for (const auto &[X, Y] : XY) {
		if (X <= L && R <= Y) listners++;
	}

	cout << listners << '\n';
	return 0;
}
