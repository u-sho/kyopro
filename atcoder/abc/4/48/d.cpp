#include <bits/stdc++.h>
using namespace std;

vector<uint> A;
vector<vector<uint>> tree;

map<uint, uint> writtens;
vector<bool> ans(200'005, false);

void dfs(const uint node, const uint pre_node, bool yes) {
	writtens[A[node]]++;
	ans[node] = yes || (writtens[A[node]] >= 2);

	for (const auto v : tree[node]) {
		if (v == pre_node) continue;
		dfs(v, node, ans[node]);
	}
	writtens[A[node]]--;
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

	set<uint> writtens;
	dfs(0, UINT_MAX, false);

	for (uint i = 0; i < N; i++) {
		cout << (ans[i] ? "Yes\n" : "No\n");
	}

	return 0;
}
