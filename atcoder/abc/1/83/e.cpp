#include <bits/stdc++.h>
#define Wall '#'
using namespace std;
using Grid        = vector<string>;
constexpr int mod = 1000'000'007;

// https://github.com/ei1333/library/blob/master/math/combinatorics/arbitrary-mod-int.cpp
// 少し変えてる
struct Mint {
    int x;
    Mint() : x(0) {}
    Mint(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    Mint &operator+=(const Mint &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }
    Mint &operator-=(const Mint &p) {
        if ((x -= p.x) < 0) x += mod;
        return *this;
    }
    Mint &operator*=(const Mint &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }
    Mint &operator/=(const Mint &p) {
        *this *= p.inverse();
        return *this;
    }

    Mint operator-() const { return Mint(-x); }
    Mint operator+(const Mint &p) const { return Mint(*this) += p; }
    Mint operator-(const Mint &p) const { return Mint(*this) -= p; }
    Mint operator*(const Mint &p) const { return Mint(*this) *= p; }
    Mint operator/(const Mint &p) const { return Mint(*this) /= p; }

    bool operator==(const Mint &p) const { return x == p.x; }
    bool operator!=(const Mint &p) const { return x != p.x; }

    Mint inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return Mint(u);
    }

    friend std::ostream &operator<<(std::ostream &os, const Mint &p) {
        return os << p.x;
    }
    friend std::istream &operator>>(std::istream &is, Mint &a) {
        long long t;
        is >> t;
        a = Mint(t);
        return is;
    }
};

Mint dp[2003][2003];  // dp[i][j] := マス(i,j)まで移動する方法の通り数
Mint x[2'003][2'003];  // x[i][j] := マス(i,j)に 左 から移動してくる方法の通り数
Mint y[2'003][2'003];  // y[i][j] := マス(i,j)に 上 から移動してくる方法の通り数
Mint xy[2003][2003];  // xy[i][j] := マス(i,j)に左上から移動してくる方法の通り数

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    Grid S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    dp[0][0] = x[0][0] = y[0][0] = xy[0][0] = Mint(1);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 && j == 0) continue;
            if (S[i][j] == Wall) continue;

            if (j) x[i][j] = x[i][j - 1];
            if (i) y[i][j] = y[i - 1][j];
            if (i && j) xy[i][j] = xy[i - 1][j - 1];

            dp[i][j] += x[i][j] + y[i][j] + xy[i][j];

            x[i][j] += dp[i][j];
            y[i][j] += dp[i][j];
            xy[i][j] += dp[i][j];
        }
    }

    cout << dp[H - 1][W - 1] << "\n";

    return 0;
}
