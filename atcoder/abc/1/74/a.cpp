#include <iostream>
int main() {
    int x;
    std::cin >> x;
    if (x >= 30) {
        std::cout << "Yes\n";
        return 0;
    }
    std::cout << "No\n";
    return 0;
}