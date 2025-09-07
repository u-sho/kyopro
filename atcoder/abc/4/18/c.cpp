/**
 * @file c.cpp
 * @author u_sho (Uechi,Shouhei)
 *
 * @param N ティーバッグのフレーバーの種類数 (1 <= N <= 3e5)
 * @param A Ai: フレーバーi (i∈[1,N]) のティーバッグの個数 (1 <= Ai <= 1e6)
 * @param Q クエリ数 (1 <= Q <= 3e5)
 * @param B Bj: j番目のゲーム (j∈[1,Q]) の難易度 (1 <= Bj <= min(1e6, sum(Ai)))
 *
 * j番目のゲームの流れ
 * 1. あなたは整数 x (B_j <= x <= sum(Ai)) を決める
 * 2. ディーラーはティーバッグを x 個選び，あなたに渡す
 * 3. あなたは渡された中から Bj 個をすべて同じフレーバーになるように選ぶ
 * 4. すべて同じフレーバーならばゲームに勝ち，そうでなければ負け
 *
 * @brief クエリに対して，ゲームに勝つために必要な最小の x を出力する．
 *        すなわち，1 + sum_i( min(Bj - 1, Ai) ) を出力する．
 *        ただし，max(Ai) < Bj のときは -1 を出力する．
 *
 * @note sum_i( min(Bj - 1, Ai) ) = sum_{i: Ai < Bj}(Ai) + sum_{i: Ai >= Bj}(Bj
 * - 1)
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	uint64_t N, Q;
	cin >> N >> Q;
	vector<uint64_t> A(N);
	for (auto &Ai : A) cin >> Ai;
	vector<uint64_t> B(Q);
	for (auto &Bj : B) cin >> Bj;

	// O(N log N)
	ranges::sort(A);
	const uint maxA = A.back();

	// partial_sum_of_A[i] = sum_{k=0}^{i-1} A[k]
	vector<uint64_t> partial_sum_of_A(N + 1, 0);
	partial_sum(A.begin(), A.end(), next(partial_sum_of_A.begin()));

	// O(Q log N)
	for (const auto &Bj : B) {
		if (maxA < Bj) {
			cout << "-1\n";
			continue;
		}

		// A[i] >= Bj となる最小の i を求める
		const auto i = distance(A.begin(), ranges::lower_bound(A, Bj));

		// A[k] < Bj となる最大の k: i-1
		auto ans = 1ull + partial_sum_of_A[i] + (N - i) * (Bj - 1ull);

		cout << ans << '\n';
	}

	return 0;
}
