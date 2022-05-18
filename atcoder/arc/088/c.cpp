#include <iostream>
int main() {
    long long X, Y;
    std::cin >> X >> Y;
    long long ans = 1LL;
    for (; (X * 2) <= Y; ++ans) X *= 2;
    std::cout << ans << '\n';
    return 0;
}