#include <iomanip>
#include <iostream>
int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    // fixed で指数表示ではなく小数点表示
    // setprecision で精度を指定
    std::cout << std::fixed << std::setprecision(5);
    double r;
    std::cin >> r;
    std::cout << r * 6.28318530717958623200 << std::endl;
    return 0;
}