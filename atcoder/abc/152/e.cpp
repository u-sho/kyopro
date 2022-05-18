#include <cmath>
#include <climits> /* LLONG_MAX */

#include <string>
#include <vector>
#include <numeric> /* gcd, lcm, partial_sum, reduce*/
#include <iomanip> /* setprecision */
#include <iostream>
#include <algorithm>

using ll = long long; // c++11

// https://github.com/ei1333/library/blob/master/math/combinatorics/arbitrary-mod-int.cpp
struct ModInt {

    int x;

    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % get_mod() : (get_mod() - (-y) % get_mod()) % get_mod()) {}

    static int &get_mod() {
        static int mod = 1e9+7;
        return mod;
    }

    static void set_mod(int md) {
        get_mod() = md;
    }

    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= get_mod()) x -= get_mod();
        return *this;
    }

    ModInt &operator-=(const ModInt &p) {
        if((x += get_mod() - p.x) >= get_mod()) x -= get_mod();
        return *this;
    }

    ModInt &operator*=(const ModInt &p) {
        unsigned long long a = (unsigned long long) x * p.x;
        unsigned xh = (unsigned) (a >> 32), xl = (unsigned) a, d, m;
        asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (get_mod()));
        x = m;
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
        int a = x, b = get_mod(), u = 1, v = 0, t;
        while(b > 0) {
        t = a / b;
        std::swap(a -= t * b, b);
        std::swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while(n > 0) {
        if(n & 1) ret *= mul;
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
};

int main() {
    using namespace std;
    int n;
    vector<ModInt> A;
    cin >> n;
    for (int i = 0; i<n; i++){
        int _a;
        cin >> _a;
        A.push_back(_a);
    }
    for (int i = 1; i < n; i++) {
  
    }
    return 0;
}
