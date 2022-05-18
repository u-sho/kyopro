#include <bits/stdc++.h>
using namespace std;

// https://qiita.com/drken/items/a14e9af0ca2d857dad23#4-%E7%B4%A0%E5%9B%A0%E6%95%B0%E5%88%86%E8%A7%A3
using PrimeFact     = std::pair<int, int>;
using PrimeFactores = std::vector<PrimeFact>;
PrimeFactores prime_factorize(int N) {
    PrimeFactores res;
    for (int p = 2LL; p * p <= N; ++p) {
        if (N % p) continue;  // 素因数判定
        int ex = 0;           // 指数
        while (N % p == 0LL) {
            ++ex;
            N /= p;
        }
        res.push_back({p, ex});  // pow(p, ex)
    }
    if (N > 1LL) res.push_back({N, 1});  // 素因数判定 (N==0となることはない)
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int K;
    cin >> K;

    unsigned long long ans = 1ULL;
    for (int i = 2; i <= K; i++) {
        const PrimeFactores& i_prime_factores = prime_factorize(i);
        unsigned long long cnt                = 1ULL;
        for (const PrimeFact& p : i_prime_factores) {
            cnt *= (p.second + 2ULL) * (p.second + 1ULL) / 2ULL;
        }
        ans += cnt;
    }

    cout << ans << "\n";
    return 0;
}
