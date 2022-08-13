#include <bits/stdc++.h>
using namespace std;
using lli = unsigned long long;

int sum_of_difits(lli n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        lli n_i;
        int s;
        cin >> n_i >> s;

        if (s >= sum_of_difits(n_i)) {
            cout << "0\n";
            continue;
        }

        // 1の位から切り上げていく
        lli n         = n_i;
        lli ten_pow_i = 10ULL;
        for (int i = 1; i <= 19; i++) {
            n /= ten_pow_i;
            ++n;
            n *= ten_pow_i;

            if (s >= sum_of_difits(n)) break;
            ten_pow_i *= 10ULL;
        }

        cout << n - n_i << "\n";
    }

    return 0;
}