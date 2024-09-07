#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

#define SORT(v)  std::ranges::sort(v)
#define ALL(v)   (v).begin(), (v).end()
#define LP(v, c) lower_bound(ALL(v), (c))
#define UP(v, c) upper_bound(ALL(v), (c))
#define BS(v, c) binary_search(ALL(v), (c))

#define REP(i, n)  for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;     // N <= 2e5
    int64_t K;  // 1e-15 <= K <= 1e15
    cin >> N >> K;
    vector<int64_t> A(N);
    for (int64_t &Ai : A) cin >> Ai;  // 1e-9 <= Ai <= 1e9

    // 1. 尺取り法で総和がKであるようなAの連続部分列A[i,j)をすべてkaに格納する
    // 2. ka[i]について，

    uint left = 0, right = 1;
    int64_t p_sum = A[0];
    while () {
        if (p_sum == K) }
    for (; left < N; left++) {
        for (uint i = right; i < N; i++) {
            p_sum += A[i];
        }
        if ()

            for (;;) {
                if (p_sum ==) }
    }

    return 0;
}
