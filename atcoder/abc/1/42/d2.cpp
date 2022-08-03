#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli calc_prime_factor(lli N) {
    lli res = 1LL;

    for (lli p = 2LL; p * p <= N; ++p) {
        if (N % p) continue;  // 素因数判定

        res++;

        // 割り切る
        while (N % p == 0LL) {
            N /= p;
        }
    }

    if (N > 1LL) res++;

    return res;
}

int main() {
    lli a, b;
    cin >> a >> b;

    cout << calc_prime_factor(__gcd(a, b)) << '\n';

    return 0;
}
