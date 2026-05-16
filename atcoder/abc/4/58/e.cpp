#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 998244353;  // log(MOD) ~ 30

vector<int> permutations = {1, 1};
vector<int> inverses(3000006, 0);

[[no_discard]] int inverse(int x) {
	if (inverses[x]) return inverses[x];
	int a = x % MOD, b = MOD, u = 1, v = 0, t;
	while (b > 0) {
		t = a / b;
		std::swap(a -= t * b, b);
		std::swap(u -= t * v, v);
	}
	return inverses[x] = u % MOD;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	for (long long i = 2; i < 3'000'006; i++) {
		permutations.push_back((permutations.back() * i) % MOD);
	}

	long long X1, X2, X3;
	cin >> X1 >> X2 >> X3;

	const int head = ((((long long)permutations[X3 - 1] * permutations[X1 - 1]) % MOD) *
	                  (long long)permutations[X2 + 1]) %
	                 MOD;
	int ans        = 0;
	for (long long i = 1; i <= X1; i++) {
		for (long long j = 1; j <= X3 && i + j <= X2 + 1; j++) {
			int bottom = (inverse(X1 - i) * (long long)inverse(X3 - j)) % MOD;
			bottom     = (bottom * (long long)inverse(i)) % MOD;
			bottom     = (bottom * (long long)inverse(j)) % MOD;
			bottom     = (bottom * (long long)inverse(i - 1)) % MOD;
			bottom     = (bottom * (long long)inverse(j - 1)) % MOD;
			bottom     = (bottom * (long long)inverse(X2 + 1 - i - j)) % MOD;

			ans = ((long long)ans + ((head * (long long)bottom) % MOD)) % MOD;
		}
	}

	cout << ans << '\n';

	return 0;
}
