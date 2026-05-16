#include <bits/stdc++.h>
using namespace std;

int main(void) {
	string S;
	cin >> S;

	uint64_t 部分文字列数 = 0;
	for (uint i = 0; i < S.length(); i++) {
		if (S[i] != 'C') continue;
		部分文字列数 += min(i + 1u, (uint)S.length() - i);
	}
	cout << 部分文字列数 << '\n';
}
