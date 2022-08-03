#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    using std::cin;
    using std::cout;
    using std::vector;

    long long N;
    cin >> N;
    vector<long long> a(N);
    for (long long &ai : a) cin >> ai;

    std::sort(a.begin(), a.end());
    vector<bool> unique(N);
    std::fill(unique.begin(), unique.end(), true);
    for (long long i = 0; i < N; ++i) {
        if (!unique.at(i)) continue;

        for (long long j = 2; a.at(i) * j <= a.at(N - 1); j <<= 1) {
            auto it = std::lower_bound(a.begin(), a.end(), a.at(i) * j);
            if (it == a.end()) break;
            if (*it != a.at(i) * j) continue;
            unique.at(it - a.begin()) = false;
        }
    }

    int ans = 0;
    for (const bool u : unique)
        if (u) ans++;

    cout << ans << '\n';
    return 0;
}