#include <iostream>
int main() {
    uint N, X, Y, Z;
    std::cin >> N >> X >> Y >> Z;
    if ((X < Z && Z < Y) || (Y < Z && Z < X)) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
    return 0;
}