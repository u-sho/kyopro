#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244'353;

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

    [[nodiscard]] ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    template <typename T>
    [[nodiscard]] ModInt pow(T n) const {
        if (n < 0) assert(false);
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n   >>= 1;
        }
        return ret;
    }

    friend std::ostream &operator<<(std::ostream &os, const ModInt &p) {
        return os << p.x;
    }
    friend std::istream &operator>>(std::istream &is, ModInt &a) {
        long long t;
        is >> t;
        a = ModInt(t);
        return is;
    }

    [[maybe_unused]] [[nodiscard]] static int get_mod() { return mod; }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned Q;
    cin >> Q;

    deque<char> S;
    S.push_back('1');
    ModInt s = 1;
    while (Q--) {
        unsigned query_kind;
        cin >> query_kind;
        if (query_kind == 1) {
            char x;
            cin >> x;
            S.push_back(x);
            s = (ModInt(10) * s + ModInt(x - '0'));
            // cout << s << '\n';
        }
        if (query_kind == 2) {
            char S0 = S.front();
            S.pop_front();
            s -= ModInt(S0 - '0') * ModInt(10).pow(S.size());
            // cout << s << '\n';
        }
        if (query_kind == 3) {
            cout << s << '\n';
        }
    }

    return 0;
}
