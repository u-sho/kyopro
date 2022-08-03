#include <cmath>
#include <iostream>
#include <vector>
int main() {
    int n;
    std::cin >> n;

    long long ans = 1UL;
    bool hasZero  = false;
    std::vector<long double> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a.at(i);
        if (a.at(i) == 0) hasZero = true;
    }
    if (hasZero) {
        std::cout << "0\n";
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (std::log10(a.at(i)) + std::log10((long double)ans) > 18.0000001) {
            std::cout << "-1\n";
            return 0;
        }
        ans *= (long long)a.at(i);
        if (ans > 1'000'000'000'000'000'000) {
            std::cout << "-1\n";
            return 0;
        }
    }
    std::cout << ans << '\n';
    return 0;
}