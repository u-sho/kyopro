#include <bits/stdc++.h>
using namespace std;

#define divmod(n, d) make_pair((n) / (d), (n) % (d))

int main() {
	uint N;
	cin >> N;
	vector<uint> A(N);
	for (uint& Ai : A) cin >> Ai;
	ranges::sort(A);

	vector ans = {0ul};
	for (uint i = 0; i < N; i++) {
		if (i > 0 && A[i] == A[i - 1]) continue;
		for (uint j = ans.size(); j <= A[i]; j++) {
			const auto& [x, y] = divmod(ans.back() + N - i, uint64_t(10));
			ans.back()         = y;
			ans.push_back(x);  // 最大 6e15 くらい？
		}
	}

	if (ans.size() > 1 && ans.back() == 0) ans.pop_back();
	for_each(ans.rbegin(), ans.rend(), [](auto ci) { cout << ci; });

	return 0;
}
