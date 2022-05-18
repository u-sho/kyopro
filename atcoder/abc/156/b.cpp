#include <iostream>
int main(void) {
    int N, K;
    std::cin >> N >> K;

    int ans = 0;
    for (long k = K; N / k > 0 || N % k > 0; ++ans) {
        N /= k;
    }

    std::cout << ans << '\n';
    return 0;
}
