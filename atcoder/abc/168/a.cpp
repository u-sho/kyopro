#include <iostream>
int main() {
    int n;
    std::cin >> n;
    if (n % 10 == 3) {
        std::cout << "bon\n";
        return 0;
    }
    if (n % 10 == 0 || n % 10 == 1 || n % 10 == 6 || n % 10 == 8) {
        std::cout << "pon\n";
        return 0;
    }
    std::cout << "hon\n";
    return 0;
}