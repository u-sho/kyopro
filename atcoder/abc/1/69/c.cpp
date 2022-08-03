#include <iostream>
constexpr long long m   = 1'000'000'000LL;  //' 1e9
constexpr long double e = 0.001000000000L;  // error
constexpr long long h   = 100LL;

int main(void) {
    long long a, bh;
    long double b;
    std::cin >> a >> b;
    bh = (b + e) * h;  // b * 100

    if (a == 0LL || bh == 0LL) {
        std::cout << "0\n";
        return 0;
    }

    long long ua, ba;
    ua = a / m;  // a / 1e9
    ba = a % m;  // a % 1e9
    if (ua == 0LL) {
        std::cout << a * bh / h << std::endl;
        return 0;
    }

    // a * (b * 100)
    ua *= bh;
    ba *= bh;
    ba += (ua % h) * m;

    // (a * (b * 100)) / 100
    ua /= h;
    ba /= h;
    ua += ba / m;
    ba %= m;

    if (ua == 0LL) {
        std::cout << ba << std::endl;
    } else {
        printf("%lld%09lld\n", ua, ba);
    }

    return 0;
}