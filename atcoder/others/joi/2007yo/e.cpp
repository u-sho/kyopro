#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
using i_type = unsigned;
using j_type = unsigned;
using k_type = unsigned;
using test_type = tuple<i_type, j_type, k_type>;

// 入力値
i_type a;
j_type b;
k_type c;

// 不合格のテスト
vector<test_type> tests;

// 0: 故障
// 1: 正常
// 2: よくわからない
typedef enum {
	BROKEN,
	PERFECT,
	UNKNOWN,
} Test_Result_E;

vector<Test_Result_E> powers(102u, UNKNOWN);
vector<Test_Result_E> motors(102u, UNKNOWN);
vector<Test_Result_E> cables(102u, UNKNOWN);

int main() {
	cin >> a >> b >> c;
	unsigned N; cin >> N; // 検査回数
	while(N--) {
		unsigned i, j, k, r;
		cin >> i >> j >> k >> r;
		j -= a;
		k -= a + b;
		if (r) { // passed
			powers.at(i) = PERFECT;
			motors.at(j) = PERFECT;
			cables.at(k) = PERFECT;
		} else {
			test_type test(i,j,k);
			tests.push_back(test);
			if (powers.at(i) != PERFECT) powers[i] = UNKNOWN;
			if (motors.at(j) != PERFECT) motors[j] = UNKNOWN;
			if (cables.at(k) != PERFECT) cables[k] = UNKNOWN;
		}
	}

	for (const auto &[i,j,k] : tests) {
		if (powers.at(i) == PERFECT && motors.at(j) == PERFECT) cables.at(k) = BROKEN;
		if (motors.at(j) == PERFECT && cables.at(k) == PERFECT) powers.at(i) = BROKEN;
		if (cables.at(k) == PERFECT && powers.at(i) == PERFECT) motors.at(j) = BROKEN;
	}

	for (i_type i = 1u; i <= a; i++) {
		cout << powers[i] << '\n';
	}
	for (j_type j = 1u; j <= b; j++) {
		cout << motors[j] << '\n';
	}
	for (k_type k = 1u; k <= c; k++) {
		cout << cables[k] << '\n';
	}

	return 0;
}

