#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(5);
    //-----------------------------------------------
    int n;
    std::cin >> n;
    std::vector<int> buka(n + 1);
    std::fill(buka.begin(), buka.end(), 0);
    for (int i = 2; i <= n; ++i) {
        int a;  // joushiNum
        std::cin >> a;
        buka.at(a) += 1;
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << buka.at(i) << std::endl;
    }

    return 0;
}