#include <bits/stdc++.h>
int main() {
	using std::cin;
	uint N;
	cin >> N;
	std::vector<uint> A(N);
	for (uint &Ai : A) cin >> Ai;
	uint X;
	cin >> X;

	std::cout << (std::ranges::find(A, X) != A.end() ? "Yes\n" : "No\n");
}
