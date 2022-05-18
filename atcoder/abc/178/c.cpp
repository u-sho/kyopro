#include <iostream>
using namespace std;

const int mod = 1'000'000'007;  //'

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

    ModInt pow(int64_t pown) const {
        int64_t n = pown;
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
        a = ModInt(t);
        return (is);
    }

    static int get_mod() { return mod; }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // inputs
    int64_t N;  // n <= 1e6
    cin >> N;

    // solve
    // 10^N - 8 ^N
    ModInt ten = 10, nine = 9, eight = 8;
    ten        = ten.pow(N);
    nine       = nine.pow(N);
    eight      = eight.pow(N);
    ModInt ans = ten - nine - nine + eight;

    // output
    cout << ans << "\n";

    return 0;
}
