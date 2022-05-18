#include <iostream>
using lli         = long long;
constexpr lli mod = 1'000'000'007;  //'

long long comb(long long n, long long r) {
    //--------Valid Error------------------
    if (n < 0 || r < 0) return 0LL;
    if (n == 0) return 0LL;
    if (n < r) return 0LL;
    //-------------------------------------

    r = std::min(r, n - r);
    if (r == 0LL) return 1LL;
    if (r == 1LL) return n;

    int inverse[500005];
    for (lli i = 1LL; i <= r; ++i) {
        lli a = i, b = mod, u = 1LL, v = 0LL, t;
        while (b > 0) {
            t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        inverse[i] = (u >= 0 ? u % mod : (mod - (-u) % mod));
    }

    long long retVal = 1LL;
    for (long long i = 0LL; i < r; i++) {
        retVal *= (n - i);  // retVal = n! / (n-r)!
        retVal %= mod;
        retVal *= inverse[i + 1];  // retVal /= r!
        retVal %= mod;
    }
    return retVal;
}

int main(void) {
    lli x, y;
    std::cin >> x >> y;

    lli k = 2LL * x - y;
    if (k % 3LL) {
        std::cout << "0\n";
        return 0;
    }
    k /= 3LL;

    lli t = 2LL * y - x;
    if (t % 3LL) {
        std::cout << "0\n";
        return 0;
    }
    t /= 3LL;

    long long ans = comb(k + t, k);
    std::cout << ans << std::endl;

    return 0;
}