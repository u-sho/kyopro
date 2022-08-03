#include <bits/stdc++.h>
using namespace std;
using lli  = long long;
using ulli = unsigned long long;

int main() {
    int N;
    cin >> N;
    vector<ulli> T(N);
    for (ulli &Ti : T) cin >> Ti;

    ulli lcd_low       = 1uLL;
    ulli lcd_upp       = 0uLL;
    constexpr ulli sep = 9'000'000'000'000'000'000uLL;
    for (const ulli Ti : T) {
        lcd_low /= __gcd(lcd_low, Ti);
        if (log10(lcd_low) + log10(Ti) >= log10(sep)) {
        }
        lcd_low *= Ti;
    }

    return 0;
}
