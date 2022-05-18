#include <algorithm>
#include <iostream>
int main() {
    int A, D;
    std::cin >> A >> D;
    std::cout << (std::min(A, D) + 1) * (std::max(A, D)) << '\n';
    return 0;
}