#include <vector>
#include <string>
#include <iostream>
using namespace std;

uint64_t A, N;
bool is_A進回文(uint64_t n) {
	vector<uint> s;
	while (n > 0) {
		s.push_back(n % A);
		n /= A;
	}
	for (int i = 0; i <= s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1]) return false;
	}
	return true;
}

uint64_t get_偶数桁10進回文(string n) {
	n += string(n.rbegin(), n.rend()); // 文字列を逆順に追加
	return stoull(n);
}
uint64_t get_奇数桁10進回文(string n) {
	n += string(n.rbegin() + 1, n.rend()); // 文字列を逆順に追加（中央の数字を除く）
	return stoull(n);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> A;
	cin >> N;

	uint64_t sum = 0;

	// 2桁以上の十進回文を調べる
	for (uint64_t i = 1; i<=1'000'000; i++) {
		string s = to_string(i);
		uint64_t n = get_奇数桁10進回文(s);
		if (n > N) break;
		if (is_A進回文(n)) sum += n;

		n = get_偶数桁10進回文(s);
		if (n > N) continue;
		if (is_A進回文(n)) sum += n;
	}

	cout << sum << '\n';

	return 0;
}
