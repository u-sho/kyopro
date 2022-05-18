#include <cassert>
#include <iostream>
constexpr long long MOD = 1'000'000'007;  //'

long long inv[2003];
long long inverse(int x) {
    long long a = x, b = MOD, u = 1LL, v = 0LL, t;
    while (b > 0) {
        t = a / b;
        std::swap(a -= t * b, b);
        std::swap(u -= t * v, v);
    }
    return u % MOD;
}
void initInv() {
    for (int i = 0; i < 2003; ++i) {
        inv[i] = inverse(i);
    }
}

long long n, k;
long long comb(long long t, long long r) {
    //--------Valid Error------------------
    if (t < 0LL || r < 0LL) assert(false);
    // if(t<r) assert(false);
    if (t < r) return 0LL;
    //-------------------------------------

    r = std::min(r, t - r);
    if (r == 0LL) return 1LL;
    if (r == 1LL) return t;

    long long retVal = 1LL;
    for (long long i = 0LL; i < r; ++i) {
        retVal *= t - i;  // retVal *= t, t-1, t-2, ... , t-r+1
        retVal += MOD;
        retVal *= inv[i + 1LL];  // retVal /= 1, 2, 3, ... , r
        retVal %= MOD;
    }
    return retVal;
}

int main() {
    initInv();
    std::cin >> n >> k;
    for (long long i = 1; i <= k; ++i) {
        std::cout << ((comb(k - 1, i - 1) * comb(n - k + 1, i)) % MOD)
                  << std::endl;
    }
    return 0;
}