// 参考：https://bondo.hateblo.jp/entry/2023/04/16/122341

#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (unsigned i = 0U; i < (n); i++)
#define REP1(i, n) for (unsigned i = 1U; i <= (n); i++)

constexpr int mod = 998244353;

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

    // N: ゴール地点 2≤N≤100,
    // A: 高橋君の初期位置, B: 青木君の初期位置, 1≤A,B<N
    // P: 高橋君のサイコロの面数, Q: 青木君のサイコロの面数, 1≤P,Q≤10 (i.i.d.)
    unsigned N, A, B, P, Q;
    cin >> N >> A >> B >> P >> Q;

    // dp_t[t][i]: t回サイコロをふったとき高橋君が地点iにいる確率(mod 998244353)
    vector<vector<ModInt>> dp_t(N + 1, vector<ModInt>(N + 1, ModInt(0)));
    dp_t[0][A] = ModInt(1);
    REP(t, N)  // t: 高橋君がサイコロを振った回数 t<N (∵1≤A)
    REP(i, N)  // i: 丁度 t 回振ったときの地点 i<N (i=N でゲーム終了)
    REP1(p, P)  // p: t+1 回目のサイコロの出目 1≤p≤P
    dp_t[t + 1][min(i + p, N)] += dp_t[t][i] / ModInt(P);

    // dp_a[t][i]: t回サイコロをふったとき青木君が地点iにいる確率(mod 998244353)
    vector<vector<ModInt>> dp_a(N + 1, vector<ModInt>(N + 1, ModInt(0)));
    dp_a[0][B] = ModInt(1);
    REP(t, N) REP(i, N) {
        REP1(q, Q) dp_a[t + 1][min(i + q, N)] += dp_a[t][i] / ModInt(Q);
    }

    // pr_win_t: 高橋君が勝つ確率
    ModInt pr_win_t = ModInt(0);
    REP1(t, N) {  // t: 高橋君がサイコロを振った回数

        // pr_not_win_a: 青木君が t-1 回サイコロを振って勝っていない確率
        ModInt pr_not_win_a    = ModInt(0);
        REP(i, N) pr_not_win_a += dp_a[t - 1][i];

        pr_win_t += pr_not_win_a * dp_t[t][N];
    }

    cout << pr_win_t << "\n";

    return 0;
}
