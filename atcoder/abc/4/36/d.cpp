#include <bits/stdc++.h>
using namespace std;

using Coordinates = pair<uint, uint>;

/** Key: 座標，Value: 親 */
map<Coordinates, Coordinates> uf;
map<char, vector<Coordinates>> warp;

[[no_discard]] Coordinates get_root(const Coordinates& c) {
	if (uf[c] == c) return c;
	return uf[c] = get_root(c);
}

bool merge_root(const Coordinates& c1, const Coordinates& c2) {
	const auto r1 = get_root(c1);
	const auto r2 = get_root(c2);
	if (c1 == c2) return false;
	uf[r1] = r2;
	return true;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint H, W;
	cin >> H >> W;
	vector<string> S(H);
	for (auto& Si : S) cin >> Si;

	for (uint h = 0; h < H; h++) {
		for (uint w = 0; w < W; w++) {
			const auto is_block = S[h][w] == '#';
			if (is_block) continue;

			const auto is_empty = S[h][w] != '.';
			if (is_empty) {
				uf.insert(make_pair<Coordinates, Coordinates>({h, w}, {h, w}));
				continue;
			}

			// ワープ
			const auto it = warp.find(char(S[h][w]));
			if (it == warp.end()) warp.insert({char(S[h][w]), vector<Coordinates>(1, {h, w})});
			else warp.at(char(S[h][w])).push_back({h, w});
		}
	}

	// ワープをつなげる
	for (const auto& [warp_to, vec_hw] : warp) {
		for (const auto& hw : vec_hw) {
			uf[hw] = vec_hw[0];
		}
	}

	// 移動できる場所をつなげる
	for (uint h = 0; h + 1 < H; h++) {
		for (uint w = 0; w + 1 < W; w++) {
			const auto is_block = S[h][w] == '#';
			if (is_block) continue;

			if (S[h + 1][w] != '#') merge_root({h, w}, {h + 1, w});
			if (S[h][w + 1] != '#') merge_root({h, w}, {h, w + 1});
		}
	}

	return 0;
}
