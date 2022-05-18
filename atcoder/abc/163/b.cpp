#include <iomanip>
#include <iostream>
#include <vector>
int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(5);
    //-----------------------------------------------
    int n, m;
    std::cin >> n >> m;
    int kadaiDay = 0;
    for (int i = 0; i < m; ++i) {
        int a;
        std::cin >> a;
        kadaiDay += a;
    }

    if (kadaiDay > n) {
        std::cout << "-1\n";
    } else {
        std::cout << n - kadaiDay << std::endl;
    }
    return 0;
}