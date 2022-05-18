#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1'000'000'007;  // '

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
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }
    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

ModInt combination(int n, int r) {
    if (n<r) return ModInt(0);
    r = min(r, n-r);
    ModInt comb = 1;
    for (int i = 0; i < r; i++) {
        comb = ModInt((long long)comb.x * (long long)(n-i) / (i+1LL));
    }
    return comb;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // inputs
    int S;
    cin >> S;

    // solve
    /**
     * T := { t_i | t_i ≧ 3, Σt_i = S }
     * T としてありうる数列の総数を求める
     */
    ModInt ans = 0; // T としてありうる数列の総数
    const int max_len = S / 3; // max |T|

    for (int i=1; i <= max_len; i++) {
        // |T| = i であるような数列の総数
        ModInt ti = combination(S-2*i-1, i-1);
        ans += ti;
    }

    // output
    cout << ans << "\n";

    return 0;
}
