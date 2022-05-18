#include <iostream>
#include <numeric>
#include <vector>

std::vector<long long> pow4;

int main() {
    for (long long i = 0; i < 1000; ++i) {
        pow4.push_back(i * i * i * i);
    }

    int x;
    std::cin >> x;

    auto it = std::lower_bound(pow4.begin(), pow4.end(), x);
    int N   = it - pow4.begin();

    std::cout << N << '\n';

    return 0;
}