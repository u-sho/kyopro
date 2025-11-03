#include <bits/stdc++.h>
using namespace std;

// #define DEBUG

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N;
	cin >> N;
	vector<uint> X(N);
	for (auto& Xi : X) cin >> Xi;

	set<uint> x;
	x.insert(0);
	uint64_t sum_d = UINT_MAX;
#ifdef DEBUG
	printf("  prev_di       di      next_di        sum_d\n");
#endif
	for (const uint Xi : X) {
		x.insert(Xi);

		const auto it_prev = --x.lower_bound(Xi);
		const auto it_next = x.upper_bound(Xi);
		const uint prev_Xi = *it_prev;
		const uint next_Xi = (it_next != x.end() ? *it_next : UINT_MAX);

		const uint di = min(next_Xi - Xi, Xi - prev_Xi);

		const uint prevprev_Xi = (it_prev != x.begin() ? *ranges::prev(it_prev) : 0);
		const uint nextnext_Xi = (it_next != x.end() ? *ranges::next(it_next) : UINT_MAX);

		const uint prev_di_old = prev_Xi ? min(prev_Xi - prevprev_Xi, next_Xi - prev_Xi) : next_Xi;
		const uint prev_di     = prev_Xi ? min(prev_Xi - prevprev_Xi, /**/ Xi - prev_Xi) : /**/ Xi;

		const uint next_di_old = min(nextnext_Xi - next_Xi, next_Xi - prev_Xi);
		const uint next_di     = min(nextnext_Xi - next_Xi, next_Xi - /**/ Xi);

		sum_d += di;
		sum_d -= prev_di_old - prev_di;
		sum_d -= next_di_old - next_di;
#ifdef DEBUG
		printf("pp: %u, p: %u, Xi: %u, n: %u, nn: %u\n", prevprev_Xi, prev_Xi, Xi, next_Xi,
		       nextnext_Xi);
		printf("%11u%11u%11u%18lu\n", prev_di, di, next_di, sum_d);
#else
		cout << sum_d << "\n";
#endif
	}

	return 0;
}
