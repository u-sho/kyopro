#include <bits/stdc++.h>
using namespace std;
using lli = long long;

constexpr int mod = 998'244'353;

// https://github.com/ei1333/library/blob/master/math/combinatorics/arbitrary-mod-int.cpp
// 少し変えてる
struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p) {
        if ((x -= p.x) < 0) x += mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    template <typename T>
    [[nodiscard]] ModInt pow(T n) const {
        if (n < 0) assert(false);
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend std::ostream &operator<<(std::ostream &os, const ModInt &p) {
        return os << p.x;
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned N, M, K;
    cin >> N >> M >> K;

    if (N == 1 || M == 1) {
        cout << ModInt(K).pow(max(N, M)) << "\n";
        return 0;
    }

    ModInt ans = 0;
    for (unsigned i = 1U; i <= K; i++) {
        ans += ModInt(i).pow(N) *
               (ModInt(K - i + 1).pow(M) - ModInt(K - i).pow(M));
    }

    cout << ans << "\n";

    return 0;
}
