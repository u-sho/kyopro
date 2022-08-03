#include <bits/stdc++.h>
using namespace std;
using lli = long long;

using PrimeFact     = std::pair<long long, int>;
using PrimeFactores = std::vector<PrimeFact>;

PrimeFactores prime_factorize(long long a, long long b) {
    PrimeFactores res;

    for (long long p = 2LL; p * p <= max(a, b); ++p) {
        if (a % p || b % p) continue;  // 素因数判定

        int ex = 0;  // 指数
        while (a % p == 0LL && b % p == 0LL) {
            ++ex;
            a /= p;
            b /= p;
        }

        res.push_back({p, ex});  // pow(p, ex)
    }

    return res;
}

int main() {
    lli A, B;
    cin >> A >> B;

    cout << prime_factorize(A, B).size() + 1uL << '\n';

    return 0;
}
