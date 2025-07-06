#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, L;
	cin >> N >> L;
	vector<uint> d(N - 1u);
	for (uint &di : d) cin >> di;

	if (L % 3u) {
		cout << "0\n";
		return 0;
	}

	vector<uint> points = {0};
	for (const uint di : d) points.push_back((points.back() + di) % L);
	ranges::sort(points);

	uint64_t ans = 0ull;
	for (const uint p1 : points) {
		if (p1 >= L / 3u) break;

		const uint p2 = p1 + L / 3u;
		const uint p3 = p1 + 2u * (L / 3u);

		auto it2 = ranges::lower_bound(points, p2);
		auto it3 = ranges::lower_bound(points, p3);

		if (it2 == points.end() || *it2 != p2) continue;
		if (it3 == points.end() || *it3 != p3) continue;

		auto c2 = ranges::upper_bound(points, p2) - it2;
		auto c3 = ranges::upper_bound(points, p3) - it3;

		ans += (uint64_t)c2 * (uint64_t)c3;
	}
	cout << ans << '\n';

	return 0;
}
