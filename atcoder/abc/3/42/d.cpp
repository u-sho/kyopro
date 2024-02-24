#include <bits/stdc++.h>
using namespace std;

/** 参考：https://qiita.com/drken/items/a14e9af0ca2d857dad23#4-素因数分解
 * 𝑶(√N log(N)) */
[[nodiscard]] uint64_t prime_factorize(uint64_t N) {
    if (N == 0ULL) return 0ULL;

    uint64_t res=1ULL;

    for (uint64_t p = 2ULL; p * p <= N; ++p) {
        if (N % p) continue;  // 素因数判定

        unsigned ex = 0U;  // 指数
        while (N % p == 0ULL) {
            ++ex;
            N /= p;
        }

        if (ex % 2U) {  // 素因数 p が奇数個含まれる場合のみ（問題固有処理）
            res *= p;  // pow(p, ex)
        }
    }
    if (N > 1ULL) res *= N;  // 素因数判定 (N==0となることはない)

    return res;
}


/* 𝑶(min(r,n-r) log(MOD)) */
[[nodiscard]] uint64_t comb(uint64_t n, uint64_t r) {
    //--------Valid Error------------------
    if (n == 0) return 0ULL;
    if (n < r) return 0ULL;
    //-------------------------------------

    r = std::min(r, n - r);
    if (r == 0ULL) return 1ULL;
    if (r == 1ULL) return n;

    uint64_t retVal = 1ULL;
    for (uint64_t i = 0ULL; i < r; ++i) {
        retVal *= (n - i);  // retVal = n! / (n-r)!
        retVal /= i + 1ULL;  // retVal /= r!
    }
    return retVal;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;  // <= 2e5
    cin >> N;
    vector<uint64_t> A_prime(N);
    for (auto& A_prime_i : A_prime) {
        uint64_t Ai;
        cin >> Ai;
        A_prime_i = prime_factorize(Ai);
    }
    ranges::sort(A_prime);

    uint64_t ans = 0ULL;
    auto it = ranges::upper_bound(A_prime, 0ULL);
    if (it != A_prime.begin()){
        for (uint i=1U; A_prime[i-1]==0ULL && i<=N; i++){
            ans += N-i;
        }
    }

    map<uint64_t, uint> same_counter;
    for(auto i = it; i!= A_prime.end(); i++){
        same_counter[*i]++;
    }
    for (const auto&[_, same_count]: same_counter){
        ans += comb(same_count, 2ULL);
    }

    cout << ans << '\n';

    return 0;
}
