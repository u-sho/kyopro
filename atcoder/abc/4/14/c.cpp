#include <bits/stdc++.h>
using namespace std;

// 1-digit
vector<uint64_t> candidates_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

// 2-digits
vector<uint64_t> candidates_2 = {11, 22, 33, 44, 55, 66, 77, 88, 99};

vector<uint64_t> candidates_3, candidates_4, candidates_5, candidates_6,
	candidates_7, candidates_8, candidates_9, candidates_10, candidates_11,
	candidates_12;

bool is_N_ary_string_reversible(const uint N, uint64_t number) {
	string result;
	while (number > 0) {
		result += to_string(number % N);
		number /= N;
	}
	string reversed_result = result;
	ranges::reverse_copy(result, reversed_result.begin());

	return result == reversed_result;
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	for (const auto& c : candidates_2) {   // c: xx
		uint b3 = c / 10 * 100 + c % 10;   // -> b3: x0x
		uint b4 = c / 10 * 1000 + c % 10;  // -> b4: x00x
		for (auto d = 0ull; d < 10ull; d++) {
			candidates_3.push_back(b3 + d * 10);   // xdx
			candidates_4.push_back(b4 + d * 110);  // xddx
		}
	}

	for (const auto& c : candidates_4) {      // c: xyyx
		uint b5 = c / 100 * 1000 + c % 100;   // -> b5: xy0yx
		uint b6 = c / 100 * 10000 + c % 100;  // -> b6: xy00yx
		for (auto d = 0ull; d < 10ull; d++) {
			candidates_5.push_back(b5 + d * 100);   // xydyx
			candidates_6.push_back(b6 + d * 1100);  // xyddyx
		}
	}

	for (const auto& c : candidates_6) {
		uint b7 = c / 1000 * 10000 + c % 1000;   // -> b7: xyz0zyx
		uint b8 = c / 1000 * 100000 + c % 1000;  // -> b8: xyz00zyx
		for (auto d = 0ull; d < 10ull; d++) {
			candidates_7.push_back(b7 + d * 1000);   // xyzdzyx
			candidates_8.push_back(b8 + d * 11000);  // xyzddzyx
		}
	}

	for (const auto& c : candidates_8) {
		uint b9  = c / 10000 * 100000 + c % 10000;   // -> b9: xyzw0wzyx
		uint b10 = c / 10000 * 1000000 + c % 10000;  // -> b10: xyzw00wzyx
		for (auto d = 0ull; d < 10ull; d++) {
			candidates_9.push_back(b9 + d * 10000);     // xyzwdwzyx
			candidates_10.push_back(b10 + d * 110000);  // xyzwddwzyx
		}
	}

	for (const auto& c : candidates_10) {
		uint b11 = c / 100000 * 1000000 + c % 100000;   // -> b11: xyzwv0vwzyx
		uint b12 = c / 100000 * 10000000 + c % 100000;  // -> b12: xyzwv00vwzyx
		for (auto d = 0ull; d < 10ull; d++) {
			candidates_11.push_back(b11 + d * 100000);   // xyzwvdvwzyx
			candidates_12.push_back(b12 + d * 1100000);  // xyzwvddvwzyx
		}
	}

	vector<uint64_t> candidates;
	for (const auto& c : candidates_1) candidates.push_back(c);
	for (const auto& c : candidates_2) candidates.push_back(c);
	for (const auto& c : candidates_3) candidates.push_back(c);
	for (const auto& c : candidates_4) candidates.push_back(c);
	for (const auto& c : candidates_5) candidates.push_back(c);
	for (const auto& c : candidates_6) candidates.push_back(c);
	for (const auto& c : candidates_7) candidates.push_back(c);
	for (const auto& c : candidates_8) candidates.push_back(c);
	for (const auto& c : candidates_9) candidates.push_back(c);
	for (const auto& c : candidates_10) candidates.push_back(c);
	for (const auto& c : candidates_11) candidates.push_back(c);
	for (const auto& c : candidates_12) candidates.push_back(c);

	// inputs
	uint64_t A, N;
	cin >> A >> N;

	uint64_t ans = 0;
	for (const auto& c : candidates) {
		if (c > N) break;
		if (is_N_ary_string_reversible(A, c)) ans += c;
	}

	cout << ans << endl;

	return 0;
}
