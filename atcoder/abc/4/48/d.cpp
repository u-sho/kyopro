#include <bits/stdc++.h>
using namespace std;

vector<uint> A;
vector<vector<uint>> tree;
vector<int> ans;
void dfs(const uint node, const set<uint>& writtens, const set<uint>& visited, const bool yes) {
	if (ans[node] >= 0) return;

	set<uint> visited_n = visited, writtens_n = writtens;
	visited_n.emplace(node);

	if (writtens_n.find(A[node]) != writtens_n.end()) {
		writtens_n.emplace(node);
		ans[node] = 0;
	} else {
		ans[node] = yes ? 1 : 0;
	}

	for (const auto v : tree[node]) {
		if (visited_n.find(v) == visited_n.end()) continue;
		dfs(v, writtens_n, visited_n, ans[node]);
	}
	return;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N;
	cin >> N;
	A.resize(N);
	tree.resize(N);
	for (uint& Ai : A) cin >> Ai;
	for (uint i = 1; i < N; i++) {
		uint u, v;
		cin >> u >> v;
		tree[u - 1].push_back(v - 1);
		tree[v - 1].push_back(u - 1);
	}

	ans.resize(N, -1);

	set<uint> writtens, visited;
	dfs(0, writtens, visited, false);

	for (uint i = 0; i < N; i++) {
		cout << (ans[i] ? "Yes\n" : "No\n");
	}

	return 0;
}
