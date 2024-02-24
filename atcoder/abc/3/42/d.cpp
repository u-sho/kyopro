#include <bits/stdc++.h>
using namespace std;

// 参考：https://qiita.com/drken/items/a14e9af0ca2d857dad23#4-素因数分解
using PrimeFactors = std::vector<uint64_t>;
PrimeFactors prime_factorize(uint64_t N) {
    PrimeFactors res;
    if (N == 0ULL) return res;

    for (uint64_t p = 2ULL; p * p <= N; ++p) {
        if (N % p) continue;  // 素因数判定

        unsigned ex = 0U;  // 指数
        while (N % p == 0ULL) {
            ++ex;
            N /= p;
        }

        if (ex % 2U) {  // 素因数 p が奇数個含まれる場合のみ（問題固有処理）
            res.push_back(p);  // pow(p, ex)
        }
    }
    if (N > 1ULL) res.push_back(N);  // 素因数判定 (N==0となることはない)

    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;  // <= 2e5
    cin >> N;
    vector<PrimeFactors> A_prime(N);
    for (auto& A_prime_i : A_prime) {
        uint Ai;
        cin >> Ai;
        A_prime_i = prime_factorize(Ai);
    }
    cout << "input" << endl;

    uint64_t ans = 0ULL;
    ranges::sort(A_prime, [](auto const& x, auto const& y) {
        if (x.size() == y.size()) return x < y;
        else return x.size() < y.size();
    });

    cout << "sorted" << endl;


    for (auto it_begin = A_prime.begin(); it_begin != A_prime.end(); ) {
        PrimeFactors _p(A_prime[0].size());
        auto it_end = upper_bound(it_begin, A_prime.end(), _p, [](const auto& x, const auto&y){return x.size() < y.size();});
        if ((*it_begin).size() == 0) { // Ai==0
            for (uint i=1U; i <= distance(it_begin,it_end); i++) ans += N-i;
            continue;
        }

        for (auto same_it_begin = it_begin; same_it_begin != it_end;){
            auto same_it_end = upper_bound(same_it_begin, it_end, *same_it_begin);
            ans += distance(same_it_begin, same_it_end);
            same_it_begin = same_it_end;
        }
        it_begin = it_end;
    }

    cout << ans << '\n';

    return 0;
}
