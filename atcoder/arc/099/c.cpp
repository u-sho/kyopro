#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> A(N);
    for (int &Ai : A) std::cin >> Ai;

    int ans        = 1000000000;
    auto one_is_at = std::lower_bound(A.begin(), A.end(), 1);
    int it         = one_is_at - A.begin();
    for (int i = it - K + 1; i < it + K; ++i) {  // i: 区間の最初のiterator
        if (i < 0) continue;
        if (i >= N) break;
        int kl = i / (K - 1);
        if (i % (K - 1)) kl++;
        int kr = (N - i - 1) / (K - 1);
        if ((N - i - 1) % (K - 1)) kr++;
        ans = std::min(ans, kl + kr);
    }

    std::cout << ans << '\n';
    return 0;
}