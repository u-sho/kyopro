#include <cmath>
#include <iostream>
#include <vector>

using PrimeFact     = std::pair<long long, int>;
using PrimeFactores = std::vector<PrimeFact>;

PrimeFactores prime_factorize(long long N) {
    PrimeFactores res;

    for (long long p = 2LL; p * p <= N; ++p) {
        if (N % p) continue;  // 素因数判定

        int ex = 0;  // 指数
        while (N % p == 0LL) {
            ++ex;
            N /= p;
        }

        res.push_back({p, ex});  // pow(p, ex)
    }
    if (N > 1LL) res.push_back({N, 1});  // 素因数判定 (N==0となることはない)

    return res;
}

template <typename T, typename U>
T llPow(const T p, const U e) {
    if (e == 0) return 1;
    if (e % 2) return p * llPow(p, e - 1);

    T p_pow_half_e = llPow(p, e / 2);
    return p_pow_half_e * p_pow_half_e;
}

int main() {
    long long N;
    std::cin >> N;

    // 完全数 : メルセンヌ素数 M(p) = 2^p - 1 に対して 2^(p-1) * M(p)
    const long long pn[6] = {6LL,    28LL,       496LL,
                             8128LL, 33550336LL, 8589869056LL};
    for (std::size_t i = 0uL; i < 6uL; ++i) {
        if (pn[i] == N) {
            std::cout << "Perfect\n";
            return 0;
        }
    }

    PrimeFactores pf       = prime_factorize(N);
    long long factores_sum = 1LL;
    for (const PrimeFact pn : pf) {
        long long pf_sum = 0LL;
        for (int i = 0; i <= pn.second; ++i) {
            pf_sum += llPow(pn.first, i);
        }
        factores_sum *= pf_sum;
    }

    // std::cout << factores_sum << std::endl;
    if (factores_sum < 2 * N) {
        std::cout << "Deficient\n";
        return 0;
    }
    std::cout << "Abundant\n";
    return 0;
}