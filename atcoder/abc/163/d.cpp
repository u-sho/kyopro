#include <bits/stdc++.h>
constexpr int MOD = 1'000'000'007;

// https://github.com/ei1333/library/blob/master/math/combinatorics/arbitrary-mod-int.cpp
template <int mod>
struct ModInt {
    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }

    bool operator!=(const ModInt &p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
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

    friend std::istream &operator>>(std::istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using modint = ModInt<MOD>;

    int n, k;
    cin >> n >> k;

    modint ans = 0, N = n, t = 2, o = 1;
    modint sumn2 = (N + o) * (N + t) / t;
    for (int i = k; i <= n + 1; ++i) {
        modint ki     = i;
        modint sumnnk = (N - ki + o) * (N - ki + t) / t;
        modint sumk   = ki * (ki + o) / t;
        ans += sumn2 - sumnnk - sumk + o;
    }
    cout << ans << endl;
    return 0;
}