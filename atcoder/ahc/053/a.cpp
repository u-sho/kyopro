/**
 * @file a.cpp
 * @author u-sho (Shouhei Uechi)
 * @date 2024-06-15
 *
 * 標準入力1
 * @param N カード枚数
 * @param M L以上U以下の整数が i.i.d にM個生成される
 * @param L 下限
 * @param U 上限
 *
 * 標準出力2
 * A_1, ..., A_N (1 <= A_i <= U)
 *
 * 標準入力3
 * @param B_1, ..., B_M (L <= B_i <= U)
 *
 * 標準出力4
 * X_1, ... , X_N (X_i はカード i を選ぶなら 1, 選ばないなら 0)
 *
 * @brief 問題文
 * 2. 初めに 1 以上 U 以下の整数 A_1, ... , A_N を自由に選び，カード i に A_i
 * を書き込む．
 * 3. 次に，L 以上 U 以下の整数 B_1, ... , B_M が i.i.d に生成される．
 * 4. 最後に，N 枚以下のカードを選び，M 個の山に分ける（ただし，空の山でもよい）
 * 5. 各山について，その山に含まれるカードに書かれた整数の和を S_j (1<=j<=M)
 * とし，誤差 E = sum_{j=1}^{M} |S_j - B_j| を最小化することを目指す．
 */

#include <bits/stdc++.h>
using namespace std;

#define REP(i, n)  for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
	ios::sync_with_stdio(false);

	uint N, M, L, U;
	cin >> N >> M >> L >> U;

	vector<uint> A(N, (L + U) / 2u);
	if (N <= M) {
	} else if (N <= 2 * M) {
		for (uint i = 0; i < N - M; i++) A[i] = L + (U - L) / 3u;
		for (uint i = N - M; i + N - M < N; i++) A[i] = (U - L) / 3u;
	}
	for (const auto &Ai : A) cout << Ai << " ";
	cout << endl;

	return 0;
}
