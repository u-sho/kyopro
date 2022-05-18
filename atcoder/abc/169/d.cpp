#include <cmath>
#include <iostream>
#include <vector>
using std::pair;
using std::vector;
using Prime_Power = pair<long long, long long>;
using PPvec       = vector<Prime_Power>;

PPvec prime_factorize(long long N) {
    PPvec res;
    for (long long a = 2LL; a * a <= N; ++a) {
        if (N % a != 0LL) continue;
        long long ex = 0LL;  // 指数

        // 割れる限り割り続ける
        while (N % a == 0LL) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});

    return res;
}

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    long long n;
    cin >> n;
    if (n == 1LL) {
        cout << "0\n";
        return 0;
    }
    if (n == 2LL) {
        cout << "1\n";
        return 0;
    }

    const PPvec &res = prime_factorize(n);
    long long ans    = 0LL;
    for (const Prime_Power &p : res) {
        // p.second >= z(z+1)/2
        long long z = -0.5L + sqrt(0.25 + (2 * p.second));
        ans += z;
    }
    cout << ans << endl;

    return 0;
}