#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N, M;
	cin >> N >> M;
	vector<uint> W(N);
	for (uint &Wi : W) cin >> Wi;
	vector<vector<uint>> 辺from頂点(N);
	for (uint i = 0; i < M; i++) {
		uint u, v;
		cin >> u >> v;
		u--;
		v--;
		辺from頂点[u].push_back(v);
		辺from頂点[v].push_back(u);
	}

	vector<uint64_t> 必要な燃料の最小量to頂点(N, UINT64_MAX);
	vector<uint64_t> そのときの高橋くんの体重(N, UINT64_MAX);
	必要な燃料の最小量to頂点[0] = 0;     // 初期位置
	そのときの高橋くんの体重[0] = W[0];  // 初期位置

	queue<uint> q;
	q.push(0);
	while (!q.empty()) {
		const uint i = q.front();
		q.pop();
		for (const auto &to : 辺from頂点[i]) {
			const uint64_t 必要な燃料の量to頂点to =
				必要な燃料の最小量to頂点[i] + そのときの高橋くんの体重[i];
			if (必要な燃料の量to頂点to < 必要な燃料の最小量to頂点[to]) {
				// cout << "i: " << i << ", to: " << to
				// 	 << ", 必要な燃料の量to頂点to: " << 必要な燃料の量to頂点to
				// 	 << '\n';
				必要な燃料の最小量to頂点[to] = 必要な燃料の量to頂点to;
				そのときの高橋くんの体重[to] =
					そのときの高橋くんの体重[i] + W[to];
				q.push(to);
			}
		}
	}

	for (const uint64_t &ans : 必要な燃料の最小量to頂点) cout << ans << '\n';

	return 0;
}
