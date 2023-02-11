#include <algorithm>
#include <iostream>
#include <string>

int main(void) {
    using namespace std;

    uint64_t N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    uint64_t min_cost = UINT64_MAX;

    S += S;                              // S の index を循環させる
    for (unsigned i = 0U; i < N; i++) {  // S[0,N) <- S[1,N] に更新していく
        uint64_t cost_of_A = A * ((uint64_t)i);  // ↑の更新コスト(1回A円)
        uint64_t cost_of_B = 0ULL;  // ↓回文でないとき、Bのみで回文とするコスト
        for (unsigned j = 0U; j < N / 2U; j++) {  // S が回文か判定していく
            if (S.at(i + j) != S.at(i + N - 1U - j)) cost_of_B += B;
        }

        min_cost = min(min_cost, cost_of_A + cost_of_B);
    }

    cout << min_cost << '\n';
    return 0;
}