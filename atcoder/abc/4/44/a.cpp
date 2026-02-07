#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint N;
	cin >> N;
	cout << ((N % 10 == (N / 10) % 10 && N % 10 == N / 100) ? "Yes\n" : "No\n");

	return 0;
}
