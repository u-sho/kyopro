#include <iostream>
#include <numeric>
#include <vector>

int main(void) {
    int N, L;
    std::cin >> N >> L;

    std::vector<int> taste(N);
    for (int i = 0; i < N; ++i) {
        taste.at(i) = L + i;
    }

    int sum = std::accumulate(taste.begin(), taste.end(), 0);

    int min_abs_taste = 1000000000;
    for (int i = 0; i < N; ++i) {
        if (abs(taste.at(i)) < abs(min_abs_taste)) min_abs_taste = taste.at(i);
    }

    std::cout << sum - min_abs_taste << '\n';
    return 0;
}